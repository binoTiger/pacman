#pragma once

#include <SFML/Graphics.hpp>
#include "textbox.h"

enum class GameMode
{
	NONE,
	SINGLE = 3,
	DUO,
	TRAINING
};

enum class PacmanColors
{
	GREY,
	PINK,
	YELLOW,
	GREEN
};

enum class PacmanControls
{
	ARROWS,
	WASD
};

std::vector<std::string> readParametersFromFile(std::string fileName);
void writeParametersInFile(std::string fileName, std::vector<std::string> parameters);

PacmanColors getColor(std::string color);
std::string setColor(PacmanColors color);
PacmanControls getControls(std::string control);
std::string setControls(PacmanControls control);

class cScreen
{
public:
	virtual int Run(sf::RenderWindow& App) = 0;
	static bool _isGameStart;
	void clear();

protected:
	static GameMode _gameMode;
	static std::vector<std::string> _parameters;
	static bool _isNewLevel;

	static unsigned _level;
	static std::vector<sf::Vector2f> _levelParameters;

	static unsigned _firstPlayerScore;
	static unsigned _secondPlayerScore;
	static std::string _winner;
};