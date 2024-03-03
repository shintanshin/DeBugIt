#include "Menu.h"
#include <iostream>
#include "BuildPlace.h"

void TowerMenuItem::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
        if (m_isSelected) {
            // Тут можна намалювати позначку (наприклад, рамку) для вибраного спрайту
        }
}

void TowerMenuItem::handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window)
{
        if (!m_isSelected) {
            //std::cout << "Mouse X: " << mousePosition.x << ", Mouse Y: " << mousePosition.y << std::endl;
            sf::FloatRect bounds = m_sprite.getGlobalBounds();
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
    
                if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                m_isSelected = true;
                std::cout << "Button PRESSED" << std::endl;

            }
        }
}

TowerMenu::TowerMenu(): m_drawEnabled(false), m_selectedTower(nullptr)
{
    m_textureTowerMenu.loadFromFile("Textures/TowerSelectWin_sprite.png");
          m_backgroundSprite.setTexture(m_textureTowerMenu);

    m_potatoTexture.loadFromFile("Textures/PotatoTower/Potato0.png");
      m_potatoSprite.setTexture(m_potatoTexture);

    m_cornTexture.loadFromFile("Textures/CornTower/Corn0.png");
      m_cornSprite.setTexture(m_cornTexture);
    m_trunkTexture.loadFromFile("Textures/TrunkTower/Trunk0.png");
      m_trunkSprite.setTexture(m_trunkTexture);

    m_towerItems.emplace_back(POTATO, m_potatoTexture, sf::Vector2f(715.0f, 140.0f), sf::Vector2f(0.9f, 0.9f));
    m_towerItems.emplace_back(CORN, m_cornTexture, sf::Vector2f(723.0f, 220.0f), sf::Vector2f(1.0f, 1.0f));
    m_towerItems.emplace_back(TRUNK, m_trunkTexture, sf::Vector2f(661.5f, 330.0f), sf::Vector2f(1.8f, 1.8f));


 

    
          m_backgroundSprite.setScale(2.0f, 1.3f);
          m_backgroundSprite.setRotation(90);

          m_backgroundSprite.setPosition(795.0f, 130.0f);
          std::vector<sf::Vector2f> towerPositions = {
                 sf::Vector2f(719.0f, 140.0f),
                  sf::Vector2f(727.0f, 220.0f),
                  sf::Vector2f(678.0f, 330.0f),
           };
}

void TowerMenu::draw(sf::RenderWindow& window) {
    if (m_drawEnabled) {
        window.draw(m_backgroundSprite);

        for ( auto& towerItem : m_towerItems) {
            towerItem.draw(window);
        }
    }
}

void TowerMenu::resetSelection()
{
}

void TowerMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    static bool mousePressed = false;

    if (event.type == sf::Event::MouseButtonPressed && !mousePressed) {
        mousePressed = true;  // Встановіть флаг, що миша натиснута
        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);

        sf::FloatRect menuBounds = m_backgroundSprite.getGlobalBounds();

        if (menuBounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
            for (auto& item : m_towerItems) {
                item.handleEvent(mousePosition, window);
                std::cout << "Item isSelected: " << item.isSelected() << std::endl;
                if (item.isSelected()) {
                    m_selectedTower = item.getTower();
                    std::cout << "Tower Type isSelected: " << item.getTowerType() << std::endl;
                    std::cout << "Button PRESSED\n";
                    m_drawEnabled = false;  // Закриваємо меню башт після вибору
                    break;
                }
            }
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        mousePressed = false;  // Скидайте флаг, коли миша відпущена
        std::cout << "Button RELEASED\n";
    }

}

void TowerMenu::arrangeTowers(const std::vector<sf::Vector2f>& positions)
{
}
void TowerMenu::buildSelectedTower(BuildPlace& buildPlace)
{
    auto selectedTowerItem = std::find_if(m_towerItems.begin(), m_towerItems.end(), [](const TowerMenuItem& item) {
        return item.isSelected();
        });

    if (selectedTowerItem != m_towerItems.end()) {
        TowerType selectedTowerType = selectedTowerItem->getTowerType();
        buildPlace.buildTower(selectedTowerType);
    }
}
