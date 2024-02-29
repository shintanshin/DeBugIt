#include "Monster.h"
#include <iomanip>
#include <iostream>

Bee::Bee()
    : m_movementTimer(0.0f), m_currentTextureIndex(0), m_frameDuration(0.1f), 
    m_elapsed(0.0f), m_speed(10.0f), m_numHealth(10)
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

Bee::Bee(float speed, const sf::Vector2f& position, int health)
:m_movementTimer(0.0f), m_currentTextureIndex(0), m_speed(speed), m_spriteBee(), m_numHealth(health)
{
    const int numTextures = 12;
    for (int i = 0; i <= numTextures; ++i)
    {
        sf::Texture texture;
        texture.loadFromFile("Textures/Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");

        m_texturesBee.push_back(texture);
    }

    m_spriteBee.setTexture(m_texturesBee[m_currentTextureIndex]);
    m_spriteBee.setPosition(position);

    m_frameDuration = 0.2f;
    m_elapsed = 0.0f;
}

void Bee::update(float deltaTime)
{
    m_elapsed += deltaTime;

   /* if (m_elapsed >= m_frameDuration)
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesBee.size();
        m_spriteBee.setTexture(m_texturesBee[m_currentTextureIndex]);
        m_elapsed = 0.0f;
    }*/

    while (m_elapsed >= m_frameDuration) // Змінено умову циклу
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesBee.size();
        m_spriteBee.setTexture(m_texturesBee[m_currentTextureIndex]);
        m_elapsed -= m_frameDuration; // Зменшено залишковий час
    }
        
}

PurpleBug::PurpleBug()
    : m_movementTimer(0.0f), currentTargetIndex(0), m_currentTextureIndex(0), 
    m_frameDuration(0.1f), m_elapsed(0.0f), m_speed(10.0f), m_numHealth(10)
{
    /*targets = { sf::Vector2f(40, 100), sf::Vector2f(290, 100), sf::Vector2f(290, 285),
            sf::Vector2f(165, 285), sf::Vector2f(165, 410), sf::Vector2f(590, 410) };*/
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

    /*if (m_elapsed >= m_frameDuration)
    {
        m_currentTextureIndex = (m_currentTextureIndex + 1) % m_texturesBug.size();
        m_spritePurpleBug.setTexture(m_texturesBug[m_currentTextureIndex]);
        if (m_currentTextureIndex < m_texturesBug.size())
        {
            m_spritePurpleBug.setTexture(m_texturesBug[m_currentTextureIndex]);
        }

        m_elapsed = 0.0f;
    }*/
    /*float movement = m_speed * deltaTime;
    setPosition(sf::Vector2f(getPosition().x, getPosition().y + movement));*/


    //moveTo(targets[currentTargetIndex], deltaTime);

    //// Перехід до наступної цільової точки при досягненні поточної
    //if (getPosition() == targets[currentTargetIndex])
    //{
    //    currentTargetIndex = (currentTargetIndex + 1) % targets.size();
    //}

    // Логіка для зникнення на останньому етапі
    if (currentTargetIndex == targets.size() - 1 && getPosition() == targets[currentTargetIndex])
    {
        // Викликати функцію для визначення, що монстр має зникнути
        // setInactive();
    }
}

//void PurpleBug::moveTo(sf::Vector2f target, float deltaTime)
//{
//    sf::Vector2f currentPosition = getPosition();
//
//    if (currentPosition == target)
//    {
//        // Монстр вже знаходиться в цільовій точці
//        return;
//    }
//
//    sf::Vector2f direction = target - currentPosition;
//    direction = normalize(direction);  // normalize - ваша функція нормалізації вектора
//
//    float distance = length(direction);
//    float movement = m_speed * deltaTime;
//
//    //if (movement >= distance)
//    //{
//    //    // Якщо рух на велику відстань, встановлюємо точно в цільову позицію
//    //    setPosition(target);
//    //}
//    //else
//    //{
//        // В іншому випадку рухаємо в напрямку цільової точки
//        setPosition(currentPosition + direction * movement);
//    /*}*/
//}

sf::Vector2f PurpleBug::normalize(const sf::Vector2f& vector)
{
    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);

    if (length != 0.0f)
    {
        return sf::Vector2f(vector.x / length, vector.y / length);
    }
    else
    {
        return vector; // повертаємо оригінальний вектор, якщо його довжина дорівнює нулю
    }
}
