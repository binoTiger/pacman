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

    void checkKeys(sf::Event::KeyEvent& event, Map& map);
    void update(float time, Map& map);
    sf::Text score();

private:
    void interactionWithMap(Map& map);
    void animate(float time);

private:
    int _score;
    sf::Font _font;
    sf::Text _text;
};
