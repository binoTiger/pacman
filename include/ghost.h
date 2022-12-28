#pragma once
#include "player.h"

class Ghost : public Player
{
public:
    Ghost(sf::String imageName, float x, float y, float speed, bool canStart);
    void update(float time, const sf::Vector2f coordinates, Direction pacmanDirection, bool isFrightened, Map& map);
    void setStartCoordinates();
    bool isStart();
    void start();
    bool isFrightened();

protected:
    bool canGoRight(const Map& map);
    bool canGoLeft(const Map& map);
    bool canGoDown(const Map& map);
    bool canGoUp(const Map& map);
    void setDirection(const Map& map);
    void animate(float time);

    virtual sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection) = 0;

protected:
    static std::vector<sf::Vector2f> _frightenedTargets;

    sf::Vector2f _target;
    sf::Vector2f _frighetenedTarget;
    bool _isFrightened;
    int _lastVisitedX;
    int _lastVisitedY;
    bool _isStart;
};

class RedGhost : public Ghost
{
public:
    RedGhost(float x, float y, float speed, bool canStart);
    virtual sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);
};

class PinkGhost : public Ghost
{
public:
    PinkGhost(float x, float y, float speed, bool canStart);
    virtual sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);
};

class BlueGhost : public Ghost
{
public:
    BlueGhost(float x, float y, float speed, bool canStart);
    virtual sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);
};

class OrangeGhost : public Ghost
{
public:
    OrangeGhost(float x, float y, float speed, bool canStart);
    virtual sf::Vector2f getTarget(sf::Vector2f pacmanCoordinates, Direction pacmanDirection);
};