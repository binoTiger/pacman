#pragma once

#include <iostream>
#include "singlePlayerScreen.h"

#include <SFML/Graphics.hpp>

class duoPlayer : public singlePlayer
{
public:
    duoPlayer();
    virtual int Run(sf::RenderWindow& window);

private:
    void newGame();
    void newLevel();
    void readyText(sf::RenderWindow& window);

private:
    Pacman2* player2;
};
