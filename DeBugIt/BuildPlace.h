#pragma once
#include <SFML/Graphics.hpp>
#include "Tower.h"
#include "Menu.h"


class BuildPlace {
public:
	BuildPlace();
	void setScale() { m_spriteBuildPlace.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBuildPlace.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBuildPlace); }

	void handleEvent(sf::Event& event, sf::RenderWindow& window, TowerMenu& towerMenu);

	bool isClicked(const sf::Vector2i& mousePosition) const;
	sf::Vector2f getPosition() const { return m_spriteBuildPlace.getPosition(); }

private:

	sf::Texture m_textureBuildPlace;
	sf::Sprite m_spriteBuildPlace;
};