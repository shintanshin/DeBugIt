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
#include "GameStateManager.h"
#include "GameState.h"
#include "GameWorld.h"




void Game::run()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DeBugIt");

    /*GameWorld gameWorld(&window);
    GameStateManager gameStateManager(&gameWorld, GameStateId::TowerMenu);*/

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("Textures/MapTexture.png");
    sf::Sprite LvlTexture(backgroundTexture);

    BuildPlace buildPlace;
    TowerMenu towerSelection;

    PotatoTower potatoT;
    potatoT.setScale();
    CornTower corn;


    Base base;
    base.setScale();
    BuildPlace place;


    Bee bee;
    PurpleBug bug;
    FirstWave wave(6);


    sf::Clock clock;

    m_currentState = GameStateId::Playing;

    while (window.isOpen())
    {
        float deltaTime = clock.restart().asSeconds();
        sf::Event event;
        while (window.pollEvent(event))
        {
            //switch (event.type)
            //{
            //case sf::Event::Closed:
            //    window.close();
            //    break;
            //case sf::Event::KeyPressed:
            //    if (event.key.code == sf::Keyboard::Key::Escape)
            //        window.close();
            //    break;
            //case sf::Event::MouseButtonPressed:
            //        buildPlace.handleEvent(event, window, towerSelection);
            //    //if (gameStateManager.getCurrentGameState() == &gameStatePlaying) {
            //    //    buildPlace.handleEvent(event, window, towerSelection);
            //    //}
            //    //else if (gameStateManager.getCurrentGameState() == &gameStateTowerMenu) {
            //    //    // Викликаємо методи для GameState_TowerMenu
            //    //    //gameStateTowerMenu.handleEvent(event, window);
            //    //    gameStateTowerMenu.updateState();
            //    //}
            //}
            
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
                buildPlace.handleEvent(event, window, towerSelection);
                break;

            case GameStateId::TowerMenu:
                // Обробка подій для стану вибору башти
                towerSelection.handleEvent(event, window);
                break;

                // Обробка інших станів гри...

            default:
                break;
            }
        }

        if (towerSelection.getDrawEnabled()) {
            m_currentState = GameStateId::TowerMenu;
        }
        //float deltaTime = clock.restart().asSeconds();
        switch (m_currentState) {
        case GameStateId::TitleScreen:
            // Відображення екрану заголовка
            break;

        case GameStateId::Playing:
            // Відображення стану гри "Playing"
            wave.update(deltaTime * 5);
            wave.draw(window);
            break;

        case GameStateId::TowerMenu:
            // Відображення меню вибору башти
            towerSelection.draw(window);
            break;

            // Відображення інших станів гри...

        default:
            break;
        }
       //bee.update(deltaTime * 5);

        //bug.update(deltaTime *5);
        //wave.update(deltaTime * 5);

        //potatoT.update(deltaTime);

       

        window.clear();
        window.draw(LvlTexture);
        base.draw(window);
        place.draw(window);
        towerSelection.draw(window);

        //corn.draw(window);

        wave.draw(window);
        window.display();
    }
}
