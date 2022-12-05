#include "pacman.h"

using namespace sf;

Pacman::Pacman(String file, float x, float y)
    : Player(file, x, y, 0), _score(0), _lives(3), _isImmortal(false), _isBoosted(false)
{
    _font.loadFromFile("../fonts/CrackMan.TTF");
    _text = Text("", _font, 40);
    _text.setFillColor(Color::Yellow);
    _text.setStyle(Text::Bold);

    _lifesImage.loadFromFile("../images/PacmanLogo.png");
    _lifesImage.createMaskFromColor(Color::Green);
    _lifesTexture.loadFromImage(_lifesImage);
    _spriteOfLifes.setTexture(_lifesTexture);
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

    if (distance(_x, 540) < 5 && distance(_y, 510) < 5) {
        _x = 1340;
        _y = 510;
    }
    if (distance(_x, 1350) < 5 && distance(_y, 510) < 5) {
        _x = 580;
        _y = 510;
    }

    if (_isImmortal) {
        _immortalTimer += time;
        if (_immortalTimer > 700) {
            _isImmortal = false;
            _immortalTimer = 0;
        }
    }

    if (_isBoosted) {
        _boostedTimer += time;
        if (_boostedTimer > 1600) {
            _isBoosted = false;
            _boostedTimer = 0;
        }
    }

    interactionWithMap(map);
    _sprite.setPosition(_x, _y);
    animate(time);
}

void Pacman::setStartCoordinates()
{
    _x = _startCoordinates.x;
    _y = _startCoordinates.y;
    _direction = Direction::RIGHT;
    _isImmortal = true;
}

Text Pacman::score()
{
    std::ostringstream playerScore;
    playerScore << _score;
    _text.setString("SCORE: " + playerScore.str());
    _text.setPosition(545, 30);

    return _text;
}

const unsigned Pacman::getLifes() const
{
    return _lives;
}

void Pacman::reduceLifes()
{
    --_lives;
}

Sprite Pacman::lifes()
{
    _spriteOfLifes.setTextureRect(IntRect(0, 0, 40 + (_lives - 1) * 55, 40));
    _spriteOfLifes.setPosition(545, 1030);

    return _spriteOfLifes;
}

const bool Pacman::isImmortal() const
{
    return _isImmortal;
}

const bool Pacman::isBoosted() const
{
    return _isBoosted;
}

void Pacman::increaseScoreIfEatGhost()
{
    _score += 200;
}

const Direction Pacman::getDirection() const
{
    return _direction;
}

bool Pacman::CanGoRight(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30 + 1] > 100)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoLeft(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30 - 1] > 100)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoDown(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] > 100)
        && ((int)(_x - 540) % 30 <= 1));
}

bool Pacman::CanGoUp(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] > 100)
        && ((int)(_x - 540) % 30 <= 1));
}

void Pacman::animate(float time)
{
    if (_acceleration == Vector2f(0, 0))
        return;

    if (!_isImmortal) {
        _currentFrame += 0.0035 * time;
        if (_currentFrame > 2) {
            _currentFrame = 0;
        }
    }
    else {
        _currentFrame += 0.007 * time;
        if (_currentFrame > 3) {
            _currentFrame = 0;
        }
    }

    switch (_direction)
    {
    case Direction::RIGHT:
        _sprite.setTextureRect(IntRect(0, 30 * int(_currentFrame), 30, 30));
        break;
    case Direction::LEFT:
        _sprite.setTextureRect(IntRect(29, 30 * int(_currentFrame), -29, 30));
        break;
    case Direction::DOWN:
        _sprite.setTextureRect(IntRect(30, 29 + 30 * int(_currentFrame), 30, -29));
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
                if (_acceleration.y > 0)
                {
                    _y = i * 30 - 30;
                }
                if (_acceleration.y < 0)
                {
                    _y = i * 30 + 30;
                }
                if (_acceleration.x > 0)
                {
                    _x = (j * 30) + 540 - 30;
                }
                if (_acceleration.x < 0)
                {
                    _x = (j * 30) + 540 + 30;
                }
            }
            if (map.tiles[i][j] >= 120000) {
                _score += 100;
                map.tiles[i][j] -= 20000;
                _isBoosted = true;
            }
            else if (map.tiles[i][j] >= 110000) {
                _score += 10;
                map.tiles[i][j] -= 10000;
            }
        }
    }
}
