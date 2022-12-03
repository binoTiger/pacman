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
    const unsigned getLives() const;
    void reduceLives();

private:
    bool CanGoRight(const Map& map);
    bool CanGoLeft(const Map& map);
    bool CanGoDown(const Map& map);
    bool CanGoUp(const Map& map);
    void interactionWithMap(Map& map);
    void animate(float time);

private:
    std::pair<float, float> _startCoordinates;
    unsigned _score;
    sf::Font _font;
    sf::Text _text;
    unsigned _lives;
};
