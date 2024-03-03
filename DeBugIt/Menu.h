#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tower.h"
#include <iostream>
#include "BuildPlace.h"

class BuildPlace;

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
    TowerMenuItem(TowerType type, const sf::Texture& texture, const sf::Vector2f& position, const sf::Vector2f& scale)
        : m_towerType(type), m_isSelected(false), m_position(position), m_scale(scale)
    {
        m_sprite.setTexture(texture);
        updateSprite();
    }

    void draw(sf::RenderWindow& window);

    bool isSelected() const { return m_isSelected; }
    void setSelected(bool selected) { m_isSelected = selected; }
    
    void handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window);
    sf::Vector2f getSelectedTowerPosition() const { return m_selectedTowerPosition; }

    void setPosition(const sf::Vector2f& position) {
        m_sprite.setPosition(position);
    }

    void updateSprite() {
        m_sprite.setPosition(m_position);
        m_sprite.setScale(m_scale.x, m_scale.y);
    }
    Tower* getTower() const { return m_tower; }
    TowerType getTowerType() const { return m_towerType; }

private:
    TowerType m_towerType;
    bool m_isSelected;
    sf::Sprite m_sprite;
    sf::Vector2f m_selectedTowerPosition;
    Tower* m_tower;

    sf::Texture m_texture;
    std::string m_texturePath;

    sf::Vector2f m_position;
    sf::Vector2f m_scale;

};

class TowerMenu : public Menu {
public:
    TowerMenu();

    void draw(sf::RenderWindow& window) override;
    void resetSelection();

    bool getDrawEnabled() const { return m_drawEnabled; }
    void setDrawEnabled(bool drawEnabled) { m_drawEnabled = drawEnabled; }

    void handleEvent(sf::Event& event, sf::RenderWindow& window);

    void arrangeTowers(const std::vector<sf::Vector2f>& positions);

    void buildSelectedTower(BuildPlace& buildPlace);

    Tower* getSelectedTower() const {
        return m_selectedTower;
    }


private:
    std::vector<TowerMenuItem> m_towerItems;
    bool m_drawEnabled;
    Tower* m_selectedTower;

    sf::Vector2f m_selectedTowerPosition;

    sf::Sprite m_backgroundSprite;
    sf::Texture m_textureTowerMenu;

    sf::Texture m_potatoTexture;
    sf::Sprite m_potatoSprite;

    sf::Texture m_cornTexture;
    sf::Sprite m_cornSprite;

    sf::Texture m_trunkTexture;
    sf::Sprite m_trunkSprite;
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