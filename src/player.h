#pragma once
#include <SFML/Graphics.hpp>
#include <sstream>

#include "map.h"

enum class Direction
{
    RIGHT,
    LEFT,
    DOWN,
    UP
};

class Player
{
public:
    Player(sf::String file, float x, float y);
    sf::Sprite sprite();

protected:
    float _x, _y;
    float _dx, _dy;
    float _speed;
    Direction _direction;
    sf::String _file;
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _currentFrame;
};

class Pacman : public Player
{
public:
    Pacman(sf::String file, float x, float y);

    void checkKeys(const sf::Event::KeyEvent& event, const Map& map);
    void update(float time, Map& map);
    sf::Text score();
    const std::pair<float, float> coordinates() const;

private:
    bool CanGoRight(const Map& map);
    bool CanGoLeft(const Map& map);
    bool CanGoDown(const Map& map);
    bool CanGoUp(const Map& map);
    void interactionWithMap(Map& map);
    void animate(float time);

private:
    int _score;
    sf::Font _font;
    sf::Text _text;
};

#include <iostream>
class Ghost : public Player
{
public:
    Ghost(sf::String file, float x, float y)
        : Player(file, x, y)
    {
        _direction = Direction::LEFT;
        _speed = 0.1;
        _dx = -_speed;

        /*_targets.push_back(std::pair<float, float>(7 * 30 + 540, 25 * 30));
        _targets.push_back(std::pair<float, float>(3 * 30 + 540, 33 * 30));
        _targets.push_back(std::pair<float, float>(27 * 30 + 540, 12 * 30));
        _targets.push_back(std::pair<float, float>(8 * 30 + 540, 9 * 30));

        _num = 0;*/
    }
    void update(float time, const Pacman& pacman, Map& map)
    {
        _target = pacman.coordinates();
        //_target = _targets[_num];

        /*if ((_x - _target.first == 0 && _y - _target.second == 0) ||
            (_x - _target.first == 0 && _y - _target.second == 1) ||
            (_x - _target.first == 1 && _y - _target.second == 0) ||
            (_x - _target.first == 1 && _y - _target.second == 1))
        {
            ++_num;
        }

        if (_num == 4) {
            _num = 0;
        }*/

        /*if (!CanGoUp(map)) {
            if (CanGoRight(map) && !CanGoLeft(map)) {
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            if (!CanGoRight(map) && CanGoLeft(map)) {
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            if (CanGoRight(map) && CanGoLeft(map)) {
                if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <
                    sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2))) 
                {
                    _direction = Direction::RIGHT;
                    _speed = 0.1;
                }
                if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                    sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)))
                {
                    _direction = Direction::RIGHT;
                    _speed = 0.1;
                }
            }
        }
        if (!CanGoDown(map)) {
            if (CanGoRight(map) && !CanGoLeft(map)) {
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            if (!CanGoRight(map) && CanGoLeft(map)) {
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            if (CanGoRight(map) && CanGoLeft(map)) {
                if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <
                    sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)))
                {
                    _direction = Direction::RIGHT;
                    _speed = 0.1;
                }
                if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                    sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)))
                {
                    _direction = Direction::RIGHT;
                    _speed = 0.1;
                }
            }
        }
        if (!CanGoRight(map)) {
            if (CanGoDown(map) && !CanGoUp(map)) {
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
            if (!CanGoDown(map) && CanGoUp(map)) {
                _direction = Direction::UP;
                _speed = 0.1;
            }
            if (CanGoDown(map) && CanGoUp(map)) {
                if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <
                    sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
                {
                    _direction = Direction::DOWN;
                    _speed = 0.1;
                }
                if (sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                    sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
                {
                    _direction = Direction::UP;
                    _speed = 0.1;
                }
            }
        }
        if (!CanGoLeft(map)) {
            if (CanGoDown(map) && !CanGoUp(map)) {
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
            if (!CanGoDown(map) && CanGoUp(map)) {
                _direction = Direction::UP;
                _speed = 0.1;
            }
            if (CanGoDown(map) && CanGoUp(map)) {
                if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <
                    sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
                {
                    _direction = Direction::DOWN;
                    _speed = 0.1;
                }
                if (sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                    sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
                {
                    _direction = Direction::UP;
                    _speed = 0.1;
                }
            }
        }*/

        if (CanGoRight(map) && !CanGoLeft(map) && !CanGoDown(map) && !CanGoUp(map)) {
            _direction = Direction::RIGHT;
            _speed = 0.1;
        }
        else if (!CanGoRight(map) && CanGoLeft(map) && !CanGoDown(map) && !CanGoUp(map)) {
            _direction = Direction::LEFT;
            _speed = 0.1;
        }
        else if (!CanGoRight(map) && !CanGoLeft(map) && CanGoDown(map) && !CanGoUp(map)) {
            _direction = Direction::DOWN;
            _speed = 0.1;
        }
        else if (!CanGoRight(map) && !CanGoLeft(map) && !CanGoDown(map) && CanGoUp(map)) {
            _direction = Direction::UP;
            _speed = 0.1;
        }

        else if (CanGoRight(map) && CanGoLeft(map) && !CanGoDown(map) && !CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <= 
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) >
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
        }
        else if (CanGoRight(map) && !CanGoLeft(map) && CanGoDown(map) && !CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) >
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
        }
        else if (CanGoRight(map) && !CanGoLeft(map) && !CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) >
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }

        else if (!CanGoRight(map) && CanGoLeft(map) && CanGoDown(map) && !CanGoUp(map)) {
            if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) >
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
        }
        else if (!CanGoRight(map) && CanGoLeft(map) && !CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) >
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }

        else if (!CanGoRight(map) && !CanGoLeft(map) && CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
            else if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) >
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }

        else if (CanGoRight(map) && CanGoLeft(map) && CanGoDown(map) && !CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
        }
        else if (CanGoRight(map) && CanGoLeft(map) && !CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }
        else if (CanGoRight(map) && !CanGoLeft(map) && CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) &&
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::RIGHT)
                _direction = Direction::RIGHT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x + 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }
        else if (!CanGoRight(map) && CanGoLeft(map) && CanGoDown(map) && CanGoUp(map)) {
            if (sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) &&
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::LEFT)
                _direction = Direction::LEFT;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)))
            {
                if (_direction != Direction::DOWN)
                _direction = Direction::DOWN;
                _speed = 0.1;
            }
            if (sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x - 30 - _target.first), 2) + pow((_y - _target.second), 2)) &&
                sqrt(pow((_x - _target.first), 2) + pow((_y - 30 - _target.second), 2)) <=
                sqrt(pow((_x - _target.first), 2) + pow((_y + 30 - _target.second), 2)))
            {
                if (_direction != Direction::UP)
                _direction = Direction::UP;
                _speed = 0.1;
            }
        }

        /*if (CanGoRight(map) && _direction != Direction::LEFT)
        {
            if (sqrt(_x + 30 - _target.first))
            _direction = Direction::RIGHT;
            _speed = 0.1;
        }
        if (CanGoLeft(map) && _direction != Direction ::RIGHT)
        {
            _direction = Direction::LEFT;
            _speed = 0.1;
        }
        if (CanGoDown(map) && _direction != Direction::UP)
        {
            _direction = Direction::DOWN;
            _speed = 0.1;
        }
        if (CanGoUp(map) && _direction != Direction::DOWN)
        {
            _direction = Direction::UP;
            _speed = 0.1;
        }*/

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

        _sprite.setPosition(_x, _y);
    }
private:
    bool CanGoRight(const Map& map);
    bool CanGoLeft(const Map& map);
    bool CanGoDown(const Map& map);
    bool CanGoUp(const Map& map);
private:
    std::vector<std::pair<float, float>> _targets;
    std::pair<float, float> _target;
    //int _num;
};