#include "screen_4.h"

using namespace sf;

gameScreenDuo::gameScreenDuo()
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

int gameScreenDuo::Run(RenderWindow& window)
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

	//readyText(window);

	Clock clock;

	while (window.isOpen())
	{

		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		int pointsEaten = 0;
		pointsEaten += (*player1).pointsEaten() + (*player2).pointsEaten();

		if (!ghostsVector[1]->isStart()) {
			ghostsVector[1]->start();
		}
		if (!ghostsVector[2]->isStart() && pointsEaten > 30) {
			ghostsVector[2]->start();
		}
		if (!ghostsVector[3]->isStart() && pointsEaten > 80) {
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
					window.clear();
					return 6;
				}
			}
		}

		(*player1).checkKeys(*map);
		(*player1).update(time, *map);
		(*player2).checkKeys(*map);
		(*player2).update(time, *map);

		ghostsVector[0]->update(time, (*player1).getCoordinates(), (*player1).getDirection(), (*player1).isBoosted() || (*player2).isBoosted(), *map);
		ghostsVector[1]->update(time, (*player2).getCoordinates(), (*player2).getDirection(), (*player1).isBoosted() || (*player2).isBoosted(), *map);
		ghostsVector[2]->update(time, (*player1).getCoordinates(), (*player1).getDirection(), (*player1).isBoosted() || (*player2).isBoosted(), *map);
		ghostsVector[3]->update(time, (*player2).getCoordinates(), (*player2).getDirection(), (*player1).isBoosted() || (*player2).isBoosted(), *map);

		for (auto& ghost : ghostsVector) {
			ghostAndPacmansInteraction((*player1), (*player2), (*ghost));
		}

		pacmanAndPacmanInteraction((*player1), (*player2));

		window.clear();

		/*if ((*player1).getLifes() == 0) {
			_firstPlayerScore = (*player1).points();
			_secondPlayerScore = (*player2).points();
			_winner = _parameters[3];
			window.clear();
			return 8;
		}

		if ((*player2).getLifes() == 0) {
			_firstPlayerScore = (*player1).points();
			_secondPlayerScore = (*player2).points();
			_winner = _parameters[0];
			window.clear();
			return 8;
		}*/

		if ((*player1).getLifes() * (*player2).getLifes() == 0) {
			_firstPlayerScore = (*player1).points();
			_secondPlayerScore = (*player2).points();

			if ((*player1).getLifes() == 0) {
				_winner = _parameters[3];
			}
			else {
				_winner = _parameters[0];
			}
			window.clear();
			return 8;
		}

		(*map).drawMap(window);

		if (pointsEaten >= 40) {
			_arrowLeftSprite.setPosition(_leftArrowPosition);
			window.draw(_arrowLeftSprite);
			_arrowRightSprite.setPosition(_rightArrowPosition);
			window.draw(_arrowRightSprite);
			window.draw(gameScreenDuo::leftNewLevel());
			window.draw(gameScreenDuo::rightNewLevel());
			if (checkTeleport(*player1) || checkTeleport(*player2)) {
				_isNewLevel = true;
				window.clear();
				return 4;
			}
		}

		window.draw((*player1).score());
		window.draw((*player2).score());
		window.draw((*player1).lifes());
		window.draw((*player2).lifes());
		window.draw((*player1).sprite());
		window.draw((*player2).sprite());
		window.draw(gameScreenDuo::numberOfLevels());

		for (auto& ghost : ghostsVector) {
			window.draw((*ghost).sprite());
		}

		window.display();
	}

	return 0;
}

void gameScreenDuo::clear()
{
	delete map;
	delete player1;
	delete player2;

	for (auto& it : ghostsVector) {
		delete it;
	}
}

void gameScreenDuo::newGame()
{
	//clear();
	_level = 1;
	_firstPlayerScore = 0;
	_secondPlayerScore = 0;
	_winner = "";

	map = new Map();

	player1 = new Pacman1(_parameters[1], _parameters[2], 6 * 30 + 540, 26 * 30, _levelParameters[0].x);
	player2 = new Pacman2(_parameters[4], _parameters[5], 21 * 30 + 540, 26 * 30, _levelParameters[0].x);

	ghostsVector.clear();
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, _levelParameters[0].y, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
}

void gameScreenDuo::newLevel()
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

	player1->newLevel(_levelParameters[parameter].x);
	player2->newLevel(_levelParameters[parameter].x);

	ghostsVector.clear();
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, _levelParameters[parameter].y, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, _levelParameters[parameter].y, false));

	++_level;
}

Text gameScreenDuo::numberOfLevels()
{
	std::ostringstream playerLevel;
	playerLevel << _level;
	_textOfLevels.setString("Level: " + playerLevel.str());

	Vector2f position(850, 1025);
	_textOfLevels.setPosition(position);

	return _textOfLevels;
}

Text gameScreenDuo::leftNewLevel()
{
	_textOfNewLevels.setString(" Next\nlevel");

	Vector2f position(430, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

Text gameScreenDuo::rightNewLevel()
{
	_textOfNewLevels.setString("Next\nlevel");

	Vector2f position(1400, 495);
	_textOfNewLevels.setPosition(position);

	return _textOfNewLevels;
}

void gameScreenDuo::readyText(RenderWindow& window)
{
	RectangleShape shape(Vector2f(180, 90));
	shape.setFillColor(Color::Black);
	shape.setPosition(870, 480);

	window.clear();
	(*map).drawMap(window);
	window.draw((*player1).score());
	window.draw((*player2).score());
	window.draw((*player1).lifes());
	window.draw((*player2).lifes());
	window.draw((*player1).sprite());
	window.draw((*player2).sprite());
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
	window.draw((*player1).score());
	window.draw((*player2).score());
	window.draw((*player1).lifes());
	window.draw((*player2).lifes());
	window.draw((*player1).sprite());
	window.draw((*player2).sprite());
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
