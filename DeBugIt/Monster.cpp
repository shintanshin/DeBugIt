#include "Monster.h"
#include <iomanip>
#include <iostream>

Bee::Bee()
    : m_movementTimer(0.0f), m_currentTextureIndex(0), m_frameDuration(0.1f), 
    m_elapsed(0.0f), m_speed(10.0f), m_numHealth(10), m_pathIdx(0)
{
 
    for (int i = 0; i <= 12; ++i)
    {
        sf::Texture texture;
        texture.loadFromFile("Textures/Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");

        m_texturesBee.push_back(texture);
    }

    m_spriteBee.setTexture(m_texturesBee[m_currentTextureIndex]);
    //setPosition(sf::Vector2f(15, -40));

    m_frameDuration = 0.2f;
    m_elapsed = 0.0f;
}


void Bee::update(float deltaTime)
{
    m_elapsed += deltaTime;

    if (m_elapsed >= m_frameDuration)
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesBee.size();
        m_spriteBee.setTexture(m_texturesBee[m_currentTextureIndex]);
        m_elapsed = 0.0f;
    }
        
}

PurpleBug::PurpleBug()
    : m_movementTimer(0.0f), currentTargetIndex(0), m_currentTextureIndex(0), 
    m_frameDuration(0.1f), m_elapsed(0.0f), m_speed(10.0f), m_numHealth(10), 
    m_pathIdx(0)
{

    for (int i = 0; i <= 14; ++i)
    {
        sf::Texture texture;
        texture.loadFromFile("Textures/Purple_Bug_Sprites/skeleton-animation_" + std::to_string(i) + ".png");

        m_texturesBug.push_back(texture);
    }

    m_spritePurpleBug.setTexture(m_texturesBug[m_currentTextureIndex]);
    //setPosition(sf::Vector2f(40, -40));

    m_frameDuration = 0.2f;
    m_elapsed = 0.0f;
}

void PurpleBug::update(float deltaTime)
{
    m_elapsed += deltaTime;

    if (m_elapsed >= m_frameDuration)
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesBug.size();
        m_spritePurpleBug.setTexture(m_texturesBug[m_currentTextureIndex]);
        m_elapsed = 0.0f;
    }

}

