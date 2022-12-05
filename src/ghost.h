#pragma once
#include "player.h"

class Ghost : public Player
{
public:
    Ghost(sf::String file, float x, float y);
    void update(float time, const sf::Vector2f coordinates, bool isFrightened, Map& map);
    void setStartCoordinates();

private:
    bool canGoRight(const Map& map);
    bool canGoLeft(const Map& map);
    bool canGoDown(const Map& map);
    bool canGoUp(const Map& map);
    void setDirection(const Map& map);

private:
    sf::Vector2f _target;
    bool there = false;
    int _lastVisitedX;
    int _lastVisitedY;
    bool _isFrightened;
};
