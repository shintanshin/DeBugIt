#include "Game.h"
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include "Monster.h"
#include "Base.h"
#include "Wave.h"
#include "BuildPlace.h"
#include "Tower.h"
#include "Menu.h"





void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DeBugIt");
    window.setKeyRepeatEnabled(false);

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("Textures/MapTexture.png");
    sf::Sprite LvlTexture(backgroundTexture);

    TowerMenu towerMenu;
    
    PotatoTower potatoT;
    CornTower corn;

    Base base;
    base.setScale();

    BuildPlaces places;
   // BuildPlace(&places);
    FirstWave wave(6);

    sf::Clock clock;

    m_currentState = GameStateId::Playing;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;

        while (window.pollEvent(event))
        {
                switch (event.type)
                {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
                }
            
            switch (m_currentState) {
            case GameStateId::TitleScreen:
                break;
            case GameStateId::Playing:
                places.handleEvent(event, window, towerMenu);
                if (towerMenu.getDrawEnabled()) {
                    m_currentState = GameStateId::TowerMenu;
                }
                //if (potatoT.getDrawEnabled())//potatoT.getDrawEnabled();
                //{
                //    potatoT.setDrawEnabled(true);
                //}
                for (const auto& tower : places.getAllTowers()) {
                    //tower->update(deltaTime);
                    tower->setDrawEnabled(true);
                }
                break;
            case GameStateId::TowerMenu:
                towerMenu.handleEvent(event, window);
                if (!towerMenu.getDrawEnabled()) {
                    m_currentState = GameStateId::Playing;
                    towerMenu.buildSelectedTower(*places.getSelectedBuildPlace());
                    potatoT.setDrawEnabled(true);
                }
                if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape) {
                    towerMenu.setDrawEnabled(false);
                    m_currentState = GameStateId::Playing;
                }
                break;
            default:
                break;
            }
        }
        switch (m_currentState) {
        case GameStateId::TitleScreen:
            break;
        case GameStateId::Playing:
            for (const auto& tower : places.getAllTowers()) {
                tower->update(deltaTime);
                tower->draw(window);
            }
            //potatoT.draw(window);
            potatoT.update(deltaTime*2);
            wave.update(deltaTime * 5);
            
            break;
        case GameStateId::TowerMenu:
          
            break;
        default:
            break;
        }
        window.clear();
        window.draw(LvlTexture);
        base.draw(window);
        places.draw(window);
        towerMenu.draw(window);

        
        potatoT.draw(window);
        corn.draw(window);
       /* if (potatoT.getDrawEnabled()) {
            std::cout << "Drawing PotatoTower" << std::endl;
            potatoT.draw(window);
        }*/
        for (const auto& tower : places.getAllTowers()) {
            tower->update(deltaTime);
            tower->draw(window);
        }
        wave.draw(window);
        window.display();
    }
}
