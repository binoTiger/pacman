#pragma once
#include <SFML/Graphics.hpp>

class Menu
{
public:
    Menu();
    void drawMenu(sf::RenderWindow& window);

private:
    bool menuIsOpen;

    sf::Image startGameKeyImage;
    sf::Image exitGameKeyImage;
    sf::Image pacmanOnLoadScreenImage;
    sf::Image leftSideMapImage;
    sf::Image rightSideMapImage;

    sf::Texture startGameKeyTexture;
    sf::Texture exitGameKeyTexture;
    sf::Texture pacmanOnLoadScreenTexture;
    sf::Texture leftSideMapTexture;
    sf::Texture rightSideMapTexture;

    sf::Sprite startGameKeySprite;
    sf::Sprite exitGameKeySprite;
    sf::Sprite pacmanOnLoadScreenSprite;
    sf::Sprite leftSideMapSprite;
    sf::Sprite rightSideMapSprite;
};