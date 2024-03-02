#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tower.h"

class Menu 
{
public:
    virtual void draw(sf::RenderWindow& window) = 0;
};
class PauseMenu : public Menu 
{

};

class MainMenu : public Menu
{

};

class TowerMenuItem {
public:
    TowerMenuItem(Tower* tower, TowerType type) : m_tower(tower), m_isSelected(false), m_towerType(type) {}
    
    void draw(sf::RenderWindow& window);

    Tower* getTower() const { return m_tower; }
    bool isSelected() const { return m_isSelected; }
    void setSelected(bool selected) { m_isSelected = selected; }
    void handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window);
    Tower* getSelectedTower() const { return m_selectedTower;}
   
    sf::Vector2f getSelectedTowerPosition() const {return m_selectedTowerPosition;}
    Tower* createTower();

    void setPosition(const sf::Vector2f& position) {
        m_sprite.setPosition(position);
    }

private:
    TowerType m_towerType;
    Tower* m_tower;
    bool m_isSelected;

    Tower* m_selectedTower;
    sf::Sprite m_sprite;
    sf::Vector2f m_selectedTowerPosition;

};
class TowerMenu : public Menu
{
public:
    TowerMenu();

    void draw(sf::RenderWindow& window) override;
    void handleSelection(sf::Vector2i mousePosition, sf::RenderWindow& window);
    void resetSelection();

    Tower* getSelectedTower() const;

    void setDrawEnabled(bool drawEnabled) { m_drawEnabled = drawEnabled;}
    bool getDrawEnabled() const { return m_drawEnabled; }
    void addTower(Tower* tower) {m_towers.push_back(tower);}

    void handleEvent(sf::Event& event, sf::RenderWindow& window);

    //void arrangeTowers();
    void arrangeTowers(const std::vector<sf::Vector2f>& positions);
private:
    std::vector<Tower*> m_towers;
    std::vector<TowerMenuItem> m_towerItems;
    bool m_drawEnabled;
    sf::Sprite m_backgroundSprite;
    sf::Texture m_textureTowerMenu;

    Tower* m_selectedTower;
    sf::Vector2f m_selectedTowerPosition;
    Tower* createPotatoTower();
    Tower* createCornTower();
    Tower* createTrunkTower();
};

class WinMenu : public Menu
{

};

class LoseMenu : public Menu
{

};

class SoundMenu : public Menu
{

};