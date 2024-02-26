#pragma once
#include <SFML/Graphics.hpp>

class Monster 
{
public:
    
private:

};

class Bee
{
public:
    Bee();  // конструктор
   
    void update(float deltaTime);  // метод для оновлення анімації
    void draw(sf::RenderWindow& window);  // метод для відображення монстра
    void setScale();

private:
    //sf::Texture texture1, /*texture2,*/ texture3, /*texture4,*/ texture5, /*texture6,*/ texture7,
    //    /*texture8,*/ texture9, /*texture10,*/ texture11, /*texture12,*/ texture13;

    std::vector<sf::Texture> textures;
    sf::Sprite sprite;
    float frameDuration;
    float elapsed;
    unsigned int currentTextureIndex;
};