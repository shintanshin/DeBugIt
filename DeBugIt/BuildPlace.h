#pragma once
#include <SFML/Graphics.hpp>

class BuildPlace {
public:
	BuildPlace() {

		m_textureBuildPlace.loadFromFile("Textures/PlaceForTower.png");
		m_spriteBuildPlace.setTexture(m_textureBuildPlace);
		setPosition(sf::Vector2f(353, 115));
	}
	void setScale() { m_spriteBuildPlace.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBuildPlace.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBuildPlace); }

	void handleEvent(sf::Event& event, sf::RenderWindow& window);

	bool isClicked(const sf::Vector2i& mousePosition) const {
		sf::FloatRect bounds = m_spriteBuildPlace.getGlobalBounds();
		return bounds.contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y));
	}
	sf::Vector2f getPosition() const { return m_spriteBuildPlace.getPosition(); }

private:

	sf::Texture m_textureBuildPlace;
	sf::Sprite m_spriteBuildPlace;
};