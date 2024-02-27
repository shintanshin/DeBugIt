#pragma once
#include <SFML/Graphics.hpp>

class Monster 
{
public:
    
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

class Bee : public Monster
{
public:
    Bee(); 
   
    void update(float deltaTime);  // метод для оновлення анімації
    void draw(sf::RenderWindow& window) { window.draw(m_sprite); }  // метод для відображення монстра
    void setScale(){ m_sprite.setScale(0.7f, 0.7f); }

    sf::Vector2f getPosition() const{ return m_sprite.getPosition();}
    void setPosition(const sf::Vector2f& position){ m_sprite.setPosition(position); }

private:
    

    std::vector<sf::Texture> m_textures;
    sf::Sprite m_sprite;
    float m_frameDuration;
    float m_elapsed;
    unsigned int m_currentTextureIndex;
    float m_speed;

    void loadTextures() {
        m_textures.reserve(13); // Резервуємо місце для 11 текстур

        for (int i = 0; i < 13; ++i)
        {
            sf::Texture texture;
            texture.loadFromFile("Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");
            m_textures.push_back(texture);
        }
    }
};