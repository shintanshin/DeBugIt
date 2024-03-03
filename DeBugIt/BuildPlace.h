#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Menu.h"
#include <iostream>

class TowerMenu;
class BuildPlaces;

class BuildPlace {
public:
	BuildPlace(BuildPlaces* places);

	~BuildPlace();

	void setScale() { m_spriteBuildPlace.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBuildPlace.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBuildPlace); }

	void handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu);

	sf::Vector2f getPosition() const { return m_spriteBuildPlace.getPosition(); }

	void setSelectedTower(Tower* selectedTower) { m_selectedTower = selectedTower; }

	void buildTower(TowerType towerType);

	bool getIsSelected() const{return m_isSelected;}

private:
	bool m_isSelected = false;
	sf::Texture m_textureBuildPlace;
	sf::Sprite m_spriteBuildPlace;

	Tower* m_selectedTower;

	BuildPlaces* m_buildPlaces;
};

class BuildPlaces {
public:
	BuildPlaces();

	void draw(sf::RenderWindow& window);

	void handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu);

	std::vector<std::unique_ptr<BuildPlace>>& getBuildPlaces()  {return m_buildPlaces;}
	BuildPlace* getSelectedBuildPlace();

	 void removeBuildPlace(const BuildPlace* buildPlace);
private:
	std::vector<std::unique_ptr<BuildPlace>> m_buildPlaces;

};