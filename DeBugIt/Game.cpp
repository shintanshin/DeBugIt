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

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Key::Escape)
                    window.close();
                break;
            case sf::Event::MouseButtonPressed:
                buildPlace.handleEvent(event, window, towerSelection);
                break;
            }

        }
        float deltaTime = clock.restart().asSeconds();
       //bee.update(deltaTime * 5);

        //bug.update(deltaTime *5);
        wave.update(deltaTime * 5);

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
