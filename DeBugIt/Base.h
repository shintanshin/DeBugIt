#pragma once
#include <SFML/Graphics.hpp>

class Base 
{
public:
	Base() {
		
		m_textureBase.loadFromFile("BaseTree.png");
		m_spriteBase.setTexture(m_textureBase);
		setPosition(sf::Vector2f(545, 300));
	}
	void setScale() { m_spriteBase.setScale(1.2f, 1.2f); }

	void setPosition(const sf::Vector2f& position) { m_spriteBase.setPosition(position); }
	void draw(sf::RenderWindow& window) { window.draw(m_spriteBase); }

private:
	sf::Texture m_textureBase;
	sf::Sprite m_spriteBase;
};