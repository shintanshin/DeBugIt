#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"
#include "GameState.h"
#include "GameWorld.h"
#include "GameStateManager.h"
#include "Monster.h"
#include "Base.h"
#include "Wave.h"
#include "BuildPlace.h"
#include "Tower.h"
#include "Menu.h"

void handleSystemEvents(sf::RenderWindow& window)
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
        default:
            break;
        }
    }
}


int main()
{
    Game game;
    game.run();

    //sf::RenderWindow window(sf::VideoMode(800, 600), "DeBugIt");

    //sf::Texture backgroundTexture;
    //backgroundTexture.loadFromFile("Textures/MapTexture.png");
    //sf::Sprite LvlTexture(backgroundTexture);

    //GameWorld gameWorld(&window);
    //GameStateManager gameStateManager(&gameWorld, GameStateId::TitleScreen);

    //BuildPlace buildPlace;
    //TowerMenu towerSelection;

    //PotatoTower potatoT;
    //potatoT.setScale();
    //CornTower corn;


    //Base base;
    //base.setScale();
    //BuildPlace place;


    //Bee bee;
    //PurpleBug bug;
    //FirstWave wave(6);

    //sf::Clock clock;
 
    //while (window.isOpen())
    //{
    //    const float deltaTime = clock.restart().asSeconds();

    //    handleSystemEvents(window);

    //    /*gameStateManager.getCurrentGameState()->update(deltaTime);
    //    gameStateManager.getCurrentGameState()->draw(window);
    //    gameStateManager.getCurrentGameState()->updateState();*/

    //    
    //    wave.update(deltaTime * 5);

    //    //potatoT.update(deltaTime);



    //    window.clear();
    //    window.draw(LvlTexture);
    //    base.draw(window);
    //    place.draw(window);
    //    towerSelection.draw(window);

    //    //corn.draw(window);

    //    wave.draw(window);
    //}
 
}
