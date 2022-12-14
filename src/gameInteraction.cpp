#include "../include/gameInteraction.h"

void ghostAndPacmanInteraction(Pacman& pacman, Ghost& ghost)
{
	auto pacmanCoordinates = pacman.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (!pacman.isBoosted() && !pacman.isImmortal() && Player::distance(pacmanCoordinates, ghostCoordinates) < 20) {
		pacman.restart();
		pacman.reduceLifes();
	}
	else if (pacman.isBoosted() && Player::distance(pacmanCoordinates, ghostCoordinates) < 20) {
		ghost.setStartCoordinates();
		pacman.increaseScoreIfEatGhost();
	}
}

void ghostAndPacmansInteraction(Pacman& pacman1, Pacman& pacman2, Ghost& ghost)
{
	auto pacman1Coordinates = pacman1.getCoordinates();
	auto pacman2Coordinates = pacman2.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (!pacman1.isBoosted() && !pacman1.isImmortal() && !ghost.isFrightened() && Player::distance(pacman1Coordinates, ghostCoordinates) < 20) {
		pacman1.restart();
		pacman1.reduceLifes();
	}
	if (!pacman2.isBoosted() && !pacman2.isImmortal() && !ghost.isFrightened() && Player::distance(pacman2Coordinates, ghostCoordinates) < 20) {
		pacman2.restart();
		pacman2.reduceLifes();
	}
	if (ghost.isFrightened() && Player::distance(pacman1Coordinates, ghostCoordinates) < 20) {
		ghost.setStartCoordinates();
		pacman1.increaseScoreIfEatGhost();
	}
	if (ghost.isFrightened() && Player::distance(pacman2Coordinates, ghostCoordinates) < 20) {
		ghost.setStartCoordinates();
		pacman2.increaseScoreIfEatGhost();
	}
}

void pacmanAndPacmanInteraction(Pacman& pacman1, Pacman& pacman2)
{
	auto pacman1Coordinates = pacman1.getCoordinates();
	auto pacman2Coordinates = pacman2.getCoordinates();

	if ((pacman1.isImmortal() || pacman2.isImmortal()) && Player::distance(pacman1Coordinates, pacman2Coordinates) < 20) {
		return;
	}
	if (pacman1.isBoosted() && !pacman2.isBoosted() && Player::distance(pacman1Coordinates, pacman2Coordinates) < 20) {
		pacman2.restart();
	}
	if (!pacman1.isBoosted() && pacman2.isBoosted() && Player::distance(pacman1Coordinates, pacman2Coordinates) < 20) {
		pacman1.restart();
	}
}

bool checkTeleport(Pacman& pacman)
{
	return Player::distance(540, 510, pacman.getCoordinates()) < 10 ||
		Player::distance(1350, 510, pacman.getCoordinates()) < 10;
}
