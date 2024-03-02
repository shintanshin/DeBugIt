#include "Menu.h"
#include <iostream>

//void TowerMenuItem::draw(sf::RenderWindow& window)
//{
//        m_tower->draw(window);
//        if (m_isSelected) {
//            // Тут можна намалювати позначку (наприклад, рамку) для вибраного спрайту
//        }
//}
//
//void TowerMenuItem::handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window)
//{
//
//    if (!m_isSelected) {
//        std::cout << "Mouse X: " << mousePosition.x << ", Mouse Y: " << mousePosition.y << std::endl;
//        sf::FloatRect bounds = m_sprite.getGlobalBounds();
//        //sf::Vector2f mousePosFloat(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
//        sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//
//        /*if (bounds.contains(mousePosFloat)) {*/
//            if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
//            m_isSelected = true;
//            std::cout << "Button PRESSED";
//
//            // Перевірте, чи було вибрано башту, і встановіть позицію, якщо так
//            /*if (m_isSelected) {
//                m_selectedTower = createTower();
//                m_selectedTowerPosition = m_sprite.getPosition();
//            }*/
//        }
//    }
//}
//
//Tower* TowerMenuItem::createTower()
//{
//    switch (m_towerType) {
//    case POTATO:
//        return new PotatoTower();
//    case CORN:
//        return new CornTower();
//    case TRUNK:
//        return new TrunkTower();
//    default:
//        return nullptr; // Обробка невідомого типу башти
//    }
//}
//
//TowerMenu::TowerMenu()
//{
//
//      m_towerItems.push_back(TowerMenuItem(new PotatoTower(), POTATO));
//      m_towerItems.push_back(TowerMenuItem(new CornTower(), CORN));
//      m_towerItems.push_back(TowerMenuItem(new TrunkTower(), TRUNK));
//
//      /*m_potatoTexture.loadFromFile("Textures/Potato0.png");
//      m_cornTexture.loadFromFile("Textures/Corn0.png");
//      m_trunkTexture.loadFromFile("Textures/Trunk0.png");*/
//
//      m_textureTowerMenu.loadFromFile("Textures/TowerSelectWin_sprite.png");
//      m_backgroundSprite.setTexture(m_textureTowerMenu);
//
//      m_backgroundSprite.setScale(2, 1.3);
//      m_backgroundSprite.setRotation(90);
//
//      // Виведіть розмір текстури та спрайта для перевірки
//      std::cout << "Texture size: " << m_textureTowerMenu.getSize().x << "x" << m_textureTowerMenu.getSize().y << std::endl;
//      std::cout << "Sprite size: " << m_backgroundSprite.getGlobalBounds().width << "x" << m_backgroundSprite.getGlobalBounds().height << std::endl;
//
//      m_backgroundSprite.setPosition(795.0f, 130.0f);
//
//
//        std::vector<sf::Vector2f> towerPositions = {
//    sf::Vector2f(719.0f, 140.0f),
//    sf::Vector2f(727.0f, 220.0f),
//    sf::Vector2f(678.0f, 330.0f),
//        };
//        arrangeTowers(towerPositions);
//}
//
//void TowerMenu::draw(sf::RenderWindow& window)
//{
//
//    if (m_drawEnabled) {
//        window.draw(m_backgroundSprite);
//        for (auto& tower : m_towerItems) {
//            tower.draw(window);
//        }
//    }
//}
//
//void TowerMenu::handleSelection(sf::Vector2i mousePosition,sf::RenderWindow& window)
//{
//    std::cout << "Handling selection..." << std::endl;
//    for (auto& towerItem : m_towerItems) {
//        towerItem.handleEvent(mousePosition, window);
//        if (towerItem.isSelected()) {
//            m_selectedTower = towerItem.getTower();
//            //m_selectedTower = towerItem.getSelectedTower();
//            m_selectedTowerPosition = towerItem.getSelectedTowerPosition();
//            std::cout << "Button PRESSED";
//            break;
//        }
//    }
//
//}
//
//void TowerMenu::resetSelection()
//{
//    for (auto& item : m_towerItems) {
//        item.setSelected(false);
//    }
//}
//
//Tower* TowerMenu::getSelectedTower() const
//{
//    for (const auto& item : m_towerItems) {
//        if (item.isSelected()) {
//            return item.getTower();
//        }
//    }
//    return nullptr; // Якщо нічого не вибрано
//}
//
//void TowerMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
//{
//    for (auto& item : m_towerItems) {
//        if (event.type == sf::Event::MouseButtonPressed) {
//            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
//            item.handleEvent(mousePosition, window);
//        }
//    }
//}
//
//void TowerMenu::arrangeTowers(const std::vector<sf::Vector2f>& positions)
//{
//    std::size_t numTowers = std::min(m_towerItems.size(), positions.size());
//
//    for (std::size_t i = 0; i < numTowers; ++i) {
//        Tower* tower = m_towerItems[i].getTower();
//        tower->setPosition(positions[i]);
//        tower->setScale();
//    }
//}
//
//sf::Texture TowerMenu::getTowerTexture(TowerType type) const
//{
//    switch (type) {
//    case POTATO:
//        return m_potatoTexture;
//    case CORN:
//        return m_cornTexture;
//    case TRUNK:
//        return m_trunkTexture;
//    default:
//        return sf::Texture();  // Повернути пусту текстуру або обробити інші випадки
//    }
//}
//    
//Tower* TowerMenu::createPotatoTower()
//{
//    return new PotatoTower();
//}
//
//Tower* TowerMenu::createCornTower()
//{
//    return new CornTower();
//}
//
//Tower* TowerMenu::createTrunkTower() {
//    return new TrunkTower();
//}


//TEST 
void TowerMenuItem::draw(sf::RenderWindow& window)
{
    window.draw(m_sprite);
        if (m_isSelected) {
            // Тут можна намалювати позначку (наприклад, рамку) для вибраного спрайту
        }
}

void TowerMenuItem::handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window)
{
}

TowerMenu::TowerMenu()
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


 

    
          m_backgroundSprite.setScale(2, 1.3);
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

void TowerMenu::handleSelection(sf::Vector2i mousePosition, sf::RenderWindow& window)
{
}

void TowerMenu::resetSelection()
{
}

void TowerMenu::handleEvent(sf::Event& event, sf::RenderWindow& window)
{
}

void TowerMenu::arrangeTowers(const std::vector<sf::Vector2f>& positions)
{
}
