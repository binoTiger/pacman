#include "screen_5.h"

using namespace sf;

int game_screen_training::Run(RenderWindow& window)
{
	Pacman1 player(_parameters[1], _parameters[2], 945, 780, 0.1);

	Map map;

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
				return 0;
			}
		}

		player.checkKeys(map);
		player.update(time, map);

		window.clear();

		map.drawMap(window);

		window.draw(player.score());
		window.draw(player.lifes());
		window.draw(player.sprite());

		window.display();
	}

	return 0;
}
