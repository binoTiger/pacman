#include "screen_5.h"

using namespace sf;

gameScreenTraining::gameScreenTraining()
{
	_fontOfLevels.loadFromFile("../fonts/CrackMan.TTF");
	_textOfLevels = Text("", _fontOfLevels, 40);
	_textOfLevels.setFillColor(Color::Yellow);
	_textOfLevels.setStyle(Text::Bold);

	_textOfReady = Text("", _fontOfLevels, 40);
	_textOfReady.setFillColor(Color::Yellow);
	_textOfReady.setStyle(Text::Bold);

	_textOfGo = Text("", _fontOfLevels, 40);
	_textOfGo.setFillColor(Color::Yellow);
	_textOfGo.setStyle(Text::Bold);

	_textOfNewLevels = Text("", _fontOfLevels, 24);
	_textOfNewLevels.setFillColor(Color::Yellow);
	_textOfNewLevels.setStyle(Text::Bold);

	_arrowImage.loadFromFile("../images/arrow.png");
	_arrowImage.createMaskFromColor(Color::Green);

	_arrowTexture.loadFromImage(_arrowImage);

	_leftArrowPosition = { 560, 510 };
	_rightArrowPosition = { 1270, 510 };

	_arrowLeftSprite.setTexture(_arrowTexture);

	_arrowRightSprite.setTexture(_arrowTexture);
	_arrowRightSprite.setTextureRect(IntRect(90, 0, -90, 30));
}

int gameScreenTraining::Run(RenderWindow& window)
{
	window.setMouseCursorVisible(false);

	if (!_isGameStart) {
		_isGameStart = true;
		newGame();
	}
	else if (_isNewLevel) {
		_isNewLevel = false;
		newLevel();
	}

	readyText(window);

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Escape) {
					window.clear();
					return 6;
				}
			}
		}

		(*player).checkKeys(*map);
		(*player).update(time, *map);

		window.clear();

		(*map).drawMap(window);

		if ((*player).pointsEaten() >= 20) {
			_arrowLeftSprite.setPosition(_leftArrowPosition);
			window.draw(_arrowLeftSprite);
			_arrowRightSprite.setPosition(_rightArrowPosition);
			window.draw(_arrowRightSprite);
			window.draw(gameScreenTraining::leftNewLevel());
			window.draw(gameScreenTraining::rightNewLevel());
			if (checkTeleport(*player)) {
				_isNewLevel = true;
				window.clear();
				return 5;
			}
		}

		window.draw((*player).score());
		window.draw((*player).lifes());
		window.draw((*player).sprite());
		window.draw(numberOfLevels());

		window.display();
	}

	return 0;
}

void gameScreenTraining::clear()
{
	delete map;
	delete player;
}

void gameScreenTraining::newGame()
{
	_level = 1;

	map = new Map();

	player = new Pacman1(_parameters[1], _parameters[2], 945, 780, _levelParameters[0].x);
}

void gameScreenTraining::newLevel()
{
	map = new Map();

	unsigned parameter = 0;
	if (_level <= 2) {
		parameter = 0;
	}
	else if (_level <= 4) {
		parameter = 1;
	}
	else if (_level <= 6) {
		parameter = 2;
	}
	else {
		parameter = 3;
	}

	player->newLevel(_levelParameters[parameter].x);

	++_level;
}

Text gameScreenTraining::numberOfLevels()
{
	std::ostringstream playerLevel;
	playerLevel << _level;
	_textOfLevels.setString("Level: " + playerLevel.str());

	Vector2f position(850, 1025);
	_textOfLevels.setPosition(position);

	return _textOfLevels;
}

Text gameScreenTraining::leftNewLevel()
{
	_textOfNewLevels.setString(" New\nlevel");

	Vector2f position(430, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

Text gameScreenTraining::rightNewLevel()
{
	_textOfNewLevels.setString(" New\nlevel");

	Vector2f position(1400, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

void gameScreenTraining::readyText(RenderWindow& window)
{
	window.clear();
	(*map).drawMap(window);
	window.draw((*player).score());
	window.draw((*player).lifes());
	window.draw((*player).sprite());
	window.draw(numberOfLevels());

	_textOfReady.setString("READY");
	_textOfReady.setPosition(885, 495);
	window.draw(_textOfReady);
	window.display();

	sleep(seconds(1));

	window.clear();
	(*map).drawMap(window);
	window.draw((*player).score());
	window.draw((*player).lifes());
	window.draw((*player).sprite());
	window.draw(numberOfLevels());

	_textOfGo.setString("GO");
	Vector2f positionSecond(925, 495);
	_textOfGo.setPosition(positionSecond);
	window.draw(_textOfGo);
	window.display();

	sleep(seconds(1));
}
