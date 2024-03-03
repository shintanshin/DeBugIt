#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Menu.h"

class TowerMenu;


class BuildPlace {
public:
	BuildPlace();
	void setScale() { m_spriteBuildPlace.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBuildPlace.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBuildPlace); }

	void handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu);

	sf::Vector2f getPosition() const { return m_spriteBuildPlace.getPosition(); }

	void setSelectedTower(Tower* selectedTower) { m_selectedTower = selectedTower; }

	void buildTower(TowerType towerType);

private:

	sf::Texture m_textureBuildPlace;
	sf::Sprite m_spriteBuildPlace;

	Tower* m_selectedTower;

};

class BuildPlaces {
public:
	BuildPlaces();

	void draw(sf::RenderWindow& window);

	void handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu);
	

private:
	std::vector<std::unique_ptr<BuildPlace>> m_buildPlaces;

};