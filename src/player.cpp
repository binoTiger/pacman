#include "player.h"

using namespace sf;

Player::Player(String file, float x, float y)
    : _x(x), _y(y), _dx(0), _dy(0), _speed(0), _direction(Direction::RIGHT), _file(file), _currentFrame(0)
{
    _image.loadFromFile("../images/" + file);

    _texture.loadFromImage(_image);

    _sprite.setTexture(_texture);
    _sprite.setTextureRect(IntRect(0, 0, 30, 30));
}
Sprite Player::sprite()
{
    return _sprite;
}

Pacman::Pacman(String file, float x, float y)
    : Player(file, x, y), _score(0)
{
    _font.loadFromFile("../fonts/CrackMan.TTF");
    _text = Text("", _font, 40);
    _text.setFillColor(Color::Yellow);
    _text.setStyle(Text::Bold);
};
   
void Pacman::checkKeys(Event::KeyEvent& event, Map& map)
{
    switch (event.code)
    {
    case Keyboard::Right:
        if ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) + 1] == 1
            || map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) + 1] == 0)
            && ((int)_y % 30 == 0 || (int)_y % 30 == 1))
        {
            _direction = Direction::RIGHT;
            _speed = 0.1;
        }
        break;
    case Keyboard::Left:
        if ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) - 1] == 1
            || map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) - 1] == 0)
            && ((int)_y % 30 == 0 || (int)_y % 30 == 1))
        {
            _direction = Direction::LEFT;
            _speed = 0.1;
        }
        break;
    case Keyboard::Down:
        if ((map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] == 1
            || map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] == 0)
            && ((int)(_x - 540) % 30 == 0 || (int)(_x - 540) % 30 == 1))
        {
            _direction = Direction::DOWN;
            _speed = 0.1;
        }
        break;
    case Keyboard::Up:
        if ((map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] == 1
            || map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] == 0)
            && ((int)(_x - 540) % 30 == 0 || (int)(_x - 540) % 30 == 1))
        {
            _direction = Direction::UP;
            _speed = 0.1;
        }
        break;
    }
}
void Pacman::update(float time, Map& map)
{
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
    interactionWithMap(map);
    animate(time);
}

void Pacman::interactionWithMap(Map& map)
{
    for (int i = _y / 30; i < (_y + 28) / 30; i++)
    {
        for (int j = (_x - 540) / 30; j < (_x + 28 - 540) / 30; j++)
        {
            if ((map.tiles[i][j] != 0) && (map.tiles[i][j] != 1))
            {
                if (_dy > 0)
                {
                    _y = i * 30 - 30;
                }
                if (_dy < 0)
                {
                    _y = i * 30 + 30;
                }
                if (_dx > 0)
                {
                    _x = (j * 30) + 540 - 30;
                }
                if (_dx < 0)
                {
                    _x = (j * 30) + 540 + 30;
                }
            }
            if (map.tiles[i][j] == 1) {
                ++_score;
                map.tiles[i][j] = 0;
            }
        }
    }
}

void Pacman::animate(float time)
{
    if (_dx == 0 && _dy == 0)
        return;

    _currentFrame += 0.0035 * time;
    if (_currentFrame > 2)
        _currentFrame -= 2;

    switch (_direction)
    {
    case Direction::RIGHT:
        _sprite.setTextureRect(IntRect(0, 30 * int(_currentFrame), 30, 30));
        break;
    case Direction::LEFT:
        _sprite.setTextureRect(IntRect(29, 30 * int(_currentFrame), -29, 30));
        break;
    case Direction::DOWN:
        _sprite.setTextureRect(IntRect(30, 29 + 30 * int(_currentFrame), 30, -30));
        break;
    case Direction::UP:
        _sprite.setTextureRect(IntRect(30, 30 * int(_currentFrame), 30, 30));
        break;
    }
}

Text Pacman::score()
{
    std::ostringstream playerScore;
    playerScore << _score;
    _text.setString("SCORE: " + playerScore.str());
    _text.setPosition(545, 30);

    return _text;
}