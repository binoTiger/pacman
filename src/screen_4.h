#pragma once

#include <iostream>
#include "cScreen.h"

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "gameInteraction.h"

#include <SFML/Graphics.hpp>

class gameScreenDuo : public cScreen
{
public:
    gameScreenDuo();
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
    Pacman1* player1;
    Pacman2* player2;
    std::vector<Ghost*> ghostsVector;
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
