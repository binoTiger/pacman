#include "pacman.h"

using namespace sf;

unsigned Pacman::_count = 0;

Pacman::Pacman(std::string color, std::string controlKeys, float x, float y, float speed)
    : Player(color + "Pacman.png", x, y, 0), _commonSpeed(speed), _score(0), _lives(3), _isImmortal(false), _immortalTimer(0), _isBoosted(false), _boostedTimer(0)
{
    _id = _count++;
    _font.loadFromFile("../fonts/CrackMan.TTF");
    _text = Text("", _font, 40);
    _text.setFillColor(Color::Yellow);
    _text.setStyle(Text::Bold);

    _lifesImage.loadFromFile("../images/PacmanLogo.png");
    _lifesImage.createMaskFromColor(Color::Green);
    _lifesTexture.loadFromImage(_lifesImage);
    _spriteOfLifes.setTexture(_lifesTexture);

    if (controlKeys == "arrows") {
        _controlKeys = { Keyboard::Right, Keyboard::Left, Keyboard::Down, Keyboard::Up };
        std::cout << "arrow";
    }
    if (controlKeys == "wasd") {
        _controlKeys = { Keyboard::D, Keyboard::A, Keyboard::S, Keyboard::W };
    }
};

void Pacman::checkKeys(const Map& map)
{
    if (Keyboard::isKeyPressed(_controlKeys[0])) {
        if (CanGoRight(map))
        {
            _direction = Direction::RIGHT;
            _speed = _commonSpeed;
        }
    }
    if (Keyboard::isKeyPressed(_controlKeys[1])) {
        if (CanGoLeft(map))
        {
            _direction = Direction::LEFT;
            _speed = _commonSpeed;
        }
    }
    if (Keyboard::isKeyPressed(_controlKeys[2])) {
        if (CanGoDown(map))
        {
            _direction = Direction::DOWN;
            _speed = _commonSpeed;
        }
    }
    if (Keyboard::isKeyPressed(_controlKeys[3])) {
        if (CanGoUp(map))
        {
            _direction = Direction::UP;
            _speed = _commonSpeed;
        }
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

    // 1 sec ~ 300
    if (_isImmortal) {
        _immortalTimer += time;
        if (_immortalTimer > 1500) {
            _isImmortal = false;
            _immortalTimer = 0;
        }
    }

    if (_isBoosted) {
        _speed = _commonSpeed + 0.03;
        _boostedTimer += time;
        if (_boostedTimer > 5000) {
            _isBoosted = false;
            _boostedTimer = 0;
            _speed = _commonSpeed;
        }
    }

    std::cout << _immortalTimer << _boostedTimer << "\n";

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
    _acceleration = Vector2f(_commonSpeed, 0);
    _speed = _commonSpeed;
}

Text Pacman::score()
{
    std::ostringstream playerScore;
    playerScore << _score;
    _text.setString("SCORE: " + playerScore.str());
    Vector2f position(545 + 560 * _id, 30);
    if (_id == 1 && _score > 1000) {
        position.x -= 40;
    }
    _text.setPosition(position);

    return _text;
}

unsigned Pacman::pointsEaten()
{
    return _pointsEaten;
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
    _spriteOfLifes.setPosition(545 + 680 * _id, 1030);

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
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30 + 1] >= 100000)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoLeft(const Map& map)
{
    return ((map.tiles[(int)(_y / 30)][(int)((_x - 540)) / 30 - 1] >= 100000)
        && ((int)_y % 30 <= 1));
}

bool Pacman::CanGoDown(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) + 1][(int)((_x - 540)) / 30] >= 100000)
        && ((int)(_x - 540) % 30 <= 1));
}

bool Pacman::CanGoUp(const Map& map)
{
    return ((map.tiles[(int)(_y / 30) - 1][(int)((_x - 540)) / 30] >= 100000)
        && ((int)(_x - 540) % 30 <= 1));
}

void Pacman::animate(float time)
{
    if (_acceleration == Vector2f(0, 0)) {
        _currentFrame = 0;
    }

    /*if (!_isImmortal) {
        _currentFrame += 0.0035 * time;
        if (_currentFrame >= 2) {
            _currentFrame = 0;
        }
    }
    else {
        _currentFrame += 0.007 * time;
        if (_currentFrame > 3) {
            _currentFrame = 0;
        }
    }*/
    if (_isImmortal) {
        _currentFrame += 0.007 * time;
        if (_currentFrame > 3) {
            _currentFrame = 0;
        }
    }
    else if (_isBoosted) {
        _currentFrame += 0.005 * time;
        if (_currentFrame >= 2) {
            _currentFrame = 0;
        }
    }
    else {
        _currentFrame += 0.0035 * time;
        if (_currentFrame >= 2) {
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
                ++_pointsEaten;
            }
        }
    }
}