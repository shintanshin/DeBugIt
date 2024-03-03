#include "Tower.h"

PotatoTower::PotatoTower()
{

	for (int i = 0; i < 3; i++)
	{
		sf::Texture texture;
		texture.loadFromFile("Textures/PotatoTower/Potato" + std::to_string(i) + ".png");
		m_texturePotatoT.push_back(texture);
	}
	m_currentTextureIndex = 0;
	m_elapsed = 0.0f;
	m_frameDuration = 0.5f;
	m_spritePotatoT.setTexture(m_texturePotatoT[m_currentTextureIndex]);
	setScale();
	setPosition(sf::Vector2f(453, 115));

}
void PotatoTower::update(float deltaTime)
{
    m_elapsed += deltaTime;

    if (m_elapsed >= m_frameDuration)
    {
		m_elapsed -= m_frameDuration;
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturePotatoT.size();
        m_spritePotatoT.setTexture(m_texturePotatoT[m_currentTextureIndex]);
        //m_elapsed = 0.0f;
    }
}

CornTower::CornTower()
{

	m_textureCornT.loadFromFile("Textures/CornTower/Corn0.png");
	m_spriteCornT.setTexture(m_textureCornT);
	//setPosition(sf::Vector2f(453, 115));
	void setScale();
}

TrunkTower::TrunkTower()
{

	m_textureTrunkT.loadFromFile("Textures/TrunkTower/Trunk0.png");
	m_spriteTrunkT.setTexture(m_textureTrunkT);
	//setPosition(sf::Vector2f(253, 115));
	void setScale();
}