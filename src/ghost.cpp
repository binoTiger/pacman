#include "../include/ghost.h"

using namespace sf;

std::vector<Vector2f> Ghost::_frightenedTargets = { Vector2f(23 * 30 + 540, 4 * 30), Vector2f(4 * 30 + 540, 4 * 30), Vector2f(25 * 30 + 540, 32 * 30), Vector2f(1 * 30 + 540, 29 * 30) };

Ghost::Ghost(String imageName, float x, float y, float speed, bool canStart)
    : Player(imageName, x, y, speed), _isFrightened(true), _isStart(canStart)
{
    _startCoordinates = Vector2f(945, 420);

    _direction = Direction::LEFT;

    _acceleration = Vector2f(-_commonSpeed, 0);

    _lastVisitedX = (int)((_x - 540)) / 30;
    _lastVisitedY = (int)(_y / 30);
}

void Ghost::update(float time, const Vector2f pacmanCoordinates, Direction pacmanDirection, bool isFrightened, Map& map)
{
    _isFrightened = isFrightened;

    if (_isStart) {
        _target = getTarget(pacmanCoordinates, pacmanDirection);

        setDirection(map);

        if (_isFrightened) {
            _speed = _commonSpeed - 0.015;
        }
        else {
            _speed = _commonSpeed;
        }

        switch (_direction)
        {
        case Direction::RIGHT:
            _acceleration = Vector2f(_speed, 0);
            break;
        case Direction::LEFT:
            _acceleration = Vector2f(-_speed, 0);
            break;
        case Direction::DOWN:
            _acceleration = Vector2f(0, _speed);
            break;
        case Direction::UP:
            _acceleration = Vector2f(0, -_speed);
            break;
        }

        _x += _acceleration.x * time;
        _y += _acceleration.y * time;
    }

    _sprite.setPosition(_x, _y);
    animate(time);
}

void Ghost::setStartCoordinates()
{
    _x = _startCoordinates.x;
    _y = _startCoordinates.y;
    _direction = Direction::LEFT;
}

bool Ghost::isStart()
{
    return _isStart;
}

void Ghost::start()
{
    _isStart = true;
}

bool Ghost::isFrightened()
{
    return _isFrightened;
}

bool Ghost::canGoRight(const Map& map)
{
    return _direction != Direction::LEFT && ((int)((_x - 540) / 30 + 1) != _lastVisitedX);
}

bool Ghost::canGoLeft(const Map& map)
{
    return _direction != Direction::RIGHT && ((int)((_x - 540) / 30 - 1) != _lastVisitedX);
}

bool Ghost::canGoDown(const Map& map)
{
    return _direction != Direction::UP && ((int)(_y / 30 + 1) != _lastVisitedY);
}

bool Ghost::canGoUp(const Map& map)
{
    return _direction != Direction::DOWN && ((int)(_y / 30 - 1) != _lastVisitedY);
}

void Ghost::setDirection(const Map& map)
{
    unsigned ceil = map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30];

    std::map<float, Direction> distances;

    if (((int)_y % 30 == 0) && ((int)(_x - 540) % 30 == 0)) {
        bool goRight = (ceil % 10) && canGoRight(map);
        bool goLeft = ((ceil / 10) % 10) && canGoLeft(map);
        bool goDown = ((ceil / 100) % 10) && canGoDown(map);
        bool goUp = ((ceil / 1000) % 10) && canGoUp(map);

        if (goUp) {
            float distanceIfGoUp = distance(_x, _y - 30, _target);
            distances.insert(std::pair<float, Direction>(distanceIfGoUp, Direction::UP));
        }
        if (goLeft) {
            float distanceIfGoLeft = distance(_x - 30, _y, _target);
            distances.insert(std::pair<float, Direction>(distanceIfGoLeft, Direction::LEFT));
        }
        if (goDown) {
            float distanceIfGoDown = distance(_x, _y + 30, _target);
            distances.insert(std::pair<float, Direction>(distanceIfGoDown, Direction::DOWN));
        }
        if (goRight) {
            float distanceIfGoRight = distance(_x + 30, _y, _target);
            distances.insert(std::pair<float, Direction>(distanceIfGoRight, Direction::RIGHT));
        }

        _direction = (*distances.begin()).second;
        _lastVisitedX = (int)((_x - 540)) / 30;
        _lastVisitedY = (int)(_y / 30);
    }
}

void Ghost::animate(float time)
{
    if (!_isFrightened || !_isStart) {
        _currentFrame += 0.0035 * time;
        if (_currentFrame > 2)
            _currentFrame = 0;
        _sprite.setTextureRect(sf::IntRect(30 * int(_currentFrame), 0, 30, 30));
    }
    else {
        _currentFrame += 0.0055 * time;
        if (_currentFrame > 4)
            _currentFrame = 0;
        _sprite.setTextureRect(sf::IntRect(30 * int(_currentFrame), 30, 30, 30));
    }
}

RedGhost::RedGhost(float x, float y, float speed, bool canStart)
    : Ghost("ghost0.png", x, y, speed, canStart)
{
    _frighetenedTarget = _frightenedTargets[0];
}

Vector2f RedGhost::getTarget(Vector2f pacmanCoordinates, Direction pacmanDirection)
{
    if (_isFrightened) {
        return _frighetenedTarget;
    }

    return pacmanCoordinates;
}

PinkGhost::PinkGhost(float x, float y, float speed, bool canStart)
    : Ghost("ghost1.png", x, y, speed, canStart)
{
    _frighetenedTarget = _frightenedTargets[1];
}

Vector2f PinkGhost::getTarget(Vector2f pacmanCoordinates, Direction pacmanDirection)
{
    if (_isFrightened) {
        return _frighetenedTarget;
    }

    switch (pacmanDirection)
    {
    case Direction::RIGHT:
        return pacmanCoordinates + Vector2f(120, 0);
    case Direction::LEFT:
        return pacmanCoordinates + Vector2f(-120, 0);
    case Direction::DOWN:
        return pacmanCoordinates + Vector2f(0, 120);
    case Direction::UP:
        return pacmanCoordinates + Vector2f(0, -120);
    }
}

BlueGhost::BlueGhost(float x, float y, float speed, bool canStart)
    : Ghost("ghost2.png", x, y, speed, canStart)
{
    _frighetenedTarget = _frightenedTargets[2];
}

Vector2f BlueGhost::getTarget(Vector2f pacmanCoordinates, Direction pacmanDirection)
{
    if (_isFrightened) {
        return _frighetenedTarget;
    }

    switch (pacmanDirection)
    {
    case Direction::RIGHT:
        return pacmanCoordinates + Vector2f(60, 0);
    case Direction::LEFT:
        return pacmanCoordinates + Vector2f(-60, 0);
    case Direction::DOWN:
        return pacmanCoordinates + Vector2f(0, 60);
    case Direction::UP:
        return pacmanCoordinates + Vector2f(0, -60);
    }
}

OrangeGhost::OrangeGhost(float x, float y, float speed, bool canStart)
    : Ghost("ghost3.png", x, y, speed, canStart)
{
    _frighetenedTarget = _frightenedTargets[3];
}

Vector2f OrangeGhost::getTarget(Vector2f pacmanCoordinates, Direction pacmanDirection)
{
    if (_isFrightened) {
        return _frighetenedTarget;
    }

    if (distance(_x, _y, pacmanCoordinates) > 350) {
        return pacmanCoordinates;
    }
    else {
        return _frighetenedTarget;
    }
}