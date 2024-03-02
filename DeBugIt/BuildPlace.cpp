#include "BuildPlace.h"
#include "Tower.h"
#include <iostream>


BuildPlace::BuildPlace()
{
    m_textureBuildPlace.loadFromFile("Textures/PlaceForTower.png");
    m_spriteBuildPlace.setTexture(m_textureBuildPlace);
    setPosition(sf::Vector2f(353, 115));
}

void BuildPlace::handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = m_spriteBuildPlace.getGlobalBounds();

            // Перевірка, чи клік був на спрайті BuildPlace
            if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                // Тут ви можете викликати код для вибору башти (наприклад, вибір PotatoTower)
                std::cout << "Button PRESSED";
                towerMenu.handleSelection(mousePosition, window);
                //Tower* selectedTower = towerMenu.getSelectedTower();

                towerMenu.setDrawEnabled(true);
               
            }
        }
    }
}

//bool BuildPlace::isClicked(const sf::Vector2i& mousePosition) const
//{
//    sf::FloatRect bounds = m_spriteBuildPlace.getGlobalBounds();
//    return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
//}
