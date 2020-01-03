#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    // INITIALIZING
    VideoMode vm = VideoMode::getFullscreenModes()[0];

    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    float scalewidth = (vm.width) / 1920.f;
    float scaleHeight = (vm.height) / 1080.f;

    Clock clock;

    srand((int)time(0) * 10);

    // TEXTURES
    Texture textureBackground;
    textureBackground.loadFromFile("graphics/background.png");

    Texture textureTree;
    textureTree.loadFromFile("graphics/tree.png");

    Texture textureBee;
    textureBee.loadFromFile("graphics/bee.png");

    Texture textureCloud;
    textureCloud.loadFromFile("graphics/cloud.png");

    // SPRITES
    Sprite spriteBackground;
    spriteBackground.setTexture(textureBackground);
    spriteBackground.setPosition(0, 0);
    spriteBackground.scale(sf::Vector2f(scalewidth, scaleHeight));

    Sprite spriteTree;
    spriteTree.setTexture(textureTree);
    spriteTree.setPosition(vm.width / 2 - (150 * scalewidth), 0);
    spriteTree.scale(sf::Vector2f(scalewidth, scaleHeight));

    Sprite spriteCloud1;
    Sprite spriteCloud2;
    Sprite spriteCloud3;
    spriteCloud1.setTexture(textureCloud);
    spriteCloud2.setTexture(textureCloud);
    spriteCloud3.setTexture(textureCloud);
    spriteCloud1.scale(sf::Vector2f(scalewidth, scaleHeight));
    spriteCloud2.scale(sf::Vector2f(scalewidth, scaleHeight));
    spriteCloud3.scale(sf::Vector2f(scalewidth, scaleHeight));

    Sprite spriteBee;
    spriteBee.setTexture(textureBee);
    spriteBee.scale(sf::Vector2f(scalewidth, scaleHeight));

    // SPRITES INITIAL LOGIC
    bool beeActive = false;
    float beeSpeed = 0.0f;

    bool cloud1Active = false;
    bool cloud2Active = false;
    bool cloud3Active = false;
    float cloud1Speed = 0.0f;
    float cloud2Speed = 0.0f;
    float cloud3Speed = 0.0f;

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

        // CLEAR SCENE
        window.clear();

        // UPDATE SCENE
        Time dt = clock.restart();

        if (!beeActive)
        {
            beeSpeed = (rand() % 200) + 200;
            float height = (rand() % 500) + 500;

            spriteBee.setPosition(vm.width, height * scaleHeight);
            beeActive = true;
        }
        else
        {
            spriteBee.setPosition(spriteBee.getPosition().x - (beeSpeed * dt.asSeconds()), spriteBee.getPosition().y);
            if (spriteBee.getPosition().x < -100)
            {
                beeActive = false;
            }
        }

        if (!cloud1Active)
        {
            cloud1Speed = (rand() % 200) + 200;
            float height = (rand() % 300) * scaleHeight;

            spriteCloud1.setPosition(-200, height * scaleHeight);
            cloud1Active = true;
        }
        else
        {
            spriteCloud1.setPosition(spriteCloud1.getPosition().x + (cloud1Speed * dt.asSeconds()), spriteCloud1.getPosition().y);
            if (spriteCloud1.getPosition().x > vm.width)
            {
                cloud1Active = false;
            }
        }

        if (!cloud2Active)
        {
            cloud2Speed = (rand() % 200) + 200;
            float height = (rand() % 300) * scaleHeight;

            spriteCloud2.setPosition(-200, height * scaleHeight);
            cloud2Active = true;
        }
        else
        {
            spriteCloud2.setPosition(spriteCloud2.getPosition().x + (cloud2Speed * dt.asSeconds()), spriteCloud2.getPosition().y);
            if (spriteCloud2.getPosition().x > vm.width)
            {
                cloud2Active = false;
            }
        }

        if (!cloud3Active)
        {
            cloud3Speed = (rand() % 200) + 200;
            float height = (rand() % 300) * scaleHeight;

            spriteCloud3.setPosition(-200, height * scaleHeight);
            cloud3Active = true;
        }
        else
        {
            spriteCloud3.setPosition(spriteCloud3.getPosition().x + (cloud3Speed * dt.asSeconds()), spriteCloud3.getPosition().y);
            if (spriteCloud3.getPosition().x > vm.width)
            {
                cloud3Active = false;
            }
        }

        // DRAW SCENE
        window.draw(spriteBackground);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);
        window.draw(spriteTree);
        window.draw(spriteBee);

        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu