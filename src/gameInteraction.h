#pragma once

#include "pacman.h"
#include "ghost.h"

void ghostAndPacmanInteraction(Pacman& pacman, Ghost& ghost)
{
	auto pacmanCoordinates = pacman.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (!pacman.isBoosted() && Player::distance(pacmanCoordinates.first, pacmanCoordinates.second, ghostCoordinates.first, ghostCoordinates.second) < 20) {
		pacman.setStartCoordinates();
	}
}