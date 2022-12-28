#pragma once

#include <iostream>

#include "pauseMenuScreen.h"

#include <SFML/Graphics.hpp>

class gameOverSingle : public pauseMenu
{
public:
	gameOverSingle();
	virtual int Run(sf::RenderWindow& window);

protected:
	sf::Font _font;
	sf::Text _textOfScore1;

	sf::Image gameOverImage;

	sf::Texture gameOverTexture;

	sf::Sprite gameOverSprite;
};
