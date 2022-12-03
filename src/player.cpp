#include "player.h"

using namespace sf;

Player::Player(String file, float x, float y)
    : _x(x), _y(y), _dx(0), _dy(0), _speed(0), _direction(Direction::RIGHT), _file(file), _currentFrame(0)
{
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

const std::pair<float, float> Player::getCoordinates() const
{
    return std::make_pair(_x, _y);
}

float Player::distance(float x1, float y1, float x2, float y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

float Player::distance(float coordinate1, float coordinate2) {
    return abs(coordinate1 - coordinate2);
}
