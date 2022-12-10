#include "screen_4.h"

using namespace sf;

int game_screen_duo::Run(RenderWindow& window)
{
	Pacman1 player1(_parameters[1], _parameters[2], 6 * 30 + 540, 26 * 30, 0.1);
	Pacman2 player2(_parameters[4], _parameters[5], 21 * 30 + 540, 26 * 30, 0.1);

	std::vector<Ghost*> ghostsVector;
	ghostsVector.push_back(new RedGhost(13 * 30 + 540 + 15, 14 * 30, 0.095, true));
	ghostsVector.push_back(new PinkGhost(13 * 30 + 540 + 15, 17 * 30, 0.095, false));
	ghostsVector.push_back(new BlueGhost(11 * 30 + 540 + 15, 17 * 30, 0.095, false));
	ghostsVector.push_back(new OrangeGhost(15 * 30 + 540 + 15, 17 * 30, 0.095, false));

	Map map;

	Clock clock;

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
		time /= 800;

		int pointsEaten = 0;
		pointsEaten += player1.pointsEaten() + player2.pointsEaten();

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
			if (Keyboard::isKeyPressed(Keyboard::Escape)) {
				return 0;
			}
		}

		player1.checkKeys(map);
		player1.update(time, map);
		player2.checkKeys(map);
		player2.update(time, map);

		ghostsVector[0]->update(time, player1.getCoordinates(), player1.getDirection(), player1.isBoosted() || player2.isBoosted(), map);
		ghostsVector[1]->update(time, player2.getCoordinates(), player2.getDirection(), player1.isBoosted() || player2.isBoosted(), map);
		ghostsVector[2]->update(time, player1.getCoordinates(), player1.getDirection(), player1.isBoosted() || player2.isBoosted(), map);
		ghostsVector[3]->update(time, player2.getCoordinates(), player2.getDirection(), player1.isBoosted() || player2.isBoosted(), map);

		for (auto& ghost : ghostsVector) {
			ghostAndPacmansInteraction(player1, player2, (*ghost));
		}

		pacmanAndPacmanInteraction(player1, player2);

		window.clear();

		map.drawMap(window);

		window.draw(player1.score());
		window.draw(player2.score());
		window.draw(player1.lifes());
		window.draw(player2.lifes());
		window.draw(player1.sprite());
		window.draw(player2.sprite());

		for (auto& ghost : ghostsVector) {
			window.draw((*ghost).sprite());
		}

		window.display();
	}

	return 0;
}
