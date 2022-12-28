#pragma once

#include <iostream>
#include "cScreen.h"

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "gameInteraction.h"

#include <SFML/Graphics.hpp>

class gameScreenTraining : public cScreen
{
public:
    gameScreenTraining();
    virtual int Run(sf::RenderWindow& window);
    void clear();

private:
    void newGame();
    void newLevel();
    void readyText(sf::RenderWindow& window);
    sf::Text numberOfLevels();
    sf::Text leftNewLevel();
    sf::Text rightNewLevel();

private:
    Map* map;
    Pacman1* player;
    sf::Text _textOfLevels;
    sf::Text _textOfNewLevels;
    sf::Text _textOfReady;
    sf::Text _textOfGo;
    sf::Font _fontOfLevels;
    sf::Image _arrowImage;
    sf::Texture _arrowTexture;
    sf::Sprite _arrowLeftSprite;
    sf::Sprite _arrowRightSprite;
    sf::Vector2f _leftArrowPosition;
    sf::Vector2f _rightArrowPosition;
};

