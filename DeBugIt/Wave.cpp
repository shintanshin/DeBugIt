#include "Wave.h"
#include "Monster.h"
#include <iostream>
#include <chrono>

FirstWave::FirstWave(unsigned int numMonsters)
    :m_currentTargetIndex(0), m_monsterCreationTimer(0.0f)
{
    m_targets = { sf::Vector2f(40, 100), sf::Vector2f(290, 100), sf::Vector2f(290, 285),
                    sf::Vector2f(165, 285), sf::Vector2f(165, 410), sf::Vector2f(590, 410) };

    monsters.reserve(numMonsters);
    
    float yOffset = 0.0f;

    for (unsigned int i = 0; i < numMonsters; ++i)
    {
        if (i % 2 == 0)
        {
            std::unique_ptr<PurpleBug> purpleBug = std::make_unique<PurpleBug>();
            purpleBug->setScale();
            purpleBug->setPosition(sf::Vector2f(40, -40 - yOffset));
            monsters.push_back(std::move(purpleBug));
        }
        else
        {
            std::unique_ptr<Bee> bee = std::make_unique<Bee>();
            bee->setScale();
            bee->setPosition(sf::Vector2f(40, -40 - yOffset));
            monsters.push_back(std::move(bee));
        }
        yOffset += 40.0f;
    }
  
  /*  for (unsigned int i = 0; i < numMonsters; ++i)
    {
        if (i < m_targets.size())
            monsters[i]->setTargets({ m_targets[i] });
    }*/
}

//void FirstWave::update(float deltaTime)
//{
//
//    for (auto& monster : m_monstersWave1DB)
//    {
//        if (monster) // перевірка на нульовий вказівник
//        {
//            // Виберіть конкретну цільову позицію для кожного монстра
//            sf::Vector2f targetPosition = m_targets[m_currentTargetIndex];
//
//            // Викликайте moveTo для кожного монстра
//            monster->update(deltaTime);
//            moveTo(*monster, m_targets[m_currentTargetIndex], deltaTime);
//
//            if (monster->getPosition() == m_targets[m_currentTargetIndex]) {
//                m_currentTargetIndex = (m_currentTargetIndex + 1) % m_targets.size();
//            }
//        }
//    }
//}

void FirstWave::update(float deltaTime)
{
    for (auto it = monsters.begin(); it != monsters.end();) //It works THE BEST!
    {
        auto& monster = *it;
        monster->update(deltaTime);
        moveTo(*monster, m_targets[monster->getPathIdx()], deltaTime);

        if (monster->getPosition() == m_targets[monster->getPathIdx()]) {
            if (monster->getPathIdx() == m_targets.size() - 1) {
                it = monsters.erase(it);
            }
            else {
                monster->setPathIdx((monster->getPathIdx() + 1) % m_targets.size());
                ++it;
            }
        }
        else {
            ++it;
        }
    }
}

void FirstWave::draw(sf::RenderWindow& window)
{
    for (const auto& monster : monsters)
    {
        monster->draw(window);
    }

}

sf::Vector2f FirstWave::normalize(const sf::Vector2f& vector)
{
    float len = length(vector);
    if (len != 0)
        return vector / len;
    else
        return vector;
}

float FirstWave::length(const sf::Vector2f& vector)
{
    return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

void FirstWave::moveTo(Monster& monster, sf::Vector2f target, float deltaTime)
{
    sf::Vector2f currentPosition = monster.getPosition();

    if (currentPosition == target)
    {
        return;
    }

    sf::Vector2f direction = target - currentPosition;
    direction = normalize(direction);

    float distance = length(direction);
    float movement = monster.getSpeed() * deltaTime;

    monster.setPosition(currentPosition + direction * movement);
}