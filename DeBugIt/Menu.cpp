#include "Menu.h"
#include <iostream>

void TowerMenuItem::draw(sf::RenderWindow& window)
{
        m_tower->draw(window);
        if (m_isSelected) {
            // Тут можна намалювати позначку (наприклад, рамку) для вибраного спрайту
        }
}

void TowerMenuItem::handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window)
{
    sf::FloatRect bounds = m_sprite.getGlobalBounds();
    m_isSelected = bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));

    // Перевірте, чи було вибрано башту, і встановіть позицію, якщо так
    if (m_isSelected) {
        m_selectedTower = createTower();
        m_selectedTowerPosition = m_sprite.getPosition();
    }
}

Tower* TowerMenuItem::createTower()
{
    switch (m_towerType) {
    case POTATO:
        return new PotatoTower();
    case CORN:
        return new CornTower();
    case TRUNK:
        return new TrunkTower();
    default:
        return nullptr; // Обробка невідомого типу башти
    }
}

TowerMenu::TowerMenu()
{

      m_towerItems.push_back(TowerMenuItem(new PotatoTower(), POTATO));
      m_towerItems.push_back(TowerMenuItem(new CornTower(), CORN));
      m_towerItems.push_back(TowerMenuItem(new TrunkTower(), TRUNK));

      m_textureTowerMenu.loadFromFile("Textures/TowerSelectWin_sprite.png");
      
      m_backgroundSprite.setTexture(m_textureTowerMenu);
      m_backgroundSprite.setScale(2, 1.3);
      m_backgroundSprite.setRotation(90);

      // Виведіть розмір текстури та спрайта для перевірки
      std::cout << "Texture size: " << m_textureTowerMenu.getSize().x << "x" << m_textureTowerMenu.getSize().y << std::endl;
      std::cout << "Sprite size: " << m_backgroundSprite.getGlobalBounds().width << "x" << m_backgroundSprite.getGlobalBounds().height << std::endl;

      m_backgroundSprite.setPosition(795.0f, 130.0f);

        //arrangeTowers();

        std::vector<sf::Vector2f> towerPositions = {
    sf::Vector2f(719.0f, 140.0f),
    sf::Vector2f(727.0f, 220.0f),
    sf::Vector2f(678.0f, 330.0f),
    // ... інші позиції за необхідності
        };
        arrangeTowers(towerPositions);
}

void TowerMenu::draw(sf::RenderWindow& window)
{

    if (m_drawEnabled) {
        window.draw(m_backgroundSprite);
        for (auto& tower : m_towerItems) {
            tower.draw(window);
        }
    }
}

void TowerMenu::handleSelection(sf::Vector2i mousePosition,sf::RenderWindow& window)
{
    for (auto& towerItem : m_towerItems) {
        towerItem.handleEvent(mousePosition, window);
        if (towerItem.isSelected()) {
            //m_selectedTower = towerItem.getTower();
            m_selectedTower = towerItem.getSelectedTower();
            m_selectedTowerPosition = towerItem.getSelectedTowerPosition();
            break;
        }
    }

}

void TowerMenu::resetSelection()
{
    for (auto& item : m_towerItems) {
        item.setSelected(false);
    }
}

Tower* TowerMenu::getSelectedTower() const
{
    for (const auto& item : m_towerItems) {
        if (item.isSelected()) {
            return item.getTower();
        }
    }
    return nullptr; // Якщо нічого не вибрано
}

void TowerMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
    for (auto& item : m_towerItems) {
        if (event.type == sf::Event::MouseButtonPressed || event.type == sf::Event::MouseMoved) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            item.handleEvent(mousePosition, window);
        }
    }
}

void TowerMenu::arrangeTowers()
{
    float x = 719.0f; // початкова позиція X
    float y = 140.0f; // початкова позиція Y

    for (auto& item : m_towerItems) {
        Tower* tower = item.getTower();
        tower->setPosition(sf::Vector2f(x, y));
        tower->setScale();
        y += 80.0f; // відступ між баштами
    }
  
}

void TowerMenu::arrangeTowers(const std::vector<sf::Vector2f>& positions)
{
    std::size_t numTowers = std::min(m_towerItems.size(), positions.size());

    for (std::size_t i = 0; i < numTowers; ++i) {
        Tower* tower = m_towerItems[i].getTower();
        tower->setPosition(positions[i]);
        tower->setScale();
    }
}
    
Tower* TowerMenu::createPotatoTower()
{
    return new PotatoTower();
}

Tower* TowerMenu::createCornTower()
{
    return new CornTower();
}

Tower* TowerMenu::createTrunkTower() {
    return new TrunkTower();
}
