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

//void handleSystemEvents(sf::RenderWindow& window)
//{
//
//    sf::Event event;
//    while (window.pollEvent(event))
//    {
//        switch (event.type)
//        {
//        case sf::Event::Closed:
//            window.close();
//            break;
//        case sf::Event::KeyPressed:
//            if (event.key.code == sf::Keyboard::Key::Escape)
//                window.close();
//        default:
//            break;
//        }
//    }
//}


int main()
{
    Game game;
    game.run();

    
 
}
