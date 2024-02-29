#pragma once
#include <SFML/Graphics.hpp>

class BuildPlace {
public:
	BuildPlace() {

		m_textureBuildPlace.loadFromFile("Textures/PlaceForTower.png");
		m_spriteBuildPlace.setTexture(m_textureBuildPlace);
		setPosition(sf::Vector2f(353, 120));
	}
	void setScale() { m_spriteBuildPlace.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBuildPlace.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBuildPlace); }
private:

	sf::Texture m_textureBuildPlace;
	sf::Sprite m_spriteBuildPlace;
};