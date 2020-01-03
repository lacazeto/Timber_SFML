#include "stdafx.h"
#include <SFML/Graphics.hpp>

using namespace sf;

int main()
{
    VideoMode vm = VideoMode::getFullscreenModes()[0];

    RenderWindow window(vm, "Timber!", Style::Fullscreen);

    float scalewidth = (vm.width) / 1920.f;
    float scaleHeight = (vm.height) / 1080.f;

    while (window.isOpen())
    {
        if (Keyboard::isKeyPressed(Keyboard::Escape))
        {
            window.close();
        }

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
        spriteTree.setPosition(vm.width/2 - (150 * scalewidth), 0);
        spriteTree.scale(sf::Vector2f(scalewidth, scaleHeight));

        Sprite spriteCloud1;
        Sprite spriteCloud2;
        Sprite spriteCloud3;
        spriteCloud1.setTexture(textureCloud);
        spriteCloud2.setTexture(textureCloud);
        spriteCloud3.setTexture(textureCloud);
        spriteCloud1.setPosition(0, 0);
        spriteCloud2.setPosition(0, 150 * scaleHeight);
        spriteCloud3.setPosition(0, 300 * scaleHeight);
        spriteCloud1.scale(sf::Vector2f(scalewidth, scaleHeight));
        spriteCloud2.scale(sf::Vector2f(scalewidth, scaleHeight));
        spriteCloud3.scale(sf::Vector2f(scalewidth, scaleHeight));

        Sprite spriteBee;
        spriteBee.setTexture(textureBee);
        spriteBee.setPosition(0, 800 * scaleHeight);
        spriteBee.scale(sf::Vector2f(scalewidth, scaleHeight));

        // SPRITES LOGIC
        bool beeActive = false;
        float beeSpeed = 0.0f;

        bool cloud1Active = false;
        bool cloud2Active = false;
        bool cloud3Active = false;
        float cloud1Speed = 0.0f;
        float cloud2Speed = 0.0f;
        float cloud3Speed = 0.0f;

        window.clear();

        // DRAW
        window.draw(spriteBackground);
        window.draw(spriteTree);
        window.draw(spriteBee);
        window.draw(spriteCloud1);
        window.draw(spriteCloud2);
        window.draw(spriteCloud3);

        window.display();
    }

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu