#include "Monster.h"
#include <iomanip>

Bee::Bee()
{
    //texture1.loadFromFile("Bee_sprites/skeleton-animation_00.png");
    ////texture2.loadFromFile("Bee_sprites/skeleton-animation_01.png");
    //texture3.loadFromFile("Bee_sprites/skeleton-animation_02.png");
    ////texture4.loadFromFile("Bee_sprites/skeleton-animation_03.png");
    //texture5.loadFromFile("Bee_sprites/skeleton-animation_04.png");
    ////texture6.loadFromFile("Bee_sprites/skeleton-animation_05.png");
    //texture7.loadFromFile("Bee_sprites/skeleton-animation_06.png");
    ////texture8.loadFromFile("Bee_sprites/skeleton-animation_07.png");
    //texture9.loadFromFile("Bee_sprites/skeleton-animation_08.png");
    ////texture10.loadFromFile("Bee_sprites/skeleton-animation_09.png");
    //texture11.loadFromFile("Bee_sprites/skeleton-animation_10.png");
    ////texture12.loadFromFile("Bee_sprites/skeleton-animation_11.png");
    //texture13.loadFromFile("Bee_sprites/skeleton-animation_12.png");
    for (int i = 0; i <= 11; ++i)
    {
        sf::Texture texture;
        texture.loadFromFile("Bee_sprites/skeleton-animation_" + std::to_string(i) + ".png");

        textures.push_back(texture);
    }

    sprite.setTexture(textures[0]);
    currentTextureIndex = 0;

    frameDuration = 0.2f;
    elapsed = 0.0f;
}

void Bee::update(float deltaTime)
{
    elapsed += deltaTime;

    if (elapsed >= frameDuration)
    {
       // if (sprite.getTexture() == &texture1)
       //     sprite.setTexture(texture3);
       ///* else if (sprite.getTexture() == &texture2)
       //     sprite.setTexture(texture3);*/
       // else if (sprite.getTexture() == &texture3)
       //     sprite.setTexture(texture5);
       // /*else if (sprite.getTexture() == &texture4)
       //     sprite.setTexture(texture5);*/
       // else if (sprite.getTexture() == &texture5)
       //     sprite.setTexture(texture7);
       // /*else if (sprite.getTexture() == &texture6)
       //     sprite.setTexture(texture7);*/
       // else if (sprite.getTexture() == &texture7)
       //     sprite.setTexture(texture9);
       // /*else if (sprite.getTexture() == &texture8)
       //     sprite.setTexture(texture9);*/
       // else if (sprite.getTexture() == &texture9)
       //     sprite.setTexture(texture11);
       // /*else if (sprite.getTexture() == &texture10)
       //     sprite.setTexture(texture11);*/
       // else if (sprite.getTexture() == &texture11)
       //     sprite.setTexture(texture13);
       // /*else if (sprite.getTexture() == &texture12)
       //     sprite.setTexture(texture13);*/
       // else
       //     sprite.setTexture(texture1);
        currentTextureIndex = (currentTextureIndex + 1) % textures.size();
        sprite.setTexture(textures[currentTextureIndex]);

        elapsed = 0.0f;
    }
}

void Bee::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

void Bee::setScale()
{
    sprite.setScale(0.7f, 0.7f);
}
