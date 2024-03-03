#include "BuildPlace.h"
#include "Tower.h"
#include <iostream>


BuildPlace::BuildPlace() : m_selectedTower(nullptr)
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
                std::cout << "Button PRESSED\n";
                towerMenu.setDrawEnabled(true);
            }
        }
    }
}

void BuildPlace::buildTower(TowerType towerType)
{
    Tower* newTower = nullptr;

    switch (towerType) {
    case TowerType::POTATO:
        newTower = new PotatoTower();
        break;
    case TowerType::CORN:
        newTower = new CornTower();
        break;
    case TowerType::TRUNK:
        newTower = new TrunkTower();
        break;
        // Додайте обробку інших типів башт, якщо потрібно
    default:
        return;
    }

    if (newTower) {
        newTower->setPosition(getPosition());
        newTower->setScale();
        setSelectedTower(newTower);
    }
}

BuildPlaces::BuildPlaces()
{
    std::unique_ptr<BuildPlace> place1 = std::make_unique<BuildPlace>();
    place1->setPosition(sf::Vector2f(353, 115));
    m_buildPlaces.push_back(std::move(place1));
    std::unique_ptr<BuildPlace> place2 = std::make_unique<BuildPlace>();
    place2->setPosition(sf::Vector2f(220,165));
    m_buildPlaces.push_back(std::move(place2));
    std::unique_ptr<BuildPlace> place3 = std::make_unique<BuildPlace>();
    place3->setPosition(sf::Vector2f(355, 250));
    m_buildPlaces.push_back(std::move(place3)); 
    std::unique_ptr<BuildPlace> place4 = std::make_unique<BuildPlace>();
    place4->setPosition(sf::Vector2f(230, 344));
    m_buildPlaces.push_back(std::move(place4));
    std::unique_ptr<BuildPlace> place5 = std::make_unique<BuildPlace>();
    place5->setPosition(sf::Vector2f(480, 344));
    m_buildPlaces.push_back(std::move(place5));
    std::unique_ptr<BuildPlace> place6 = std::make_unique<BuildPlace>();
    place6->setPosition(sf::Vector2f(480, 474));
    m_buildPlaces.push_back(std::move(place6));
    std::unique_ptr<BuildPlace> place7 = std::make_unique<BuildPlace>();
    place7->setPosition(sf::Vector2f(280, 474));
    m_buildPlaces.push_back(std::move(place7));
    std::unique_ptr<BuildPlace> place8 = std::make_unique<BuildPlace>();
    place8->setPosition(sf::Vector2f(485, 90));
    m_buildPlaces.push_back(std::move(place8));
    std::unique_ptr<BuildPlace> place9 = std::make_unique<BuildPlace>();
    place9->setPosition(sf::Vector2f(655, 90));
    m_buildPlaces.push_back(std::move(place9));
    std::unique_ptr<BuildPlace> place10 = std::make_unique<BuildPlace>();
    place10->setPosition(sf::Vector2f(105, 35));
    m_buildPlaces.push_back(std::move(place10));


}

void BuildPlaces::draw(sf::RenderWindow& window)
{
    for (const auto& monster : m_buildPlaces)
    {
        monster->draw(window);
    }
}

void BuildPlaces::handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu)
{
    for (const auto& buildPlace : m_buildPlaces)
    {
        buildPlace->handleEvent(event, window, towerMenu);
    }
}
