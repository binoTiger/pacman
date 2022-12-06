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