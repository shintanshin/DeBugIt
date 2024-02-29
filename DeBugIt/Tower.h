#pragma once
#include <SFML/Graphics.hpp>

class Tower
{
public:
	virtual void setPosition(const sf::Vector2f& position) = 0;

};

class PotatoTower : public Tower
{
public:
	PotatoTower() {

		m_texturePotatoT.loadFromFile("Textures/PotatoTower/Potato0.png");
		m_spritePotatoT.setTexture(m_texturePotatoT);
		setPosition(sf::Vector2f(353, 115));
	}
	void setScale() { m_spritePotatoT.setScale(0.8f, 0.8f); }

	void setPosition(const sf::Vector2f& position) override { m_spritePotatoT.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spritePotatoT); }

private:
	sf::Texture m_texturePotatoT;
	sf::Sprite m_spritePotatoT;

};

class CornTower : public Tower
{

};

class TrunkTower : public Tower
{

};