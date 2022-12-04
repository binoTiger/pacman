#include "pacman.h"

using namespace sf;

Pacman::Pacman(String file, float x, float y)
    : Player(file, x, y), _score(0), _lives(3), _isBoosted(false)
{
    _startCoordinates = std::make_pair(x, y);
    _font.loadFromFile("../fonts/CrackMan.TTF");
    _text = Text("", _font, 40);
    _text.setFillColor(Color::Yellow);
    _text.setStyle(Text::Bold);
};

void Pacman::checkKeys(const Event::KeyEvent& event, const Map& map)
{
    switch (event.code)
    {
    case Keyboard::Right:
        if (CanGoRight(map))
        {
            _direction = Direction::RIGHT;
            _speed = 0.1;
        }
        break;
    case Keyboard::Left:
        if (CanGoLeft(map))
        {
            _direction = Direction::LEFT;
            _speed = 0.1;
        }
        break;
    case Keyboard::Down:
        if (CanGoDown(map))
        {
            _direction = Direction::DOWN;
            _speed = 0.1;
        }
        break;
    case Keyboard::Up:
        if (CanGoUp(map))
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

    if (distance(_x, 540) < 5 && distance(_y, 510) < 5) {
        _x = 1340;
        _y = 510;
    }
    if (distance(_x, 1350) < 5 && distance(_y, 510) < 5) {
        _x = 580;
        _y = 510;
    }

    interactionWithMap(map);
    _sprite.setPosition(_x, _y);
    animate(time);
}

void Pacman::setStartCoordinates()
{
    _x = _startCoordinates.first;
    _y = _startCoordinates.second;
    _direction = Direction::RIGHT;
    _speed = 0.1;
}

Text Pacman::score()
{
    std::ostringstream playerScore;
    playerScore << _score;
    _text.setString("SCORE: " + playerScore.str());
    _text.setPosition(545, 30);

    return _text;
}

const unsigned Pacman::getLives() const
{
    return _lives;
}

void Pacman::reduceLives()
{
    --_lives;
}

const bool Pacman::isBoosted() const
{
    return _isBoosted;
}

bool Pacman::CanGoRight(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) + 1] <= 5)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoLeft(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540) / 30) - 1] <= 5)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoDown(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] == 1
        || map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] == 0)
        && ((int)(_x - 540) % 30 <= 1));
}

bool Pacman::CanGoUp(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] == 1
        || map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] == 0)
        && ((int)(_x - 540) % 30 <= 1));
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

void Pacman::interactionWithMap(Map& map)
{
    for (int i = _y / 30; i < (_y + 28) / 30; i++)
    {
        for (int j = (_x - 540) / 30; j < (_x + 28 - 540) / 30; j++)
        {
            if (map.tiles[i][j] > 10 && map.tiles[i][j] < 100)
            {
                _speed = 0;
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
                _score += 10;
                map.tiles[i][j] = 0;
            }
            if (map.tiles[i][j] >= 110000) {
                _score += 10;
                map.tiles[i][j] -= 10000;
            }
        }
    }
}
