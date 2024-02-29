#pragma once
#include <SFML/Graphics.hpp>

class Tower
{

};

class PotatoTower : public Tower
{
public:
	PotatoTower() {

		m_texturePotatoT.loadFromFile("Textures/PotatoTower/Potato0.png");
		m_spritePotatoT.setTexture(m_texturePotatoT);
		setPosition(sf::Vector2f(353, 120));
	}
	void setScale() { m_spritePotatoT.setScale(0.4f, 0.4f); }

	void setPosition(const sf::Vector2f& position) { m_spritePotatoT.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spritePotatoT); }

private:
	unsigned m_health = 0;
	sf::Texture m_texturePotatoT;
	sf::Sprite m_spritePotatoT;

};

class CornTower : public Tower
{

};

class TrunkTower : public Tower
{

};