#pragma once
#include "Monster.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <memory>
#include <queue>

class PurpleBug;

class Wave 
{
public:
    virtual void draw(sf::RenderWindow& window) = 0;
    virtual void update(float deltaTime) = 0;
private:
};

class FirstWave : public Wave 
{
//public:
//    FirstWave();
//	/*FirstWave(PurpleBug* monster, float speed);*/
//
//    void update(float deltaTime)override;
//    void draw(sf::RenderWindow& window) override { window.draw(m_spritePurpleBug); }
//
//    void moveTo(sf::Vector2f target, float deltaTime);
//    sf::Vector2f normalize(const sf::Vector2f& vector);
//    float length(const sf::Vector2f& vector)
//    {
//        return std::sqrt(vector.x * vector.x + vector.y * vector.y);
//    }
//    
//
//private:
//	unsigned int currentTargetIndex;
//	std::vector<sf::Vector2f> targets;
//    sf::Sprite m_spritePurpleBug;
//
//    float m_elapsed;
//    unsigned int m_currentTextureIndex;
//    //float m_frameDuration;
//
//    float m_speed;
//    PurpleBug* m_purpleBug;

public:

    FirstWave();
    FirstWave(unsigned int numMonsters);

    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

    sf::Vector2f normalize(const sf::Vector2f& vector);
    float length(const sf::Vector2f& vector);
    void moveTo(Monster& monster, sf::Vector2f target, float deltaTime);

private:
    std::vector<std::unique_ptr<Monster>> monsters;
    std::vector<sf::Vector2f> m_targets;

    unsigned int m_currentTargetIndex;
    
    float m_monsterCreationTimer;

    std::vector<Monster*> m_monstersWave1DB;


};