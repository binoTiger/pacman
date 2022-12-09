#pragma once

#include "pacman.h"
#include "ghost.h"

void ghostAndPacmanInteraction(Pacman& pacman, Ghost& ghost)
{
	auto pacmanCoordinates = pacman.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (!pacman.isBoosted() && !pacman.isImmortal() && Player::distance(pacmanCoordinates, ghostCoordinates) < 20) {
		pacman.setStartCoordinates();
		pacman.reduceLifes();
	}
	else if (pacman.isBoosted() && Player::distance(pacmanCoordinates, ghostCoordinates) < 20) {
		ghost.setStartCoordinates();
		pacman.increaseScoreIfEatGhost();
	}
}

void ghostAndPacmanInteraction(Pacman& pacman1, Pacman& pacman2, Ghost& ghost)
{
	auto pacman1Coordinates = pacman1.getCoordinates();
	auto pacman2Coordinates = pacman2.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (!pacman1.isBoosted() && !pacman1.isImmortal() && !ghost.isFrightened() && Player::distance(pacman1Coordinates, ghostCoordinates) < 20) {
		pacman1.setStartCoordinates();
		pacman1.reduceLifes();
	}
	else if (!pacman2.isBoosted() && !pacman2.isImmortal() && !ghost.isFrightened() && Player::distance(pacman2Coordinates, ghostCoordinates) < 20) {
		pacman2.setStartCoordinates();
		pacman2.reduceLifes();
	}
	else if (ghost.isFrightened() && Player::distance(pacman1Coordinates, ghostCoordinates) < 20) {
		ghost.setStartCoordinates();
		pacman1.increaseScoreIfEatGhost();
	}
	else if (ghost.isFrightened() && Player::distance(pacman2Coordinates, ghostCoordinates) < 20) {
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
		pacman2.setStartCoordinates();
	}
	if (!pacman1.isBoosted() && pacman2.isBoosted() && Player::distance(pacman1Coordinates, pacman2Coordinates) < 20) {
		pacman1.setStartCoordinates();
	}
}
