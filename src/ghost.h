#pragma once
#include "player.h"

class Ghost : public Player
{
public:
    Ghost(float x, float y, float speed, bool canStart);
    void update(float time, const sf::Vector2f coordinates, Direction pacmanDirection, bool isFrightened, Map& map);
    void setStartCoordinates();
    bool isStart();
    void start();

    static unsigned _count;

private:
    bool canGoRight(const Map& map);
    bool canGoLeft(const Map& map);
    bool canGoDown(const Map& map);
    bool canGoUp(const Map& map);
    void setDirection(const Map& map);
    void animate(float time);
    sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);

private:
    static std::vector<sf::Vector2f> _frightenedTargets;

    unsigned _id;
    sf::Vector2f _target;
    sf::Vector2f _frighetenedTarget;
    bool _isFrightened;
    int _lastVisitedX;
    int _lastVisitedY;
    bool _isStart;
};