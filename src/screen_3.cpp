#include "screen_3.h"

using namespace sf;

void game_screen_single::newGame()
{
	_level = 0;

	map = new Map();

	player = new Pacman1(_parameters[1], _parameters[2], 945, 780, _levelParameters[0].x);

	ghostsVector.clear();
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, _levelParameters[0].y, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, _levelParameters[0].y, false));
}

void game_screen_single::newLevel()
{
	map = new Map();

	unsigned parameter = 0;
	if (_level < 2) {
		parameter = 0;
	}
	else if (_level < 4) {
		parameter = 1;
	}
	else if (_level < 6) {
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

int game_screen_single::Run(RenderWindow& window)
{
	if (!_isGameStart) {
		_isGameStart = true;
		newGame();
	}
	else if (_isNewLevel) {
		_isNewLevel = false;
		newLevel();
	}

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
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				return 6;
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

		if ((*player).pointsEaten() >= 40) {
			if (checkTeleport(*player)) {
				_isNewLevel = true;
				return 3;
			}
		}

		(*map).drawMap(window);

		window.draw((*player).score());
		window.draw((*player).lifes());
		window.draw((*player).sprite());

		for (auto& ghost : ghostsVector) {
			window.draw((*ghost).sprite());
		}

		window.display();
	}

	return 0;
}