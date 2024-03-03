#include "BuildPlace.h"
#include "Tower.h"
#include <iostream>


BuildPlace::BuildPlace(BuildPlaces* places) : m_selectedTower(nullptr), m_buildPlaces(places)
{
    m_textureBuildPlace.loadFromFile("Textures/PlaceForTower.png");
    m_spriteBuildPlace.setTexture(m_textureBuildPlace);
    
}

BuildPlace::~BuildPlace()
{
}

void BuildPlace::handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu)
{
    m_isSelected = false;
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            sf::FloatRect bounds = m_spriteBuildPlace.getGlobalBounds();

            if (bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y))) {
                m_isSelected = true;
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
    default:
        return;
    }

    if (newTower) {
        newTower->setPosition(getPosition());
        newTower->setScale();
        setSelectedTower(newTower);
    }
    if (m_buildPlaces) {
        std::cout << "Removing BuildPlace at position: " << getPosition().x << ", " << getPosition().y << std::endl;
        m_buildPlaces->removeBuildPlace(this);
    }
    else {
        std::cout << "m_buildPlaces is nullptr" << std::endl;
    }
}

//void BuildPlace::buildTower(TowerType towerType, std::vector<std::unique_ptr<BuildPlace>>& buildPlaces)
//{
//    Tower* newTower = nullptr;
//
//    switch (towerType) {
//    case TowerType::POTATO:
//        newTower = new PotatoTower();
//        break;
//    case TowerType::CORN:
//        newTower = new CornTower();
//        break;
//    case TowerType::TRUNK:
//        newTower = new TrunkTower();
//        break;
//        // Додайте обробку інших типів башт, якщо потрібно
//    default:
//        return;
//    }
//
//    if (newTower) {
//        newTower->setPosition(getPosition());
//        newTower->setScale();
//        setSelectedTower(newTower);
//
//        //for (auto it = buildPlaces.begin(); it != buildPlaces.end(); ++it) {
//        //    std::cout << "Comparing BuildPlace at position: " << it->get()->getPosition().x << ", " << it->get()->getPosition().y << std::endl;
//
//        //    if (it->get() == this) {
//        //        std::cout << "Found matching BuildPlace at position: " << getPosition().x << ", " << getPosition().y << std::endl;
//        //        buildPlaces.erase(it);
//        //        break;  // Вийдемо із циклу після видалення
//        //    }
//        //}
//    }
//}

BuildPlaces::BuildPlaces()
{
    m_buildPlaces = std::vector<std::unique_ptr<BuildPlace>>();

    std::unique_ptr<BuildPlace> place1 = std::make_unique<BuildPlace>(this);
    place1->setPosition(sf::Vector2f(353, 115));
    m_buildPlaces.push_back(std::move(place1));
    std::unique_ptr<BuildPlace> place2 = std::make_unique<BuildPlace>(this);
    place2->setPosition(sf::Vector2f(220,165));
    m_buildPlaces.push_back(std::move(place2));
    std::unique_ptr<BuildPlace> place3 = std::make_unique<BuildPlace>(this);
    place3->setPosition(sf::Vector2f(355, 250));
    m_buildPlaces.push_back(std::move(place3)); 
    std::unique_ptr<BuildPlace> place4 = std::make_unique<BuildPlace>(this);
    place4->setPosition(sf::Vector2f(230, 344));
    m_buildPlaces.push_back(std::move(place4));
    std::unique_ptr<BuildPlace> place5 = std::make_unique<BuildPlace>(this);
    place5->setPosition(sf::Vector2f(480, 344));
    m_buildPlaces.push_back(std::move(place5));
    std::unique_ptr<BuildPlace> place6 = std::make_unique<BuildPlace>(this);
    place6->setPosition(sf::Vector2f(480, 474));
    m_buildPlaces.push_back(std::move(place6));
    std::unique_ptr<BuildPlace> place7 = std::make_unique<BuildPlace>(this);
    place7->setPosition(sf::Vector2f(280, 474));
    m_buildPlaces.push_back(std::move(place7));
    std::unique_ptr<BuildPlace> place8 = std::make_unique<BuildPlace>(this);
    place8->setPosition(sf::Vector2f(485, 90));
    m_buildPlaces.push_back(std::move(place8));
    std::unique_ptr<BuildPlace> place9 = std::make_unique<BuildPlace>(this);
    place9->setPosition(sf::Vector2f(655, 90));
    m_buildPlaces.push_back(std::move(place9));
    std::unique_ptr<BuildPlace> place10 = std::make_unique<BuildPlace>(this);
    place10->setPosition(sf::Vector2f(105, 35));
    m_buildPlaces.push_back(std::move(place10));


}

void BuildPlaces::draw(sf::RenderWindow& window)
{
    for (const auto& places : m_buildPlaces)
    {
        places->draw(window);
    }
}

void BuildPlaces::handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu)
{
    for (const auto& buildPlace : m_buildPlaces)
    {
        buildPlace->handleEvent(event, window, towerMenu);
    }
}

BuildPlace* BuildPlaces::getSelectedBuildPlace()
{
    auto it = std::find_if(m_buildPlaces.begin(), m_buildPlaces.end(), [](std::unique_ptr<BuildPlace>& place) {return place->getIsSelected(); });
    if (it != m_buildPlaces.end()) {
        return it->get();
    }
    return nullptr;
}

void BuildPlaces::removeBuildPlace(const BuildPlace* buildPlace)
{
    auto it = std::remove_if(m_buildPlaces.begin(), m_buildPlaces.end(),
        [buildPlace](const auto& place) {
            return place.get() == buildPlace;
        });

    if (it != m_buildPlaces.end()) {
        m_buildPlaces.erase(it, m_buildPlaces.end());
    }
}
