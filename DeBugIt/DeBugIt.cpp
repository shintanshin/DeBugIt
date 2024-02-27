#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <algorithm>
#include "Monster.h"
#include "Base.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "DeBugIt");

    sf::Texture backgroundTexture;
    backgroundTexture.loadFromFile("MapTexture.png");
    sf::Sprite LvlTexture(backgroundTexture);

    Bee bee;
    bee.setScale();
    Base base;
    base.setScale();

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
            }

        }
            float deltaTime = clock.restart().asSeconds();
            //float deltaTime = 0.5f;
            bee.update(deltaTime*5);

            window.clear();
            window.draw(LvlTexture);
            base.draw(window);
            bee.draw(window);
            window.display();
    }
}
