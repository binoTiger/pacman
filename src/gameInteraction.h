#pragma once

#include "pacman.h"
#include "ghost.h"

void ghostAndPacmanInteraction(Pacman& pacman, Ghost& ghost)
{
	auto pacmanCoordinates = pacman.getCoordinates();
	auto ghostCoordinates = ghost.getCoordinates();

	if (Player::distance(pacmanCoordinates.first, pacmanCoordinates.second, ghostCoordinates.first, ghostCoordinates.second) < 10) {
		pacman.setStartCoordinates();
	}
}