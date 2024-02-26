#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include "Monster.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DeBugIt");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("LvlTexture.png");
    sf::Sprite LvlTexture(backgroundTexture);
    LvlTexture.setScale({ 0.63f, 0.7f });

    Bee bee;
    sf::Clock clock;
    bee.setScale();

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
            }

            //float deltaTime = clock.restart().asSeconds();
            float deltaTime = 0.2f;
            bee.update(deltaTime);

            window.clear();
            window.draw(LvlTexture);
            bee.draw(window);
            window.display();
        }
    }
}
