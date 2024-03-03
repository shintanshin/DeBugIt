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
    //TowerType type;
   
    PotatoTower potatoT;
    //potatoT.setScale();
    CornTower corn;

    Base base;
    base.setScale();
    BuildPlace place;
    BuildPlaces places;

    //Bee bee;
    //PurpleBug bug;
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
                // Викликайте ваш існуючий код для обробки подій BuildPlace
                //buildPlace.handleEvent(event, window, towerMenu);
                places.handleEvent(event, window, towerMenu);
                if (towerMenu.getDrawEnabled()) {
                    m_currentState = GameStateId::TowerMenu;
                }
              
                break;
            case GameStateId::TowerMenu:
                // Обробка подій для стану вибору башти
                towerMenu.handleEvent(event, window);
                if (!towerMenu.getDrawEnabled()) {
                    towerMenu.buildSelectedTower(place);
                    //buildPlace.buildTower(type);
                    m_currentState = GameStateId::Playing;
                    // Будуємо обрану башту
                }
                if (sf::Event::KeyPressed && event.key.code == sf::Keyboard::Key::Escape) {
               
                    towerMenu.setDrawEnabled(false);
                    m_currentState = GameStateId::Playing;
                }
                break;
                // Обробка інших станів гри...
            default:
                break;
            }
        }
        switch (m_currentState) {
        case GameStateId::TitleScreen:
            // Відображення екрану заголовка
            break;
        case GameStateId::Playing:
            //potatoT.draw(window);
        potatoT.update(deltaTime);
            // Відображення стану гри "Playing"
            wave.update(deltaTime * 5);
            
            break;
        case GameStateId::TowerMenu:
            // Відображення меню вибору башти
          
            break;
            // Відображення інших станів гри...
        default:
            break;
        }
        window.clear();
        window.draw(LvlTexture);
        base.draw(window);
        place.draw(window);
        places.draw(window);
        towerMenu.draw(window);
        //potatoT.draw(window);

        //corn.draw(window);

        wave.draw(window);
        window.display();
    }
}
