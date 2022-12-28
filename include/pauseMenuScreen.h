#pragma once
#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class pauseMenu : public cScreen
{
public:
	pauseMenu();
	virtual int Run(sf::RenderWindow& window);

protected:
	sf::Image backgroundImage;
	sf::Image continueGameKeyImage;
	sf::Image restartGameKeyImage;
	sf::Image exitGameKeyImage;

	sf::Texture backgroundTexture;
	sf::Texture continueGameKeyTexture;
	sf::Texture restartGameKeyTexture;
	sf::Texture exitGameKeyTexture;

	sf::Sprite backgroundSprite;
	sf::Sprite continueGameKeySprite;
	sf::Sprite restartGameKeySprite;
	sf::Sprite exitGameKeySprite;
};
