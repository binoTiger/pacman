#pragma once
#include "player.h"

class Pacman : public Player
{
public:
    Pacman(sf::String file, float x, float y);

    void checkKeys(const sf::Event::KeyEvent& event, const Map& map);
    void update(float time, Map& map);
    void setStartCoordinates();
    sf::Text score();
    unsigned pointsEaten();
    const unsigned getLifes() const;
    void reduceLifes();
    sf::Sprite lifes();
    const bool isImmortal() const;
    const bool isBoosted() const;
    void increaseScoreIfEatGhost();
    const Direction getDirection() const;

private:
    bool CanGoRight(const Map& map);
    bool CanGoLeft(const Map& map);
    bool CanGoDown(const Map& map);
    bool CanGoUp(const Map& map);
    void interactionWithMap(Map& map);
    void animate(float time);

private:
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
};
