#include "screen_3.h"

using namespace sf;

gameScreenSingle::gameScreenSingle()
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

int gameScreenSingle::Run(RenderWindow& window)
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

		if (!ghostsVector[1]->isStart()) {
			ghostsVector[1]->start();
		}
		if (!ghostsVector[2]->isStart() && (*player).pointsEaten() > 30) {
			ghostsVector[2]->start();
		}
		if (!ghostsVector[3]->isStart() && (*player).pointsEaten() > 80) {
			ghostsVector[3]->start();
		}

		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed) {
				window.close();
			}
			if (event.type == Event::KeyReleased) {
				if (event.key.code == Keyboard::Escape) {
					return 6;
				}
			}
		}

		(*player).checkKeys(*map);
		(*player).update(time, (*map));

		if (_gameMode == GameMode::SINGLE) {
			for (auto& ghost : ghostsVector) {
				(*ghost).update(time, (*player).getCoordinates(), (*player).getDirection(), (*player).isBoosted(), *map);
			}

			for (auto& ghost : ghostsVector) {
				ghostAndPacmanInteraction((*player), (*ghost));
			}
		}

		window.clear();

		if ((*player).getLifes() == 0) {
			_firstPlayerScore = (*player).points();
			return 7;
		}

		(*map).drawMap(window);

		if ((*player).pointsEaten() >= 20) {
			_arrowLeftSprite.setPosition(_leftArrowPosition);
			window.draw(_arrowLeftSprite);
			_arrowRightSprite.setPosition(_rightArrowPosition);
			window.draw(_arrowRightSprite);
			window.draw(gameScreenSingle::leftNewLevel());
			window.draw(gameScreenSingle::rightNewLevel());
			if (checkTeleport(*player)) {
				_isNewLevel = true;
				window.clear();
				return 3;
			}
		}

		window.draw((*player).score());
		window.draw((*player).lifes());
		window.draw((*player).sprite());
		window.draw(gameScreenSingle::numberOfLevels());

		for (auto& ghost : ghostsVector) {
			window.draw((*ghost).sprite());
		}

		window.display();
	}

	return 0;
}

void gameScreenSingle::clear()
{
	delete player;
	delete map;

	for (auto& it : ghostsVector) {
		delete it;
	}
}

void gameScreenSingle::newGame()
{
	_level = 1;
	_firstPlayerScore = 0;

	map = new Map();

	player = new Pacman1(_parameters[1], _parameters[2], 945, 780, _levelParameters[0].x);

	ghostsVector.clear();
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, _levelParameters[0].y, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
}

void gameScreenSingle::newLevel()
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

	ghostsVector.clear();
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, _levelParameters[parameter].y, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));

	++_level;
}

Text gameScreenSingle::numberOfLevels()
{
	std::ostringstream playerLevel;
	playerLevel << _level;
	_textOfLevels.setString("Level: " + playerLevel.str());

	Vector2f position(850, 1025);
	_textOfLevels.setPosition(position);

	return _textOfLevels;
}

Text gameScreenSingle::leftNewLevel()
{
	_textOfNewLevels.setString(" New\nlevel");

	Vector2f position(430, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

Text gameScreenSingle::rightNewLevel()
{
	_textOfNewLevels.setString(" New\nlevel");

	Vector2f position(1400, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

void gameScreenSingle::readyText(RenderWindow& window)
{
	RectangleShape shape(Vector2f(180, 90));
	shape.setFillColor(Color::Black);
	shape.setPosition(870, 480);

	window.clear();
	(*map).drawMap(window);
	window.draw((*player).score());
	window.draw((*player).lifes());
	window.draw((*player).sprite());
	window.draw(numberOfLevels());
	for (auto& ghost : ghostsVector) {
		window.draw((*ghost).sprite());
	}
	window.draw(shape);

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
	for (auto& ghost : ghostsVector) {
		window.draw((*ghost).sprite());
	}
	window.draw(shape);

	_textOfGo.setString("GO");
	_textOfGo.setPosition(925, 495);
	window.draw(_textOfGo);
	window.display();

	sleep(seconds(1));
}
