#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Tower.h"
#include <iostream>

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

//class TowerMenuItem {
//public:
//    /*TowerMenuItem(Tower* tower, TowerType type) : m_tower(tower), m_isSelected(false), m_towerType(type),
//        m_selectedTower(tower){
//    }*/
//    TowerMenuItem(TowerType type, const std::string& texturePath) : m_towerType(type), m_texturePath(texturePath),
//        m_isSelected(false) {
//        m_sprite.setTexture(getTowerTexture(m_towerType));
//    }
//
//    void draw(sf::RenderWindow& window);
//
//    Tower* getTower() const { return m_tower; }
//    bool isSelected() const { return m_isSelected; }
//    void setSelected(bool selected) { m_isSelected = selected; }
//    void handleEvent(sf::Vector2i mousePosition, sf::RenderWindow& window);
//    Tower* getSelectedTower() const { return m_selectedTower;}
//   
//    sf::Vector2f getSelectedTowerPosition() const {return m_selectedTowerPosition;}
//    Tower* createTower();
//
//    void setPosition(const sf::Vector2f& position) {
//        m_sprite.setPosition(position);
//    }
//
//
//private:
//    TowerType m_towerType;
//    Tower* m_tower;
//    bool m_isSelected;
//
//    Tower* m_selectedTower;
//    sf::Sprite m_sprite;
//    sf::Vector2f m_selectedTowerPosition;
//
//    sf::Texture m_texture;
//    std::string m_texturePath;
//
//    sf::Texture getTowerTexture(TowerType type) const {
//        // Логіка вибору текстури на основі типу башти
//        // (можна використовувати m_texturePath для завантаження текстури)
//    }
//
//    sf::Texture m_potatoTexture;
//    sf::Texture m_cornTexture;
//    sf::Texture m_trunkTexture;
//
//};
//
//class TowerMenu : public Menu
//{
//public:
//    TowerMenu();
//
//    void draw(sf::RenderWindow& window) override;
//    void handleSelection(sf::Vector2i mousePosition, sf::RenderWindow& window);
//    void resetSelection();
//
//    Tower* getSelectedTower() const;
//
//    void setDrawEnabled(bool drawEnabled) { m_drawEnabled = drawEnabled;}
//    bool getDrawEnabled() const { return m_drawEnabled; }
//    void addTower(Tower* tower) {m_towers.push_back(tower);}
//
//    void handleEvent(sf::Event& event, sf::RenderWindow& window);
//
//    void arrangeTowers(const std::vector<sf::Vector2f>& positions);
//
//    sf::Texture getTowerTexture(TowerType type) const;
//private:
//    std::vector<Tower*> m_towers;
//    std::vector<TowerMenuItem> m_towerItems;
//    bool m_drawEnabled;
//    sf::Sprite m_backgroundSprite;
//    sf::Texture m_textureTowerMenu;
//
//    Tower* m_selectedTower;
//    sf::Vector2f m_selectedTowerPosition;
//    Tower* createPotatoTower();
//    Tower* createCornTower();
//    Tower* createTrunkTower();
//
//    sf::Sprite m_potatoSprite;
//    sf::Texture m_potatoTexture;
//
//    sf::Sprite m_cornSprite;
//    sf::Texture m_cornTexture;
//
//    sf::Sprite m_trunkSprite;
//    sf::Texture m_trunkTexture;
//};

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

private:
    TowerType m_towerType;
    bool m_isSelected;
    sf::Sprite m_sprite;
    sf::Vector2f m_selectedTowerPosition;

    sf::Texture m_texture;
    std::string m_texturePath;

    sf::Vector2f m_position;
    sf::Vector2f m_scale;

};

class TowerMenu : public Menu {
public:
    TowerMenu();

    void draw(sf::RenderWindow& window) override;
    void handleSelection(sf::Vector2i mousePosition, sf::RenderWindow& window);
    void resetSelection();

    bool getDrawEnabled() const { return m_drawEnabled; }
    void setDrawEnabled(bool drawEnabled) { m_drawEnabled = drawEnabled; }

    void handleEvent(sf::Event& event, sf::RenderWindow& window);

    void arrangeTowers(const std::vector<sf::Vector2f>& positions);

private:
    std::vector<TowerMenuItem> m_towerItems;
    bool m_drawEnabled;
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