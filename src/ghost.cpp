#include "ghost.h"

using namespace sf;

Ghost::Ghost(String file, float x, float y)
    : Player(file, x, y)
{
    _direction = Direction::LEFT;
    _speed = 0.095;
    _dx = -_speed;
}

void Ghost::update(float time, const std::pair<float, float> coordinates, bool escape, Map& map)
{
    _target = coordinates;

    setDirection(map);

    switch (_direction)
    {
    case Direction::RIGHT:
        _dx = _speed;
        _dy = 0;
        break;
    case Direction::LEFT:
        _dx = -_speed;
        _dy = 0;
        break;
    case Direction::DOWN:
        _dx = 0;
        _dy = _speed;
        break;
    case Direction::UP:
        _dx = 0;
        _dy = -_speed;
        break;
    }

    _x += _dx * time;
    _y += _dy * time;

    _currentFrame += 0.0035 * time;
    if (_currentFrame > 2)
        _currentFrame -= 2;
    _sprite.setTextureRect(sf::IntRect(30 * int(_currentFrame), 0, 30, 30));

    _sprite.setPosition(_x, _y);
}

bool Ghost::canGoRight(const Map& map)
{
    return _direction != Direction::LEFT;
}

bool Ghost::canGoLeft(const Map& map)
{
    return _direction != Direction::RIGHT;
}

bool Ghost::canGoDown(const Map& map)
{
    return _direction != Direction::UP;
}

bool Ghost::canGoUp(const Map& map)
{
    return _direction != Direction::DOWN;
}

void Ghost::setDirection(const Map& map)
{
    unsigned ceil = map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30];

    bool goRight = (ceil % 10) && canGoRight(map);
    bool goLeft = ((ceil / 10) % 10) && canGoLeft(map);
    bool goDown = ((ceil / 100) % 10) && canGoDown(map);
    bool goUp = ((ceil / 1000) % 10) && canGoUp(map);

    std::map<float, Direction> distances;

    if (((int)_y % 30 == 0) && ((int)(_x - 540) % 30 == 0)) {
        if (goUp == 1 && canGoUp(map)) {
            float distanceIfGoUp = distance(_x, _y - 30, _target.first, _target.second);
            distances.insert(std::pair<float, Direction>(distanceIfGoUp, Direction::UP));
        }
        if (goLeft == 1 && canGoLeft(map)) {
            float distanceIfGoLeft = distance(_x - 30, _y, _target.first, _target.second);
            distances.insert(std::pair<float, Direction>(distanceIfGoLeft, Direction::LEFT));
        }
        if (goDown == 1 && canGoDown(map)) {
            float distanceIfGoDown = distance(_x, _y + 30, _target.first, _target.second);
            distances.insert(std::pair<float, Direction>(distanceIfGoDown, Direction::DOWN));
        }
        if (goRight == 1 && canGoRight(map)) {
            float distanceIfGoRight = distance(_x + 30, _y, _target.first, _target.second);
            distances.insert(std::pair<float, Direction>(distanceIfGoRight, Direction::RIGHT));
        }
        _direction = (*distances.begin()).second;
    }
}