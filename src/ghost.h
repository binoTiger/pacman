#pragma once
#include "player.h"

class Ghost : public Player
{
public:
    Ghost(sf::String file, float x, float y);
    void update(float time, const std::pair<float, float> coordinates, bool escape, Map& map);

private:
    bool canGoRight(const Map& map);
    bool canGoLeft(const Map& map);
    bool canGoDown(const Map& map);
    bool canGoUp(const Map& map);
    void getDirection(const Map& map);

private:
    std::pair<float, float> _target;
    bool there = false;
};
