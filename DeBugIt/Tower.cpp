#include "Tower.h"

PotatoTower::PotatoTower() : m_drawEnabled(false)
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
	setDrawEnabled(false);

}
void PotatoTower::update(float deltaTime)
{
    m_elapsed += deltaTime;

    if (m_elapsed >= m_frameDuration)
    {
		m_elapsed -= m_frameDuration;
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturePotatoT.size();
        m_spritePotatoT.setTexture(m_texturePotatoT[m_currentTextureIndex]);
        m_elapsed = 0.0f;
    }
}

CornTower::CornTower()
{

	/*m_textureCornT.loadFromFile("Textures/CornTower/Corn0.png");
	m_spriteCornT.setTexture(m_textureCornT);
	void setScale();*/
}

CornTower::CornTower(TowerType type, const sf::Vector2f& pos): m_type(type), m_pos (pos), m_drawEnabled(false)
{
	m_textureCornT.loadFromFile("Textures/CornTower/Corn0.png");
	m_spriteCornT.setTexture(m_textureCornT);
	void setScale();
}

CornTower::~CornTower()
{
}

TrunkTower::TrunkTower() : m_drawEnabled(false)
{

	m_textureTrunkT.loadFromFile("Textures/TrunkTower/Trunk0.png");
	m_spriteTrunkT.setTexture(m_textureTrunkT);
	void setScale();
}