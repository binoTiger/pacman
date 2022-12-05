#include "player.h"

using namespace sf;

Player::Player(String file, float x, float y)
    : _x(x), _y(y), _acceleration(0, 0), _speed(0), _direction(Direction::RIGHT), _file(file), _currentFrame(0)
{
    _startCoordinates = Vector2f(_x, _y);

    _image.loadFromFile("../images/" + file);
    _image.createMaskFromColor(Color::Green);

    _texture.loadFromImage(_image);

    _sprite.setTexture(_texture);
    _sprite.setTextureRect(IntRect(0, 0, 30, 30));
}

Sprite Player::sprite()
{
    return _sprite;
}

const Vector2f Player::getCoordinates() const
{
    return Vector2f(_x, _y);
}

float Player::distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

float Player::distance(float coordinate1, float coordinate2) {
    return abs(coordinate1 - coordinate2);
}

float Player::distance(sf::Vector2f coordinates1, sf::Vector2f coordinates2)
{
    return sqrt(pow((coordinates1.x - coordinates2.x), 2) + pow((coordinates1.y - coordinates2.y), 2));
}

float Player::distance(float x1, float y1, sf::Vector2f coordinates2)
{
    return sqrt(pow((x1 - coordinates2.x), 2) + pow((y1 - coordinates2.y), 2));
}
