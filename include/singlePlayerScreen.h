#pragma once

#include <iostream>

#include "trainingScreen.h"

#include <SFML/Graphics.hpp>

class singlePlayer : public training
{
public:
    singlePlayer();
    virtual int Run(sf::RenderWindow& window);

protected:
    void newGame();
    void newLevel();
    void readyText(sf::RenderWindow& window);

protected:
    std::vector<Ghost*> ghostsVector;
};
