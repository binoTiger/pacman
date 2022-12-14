#pragma once

#include <iostream>
#include "cScreen.h"

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "gameInteraction.h"

#include <SFML/Graphics.hpp>

class game_screen_duo : public cScreen
{
public:
    virtual int Run(sf::RenderWindow& window);

private:
    void newGame();
    void newLevel();

private:
    Map* map;
    Pacman1* player1;
    Pacman2* player2;
    std::vector<Ghost*> ghostsVector;
};
