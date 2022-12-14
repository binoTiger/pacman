#include "screen_5.h"

using namespace sf;

void game_screen_training::newGame()
{
	_level = 0;

	map = new Map();

	player = new Pacman1(_parameters[1], _parameters[2], 945, 780, _levelParameters[0].x);
}

void game_screen_training::newLevel()
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

	++_level;
}

int game_screen_training::Run(RenderWindow& window)
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
		(*player).update(time, *map);

		window.clear();

		if ((*player).pointsEaten() >= 40) {
			if (checkTeleport(*player)) {
				_isNewLevel = true;
				return 5;
			}
		}

		(*map).drawMap(window);

		window.draw((*player).score());
		window.draw((*player).lifes());
		window.draw((*player).sprite());

		window.display();
	}

	return 0;
}
