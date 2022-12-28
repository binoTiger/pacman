#pragma once

#include <iostream>

#include "gameOverSingleScreen.h"

#include <SFML/Graphics.hpp>

class gameOverDuo : public gameOverSingle
{
public:
	gameOverDuo();
	virtual int Run(sf::RenderWindow& window);

private:
	sf::Text _textOfScore2;
	sf::Text _winnerPlayer;
};
