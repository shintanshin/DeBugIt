#include "Wave.h"
#include "Monster.h"
#include <iostream>
#include <chrono>


//FirstWave::FirstWave():m_currentTextureIndex(0), m_elapsed(0.0f), m_speed(10.0f) 
//{
//    targets = { sf::Vector2f(40, 100), sf::Vector2f(290, 100), sf::Vector2f(290, 285),
//            sf::Vector2f(165, 285), sf::Vector2f(165, 410), sf::Vector2f(590, 410) };
//
//    sf::Vector2f initialPosition = m_purpleBug->getPosition();
//    m_spritePurpleBug.setPosition(initialPosition);
//}
//
////FirstWave::FirstWave(PurpleBug* monster, float speed)
////    : m_purpleBug(monster), m_speed(speed)
////{
////	targets = { sf::Vector2f(40, 100), sf::Vector2f(290, 100), sf::Vector2f(290, 285),
////			sf::Vector2f(165, 285), sf::Vector2f(165, 410), sf::Vector2f(590, 410) };
////
////    sf::Vector2f initialPosition = m_purpleBug->getPosition();
////    m_spritePurpleBug.setPosition(initialPosition);
////}
//
//void FirstWave::update(float deltaTime)
//{
//    m_purpleBug->update(deltaTime);
//
//    m_elapsed += deltaTime;
//
//    if (m_elapsed >= m_purpleBug->getFrameDuration())
//    {
//        m_currentTextureIndex = (m_purpleBug->getCurrentTextureIndex() + 1) % m_purpleBug->getTextures().size();
//        m_spritePurpleBug.setTexture(m_purpleBug->getTextures()[m_currentTextureIndex]);
//        m_elapsed = 0.0f;
//    }
//    if (m_spritePurpleBug.getPosition() == targets[currentTargetIndex])
//    {
//        currentTargetIndex = (currentTargetIndex + 1) % targets.size();
//    }
//}
//
//void FirstWave::moveTo(sf::Vector2f target, float deltaTime)
//{
//    
//        sf::Vector2f currentPosition = m_spritePurpleBug.getPosition();
//
//        if (currentPosition == target)
//        {
//            return;
//        }
//
//        sf::Vector2f direction = target - currentPosition;
//        direction = normalize(direction);  
//
//        float distance = length(direction);
//        float movement = m_speed * deltaTime;
//
//        m_spritePurpleBug.setPosition(currentPosition + direction * movement);
//       
//}
//
//sf::Vector2f FirstWave::normalize(const sf::Vector2f& vector)
//{
//    float length = std::sqrt(vector.x * vector.x + vector.y * vector.y);
//
//    if (length != 0.0f)
//    {
//        return sf::Vector2f(vector.x / length, vector.y / length);
//    }
//    else
//    {
//        return vector; 
//    }
//}

FirstWave::FirstWave()
    :m_currentTargetIndex(0), m_monsterCreationTimer(0.0f)
{
    m_targets = { sf::Vector2f(40, 100), sf::Vector2f(290, 100), sf::Vector2f(290, 285),
                    sf::Vector2f(165, 285), sf::Vector2f(165, 410), sf::Vector2f(590, 410) };

   
    std::unique_ptr<Bee> bee1 = std::make_unique<Bee>( 10.0f, sf::Vector2f(100.0f, 200.0f), 10 );
    bee1->setScale();
    m_monstersWave1DB.push_back(bee1.get());

    std::unique_ptr<Bee> bee2 = std::make_unique<Bee>(10.0f, sf::Vector2f(150.0f, 200.0f), 10 );
    bee2->setScale();
    m_monstersWave1DB.push_back(bee2.get());

    std::unique_ptr<Bee> bee3 = std::make_unique<Bee>(10.0f, sf::Vector2f(200.0f, 200.0f), 10) ;
    bee3->setScale();
    m_monstersWave1DB.push_back(bee3.get());

    std::unique_ptr<Bee> bee4 = std::make_unique<Bee>(10.0f, sf::Vector2f(250.0f, 200.0f), 10) ;
    bee4->setScale();
    m_monstersWave1DB.push_back(bee4.get());
}

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
    m_monsterCreationTimer += deltaTime;

    for (auto& monster : monsters) //It works!
    {
        sf::Vector2f targetPosition = m_targets[m_currentTargetIndex];

        monster->update(deltaTime);
        moveTo(*monster, m_targets[m_currentTargetIndex], deltaTime);

        if (monster->getPosition() == m_targets[m_currentTargetIndex]) {
            m_currentTargetIndex = (m_currentTargetIndex + 1) % m_targets.size();
        }
        
    }

    //for (auto& monster : monsters) {
    //    float monsterTimer = monster->getMovementTimer();

    //    // Викликайте moveTo для кожного монстра
    //    moveTo(*monster, m_targets[m_currentTargetIndex], deltaTime);

    //    monster->update(deltaTime);

    //    if (monster->getPosition() == m_targets[m_currentTargetIndex]) {
    //        m_currentTargetIndex = (m_currentTargetIndex + 1) % m_targets.size();
    //        monsterTimer = 0.0f;  // Скидання таймера тільки після досягнення цільової позиції
    //    }

    //    monster->setMovementTimer(monsterTimer);
    //}

}

void FirstWave::draw(sf::RenderWindow& window)
{
    for (const auto& monster : monsters)
    {
        monster->draw(window);
    }

    /*for (const auto& monster : m_monstersWave1DB)
    {
        monster->draw(window);
    }*/
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