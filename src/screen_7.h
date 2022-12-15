#pragma once

#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class gameOverSingle : public cScreen
{
public:
	gameOverSingle();
	virtual int Run(sf::RenderWindow& window);

private:
	sf::Font _font;
	sf::Text _textOfScore;

	sf::Image gameOverImage;
	sf::Image backgroundImage;
	sf::Image restartGameKeyImage;
	sf::Image exitGameKeyImage;

	sf::Texture gameOverTexture;
	sf::Texture backgroundTexture;
	sf::Texture restartGameKeyTexture;
	sf::Texture exitGameKeyTexture;

	sf::Sprite gameOverSprite;
	sf::Sprite backgroundSprite;
	sf::Sprite restartGameKeySprite;
	sf::Sprite exitGameKeySprite;
};
