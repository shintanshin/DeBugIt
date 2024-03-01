#pragma once
#include <SFML/Graphics.hpp>

class Monster
{
public:
    virtual ~Monster() = default;
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(float deltaTime) = 0;
    virtual void setScale() = 0;
    virtual sf::Vector2f getPosition() const = 0;
    virtual void setPosition(const sf::Vector2f& position) = 0;

    virtual int getPathIdx()=0;
    virtual void setPathIdx(int idx) = 0;

    virtual void setTargets(const std::vector<sf::Vector2f>& targets) = 0;
    virtual float getSpeed() = 0;
private:
    sf::Texture m_texture;
    sf::Sprite m_sprite;
};

class Bee : public Monster
{
public:
    Bee(); 
   
    void update(float deltaTime) override;  // метод для оновлення анімації
    void draw(sf::RenderWindow& window) override { window.draw(m_spriteBee); }  // метод для відображення монстра
    void setScale(){ m_spriteBee.setScale(0.7f, 0.7f); }

    sf::Vector2f getPosition() const{ return m_spriteBee.getPosition();}
    void setPosition(const sf::Vector2f& position){ m_spriteBee.setPosition(position); }

    //std::vector<sf::Vector2f> getTargets() const override { return targets; }
    virtual void setTargets(const std::vector<sf::Vector2f>& targets) override {}
    //virtual void setTargets(const std::vector<sf::Vector2f>& newTargets) override { }

    float getSpeed() override { return m_speed; }

    int getPathIdx() override{return m_pathIdx;}
    void setPathIdx(int idx) override { m_pathIdx = idx; }


private:
    std::vector<sf::Texture> m_texturesBee;
    sf::Sprite m_spriteBee;
    float m_frameDuration;
    float m_elapsed;
    int m_currentTextureIndex;
    float m_speed;

    std::vector<sf::Vector2f> targets;

    float m_movementTimer;

    /*void loadTextures() {
        m_texturesBee.reserve(13); 

        for (int i = 0; i < 13; ++i)
        {
            sf::Texture texture;
            texture.loadFromFile("Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");
            m_texturesBee.push_back(texture);
        }
    }*/

    int m_numHealth;
    int m_pathIdx;

};

class PurpleBug : public Monster
{
public:
    PurpleBug();

    void update(float deltaTime)override;
    void draw(sf::RenderWindow& window) override { window.draw(m_spritePurpleBug); }
    void setScale() { m_spritePurpleBug.setScale(0.7f, 0.7f); }

    sf::Vector2f getPosition() const { return m_spritePurpleBug.getPosition(); }
    void setPosition(const sf::Vector2f& position) { m_spritePurpleBug.setPosition(position); }

    float getFrameDuration() { return m_frameDuration; }
    unsigned int getCurrentTextureIndex(){ return m_currentTextureIndex; }
    const std::vector<sf::Texture>& getTextures() const { return m_texturesBug; }


    //std::vector<sf::Vector2f> getTargets() const override { return targets; }
    void setTargets(const std::vector<sf::Vector2f>& newTargets) override { this->targets = newTargets; }

    float getSpeed() override { return m_speed; }

    int getPathIdx() override { return m_pathIdx; }
    void setPathIdx(int idx) override { m_pathIdx = idx; }

private:
    std::vector<sf::Texture> m_texturesBug;
    sf::Sprite m_spritePurpleBug;
    float m_frameDuration;
    float m_elapsed;
    unsigned int m_currentTextureIndex;
    float m_speed;

    unsigned int currentTargetIndex;
    std::vector<sf::Vector2f> targets;

    float m_movementTimer;

    /*void loadTextures() {
        m_texturesBug.reserve(16); 

        for (int i = 0; i < 16; ++i)
        {
            sf::Texture texture;
            texture.loadFromFile("Purple_Bug_Sprites/skeleton-animation_" + std::to_string(i) + ".png");
            m_texturesBug.push_back(texture);
        }
    }*/

    int m_numHealth;

    int m_pathIdx;
};