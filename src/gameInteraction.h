#pragma once

#include "pacman.h"
#include "ghost.h"

void ghostAndPacmanInteraction(Pacman& pacman, Ghost& ghost);
void ghostAndPacmansInteraction(Pacman& pacman1, Pacman& pacman2, Ghost& ghost);
void pacmanAndPacmanInteraction(Pacman& pacman1, Pacman& pacman2);
bool checkTeleport(Pacman& pacman);
