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
    const sf::Vector2f getCoordinates() const;
    static float distance(float x1, float y1, float x2, float y2);
    static float distance(float coordinate1, float coordinate2);
    static float distance(sf::Vector2f coordinates1, sf::Vector2f coordinates2);
    static float distance(float x1, float y1, sf::Vector2f coordinates2);

protected:
    float _x, _y;
    sf::Vector2f _startCoordinates;
    sf::Vector2f _acceleration;
    float _speed;
    Direction _direction;
    sf::String _file;
    sf::Image _image;
    sf::Texture _texture;
    sf::Sprite _sprite;
    float _currentFrame;
};
