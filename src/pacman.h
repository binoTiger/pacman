#pragma once
#include "player.h"

class Pacman : public Player
{
public:
    Pacman(std::string color, std::string controlKeys, float x, float y, float speed);

    void checkKeys(const Map& map);
    void update(float time, Map& map);
    void restart();
    void newLevel(float speed);
    unsigned pointsEaten();
    const unsigned getLifes() const;
    void reduceLifes();
    const bool isImmortal() const;
    const bool isBoosted() const;
    void increaseScoreIfEatGhost();
    const Direction getDirection() const;

    virtual sf::Text score() = 0;
    virtual sf::Sprite lifes() = 0;

protected:
    bool CanGoRight(const Map& map);
    bool CanGoLeft(const Map& map);
    bool CanGoDown(const Map& map);
    bool CanGoUp(const Map& map);
    void interactionWithMap(Map& map);
    void animate(float time);

protected:
    unsigned _score;
    unsigned _pointsEaten;
    sf::Font _font;
    sf::Text _text;
    unsigned _lives;
    sf::Image _lifesImage;
    sf::Texture _lifesTexture;
    sf::Sprite _spriteOfLifes;
    bool _isImmortal;
    int _immortalTimer;
    bool _isBoosted;
    int _boostedTimer;
    std::vector<sf::Keyboard::Key> _controlKeys;
};

class Pacman1 : public Pacman
{
public:
    Pacman1(std::string color, std::string controlKeys, float x, float y, float speed);

    virtual sf::Text score();
    virtual sf::Sprite lifes();
};

class Pacman2 : public Pacman
{
public:
    Pacman2(std::string color, std::string controlKeys, float x, float y, float speed);

    virtual sf::Text score();
    virtual sf::Sprite lifes();
};