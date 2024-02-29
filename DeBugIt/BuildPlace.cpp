#include "BuildPlace.h"
#include "Tower.h"

void BuildPlace::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = m_spriteBuildPlace.getGlobalBounds();

            // Перевірка, чи клік був на спрайті BuildPlace
            if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                // Тут ви можете викликати код для вибору башти (наприклад, вибір PotatoTower)
                Tower* selectedTower = new PotatoTower();
                selectedTower->setPosition(m_spriteBuildPlace.getPosition());
                // Додайте код для додавання вибраної башти до гри або обробки інших подій
            }
        }
    }
}
