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

    getDirection(map);

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
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) + 1] < 2)
        && ((int)_y % 30 <= 1) && _direction != Direction::LEFT);
}

bool Ghost::canGoLeft(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) - 1] < 2)
        && ((int)_y % 30 <= 1) && _direction != Direction::RIGHT);
}

bool Ghost::canGoDown(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] < 2)
        && ((int)(_x - 540) % 30 <= 1) && _direction != Direction::UP);
}

bool Ghost::canGoUp(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] < 2)
        && ((int)(_x - 540) % 30 <= 1) && _direction != Direction::DOWN);
}

void Ghost::getDirection(const Map& map)
{
    if (canGoRight(map) && canGoLeft(map) && !canGoDown(map) && !canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
        }
        else if (distance(_x + 30, _y, _target.first, _target.second) > distance(_x - 30, _y, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
        }
    }
    else if (canGoRight(map) && !canGoLeft(map) && canGoDown(map) && !canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
        }
        else if (distance(_x + 30, _y, _target.first, _target.second) > distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::DOWN;
        }
    }
    else if (canGoRight(map) && !canGoLeft(map) && !canGoDown(map) && canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
        }
        else if (distance(_x + 30, _y, _target.first, _target.second) > distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::UP;
        }
    }

    else if (!canGoRight(map) && canGoLeft(map) && canGoDown(map) && !canGoUp(map)) {
        if (distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
        }
        else if (distance(_x - 30, _y, _target.first, _target.second) > distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::DOWN;
        }
    }
    else if (!canGoRight(map) && canGoLeft(map) && !canGoDown(map) && canGoUp(map)) {
        if (distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
        }
        else if (distance(_x - 30, _y, _target.first, _target.second) > distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::UP;
        }
    }

    else if (!canGoRight(map) && !canGoLeft(map) && canGoDown(map) && canGoUp(map)) {
        if (distance(_x, _y + 30, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::DOWN;
        }
        else if (distance(_x - 30, _y, _target.first, _target.second) > distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::UP;
        }
    }

    else if (canGoRight(map) && canGoLeft(map) && canGoDown(map) && !canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second) &&
            distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
        }
        if (distance(_x - 30, _y, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
        }
        if (distance(_x, _y + 30, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x, _y + 30, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
        }
    }
    else if (canGoRight(map) && canGoLeft(map) && !canGoDown(map) && canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second) &&
            distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
        }
        if (distance(_x - 30, _y, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
        }
        if (distance(_x, _y - 30, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x, _y - 30, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::UP;
        }
    }
    else if (canGoRight(map) && !canGoLeft(map) && canGoDown(map) && canGoUp(map)) {
        if (distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second) &&
            distance(_x + 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
        }
        if (distance(_x, _y + 30, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x, _y + 30, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
        }
        if (distance(_x, _y - 30, _target.first, _target.second) <= distance(_x + 30, _y, _target.first, _target.second) &&
            distance(_x, _y - 30, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::UP;
        }
    }
    else if (!canGoRight(map) && canGoLeft(map) && canGoDown(map) && canGoUp(map)) {
        if (distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second) &&
            distance(_x - 30, _y, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
        }
        if (distance(_x, _y + 30, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second) &&
            distance(_x, _y + 30, _target.first, _target.second) <= distance(_x, _y - 30, _target.first, _target.second))
        {
            //if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
        }
        if (distance(_x, _y - 30, _target.first, _target.second) <= distance(_x - 30, _y, _target.first, _target.second) &&
            distance(_x, _y - 30, _target.first, _target.second) <= distance(_x, _y + 30, _target.first, _target.second))
        {
            //if (_direction != Direction::UP)
                _direction = Direction::UP;
        }
    }

    else if (canGoRight(map) && !canGoLeft(map) && !canGoDown(map) && !canGoUp(map)) {
        _direction = Direction::RIGHT;
    }
    else if (!canGoRight(map) && canGoLeft(map) && !canGoDown(map) && !canGoUp(map)) {
        _direction = Direction::LEFT;
    }
    else if (!canGoRight(map) && !canGoLeft(map) && canGoDown(map) && !canGoUp(map)) {
        _direction = Direction::DOWN;
    }
    else if (!canGoRight(map) && !canGoLeft(map) && !canGoDown(map) && canGoUp(map)) {
        _direction = Direction::UP;
    }
}