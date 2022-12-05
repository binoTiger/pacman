#pragma once
#include "player.h"

class Ghost : public Player
{
public:
    Ghost(float x, float y, float speed);
    void update(float time, const sf::Vector2f coordinates, Direction pacmanDirection, bool isFrightened, Map& map);
    void setStartCoordinates();

private:
    bool canGoRight(const Map& map);
    bool canGoLeft(const Map& map);
    bool canGoDown(const Map& map);
    bool canGoUp(const Map& map);
    void setDirection(const Map& map);
    void animate(float time);
    sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);

private:
    static unsigned _count;
    static std::vector<sf::Vector2f> _frightenedTargets;

    unsigned _id;
    sf::Vector2f _target;
    sf::Vector2f _frighetenedTarget;
    bool _isFrightened;
    int _lastVisitedX;
    int _lastVisitedY;
};
