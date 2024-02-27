#include "Monster.h"
#include <iomanip>
#include <iostream>

Bee::Bee():m_currentTextureIndex(0), m_frameDuration(0.1f), m_elapsed(0.0f), m_speed(10.0f)
{
 
    for (int i = 0; i <= 12; ++i)
    {
        sf::Texture texture;
        texture.loadFromFile("Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");

        m_textures.push_back(texture);
    }

    m_sprite.setTexture(m_textures[m_currentTextureIndex]);
    setPosition(sf::Vector2f(15, -40));

    m_frameDuration = 0.2f;
    m_elapsed = 0.0f;
}

void Bee::update(float deltaTime)
{
    m_elapsed += deltaTime;

    if (m_elapsed >= m_frameDuration)
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_textures.size();
        m_sprite.setTexture(m_textures[m_currentTextureIndex]);
        if (m_currentTextureIndex < m_textures.size())
        {
            m_sprite.setTexture(m_textures[m_currentTextureIndex]);
        }

        m_elapsed = 0.0f;
    }
        float movement = m_speed * deltaTime;
        setPosition(sf::Vector2f(getPosition().x, getPosition().y + movement));
        
}

