#include <SFML/Graphics.hpp>

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "menu.h"
#include "gameInteraction.h"

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);

    Menu menu;
    menu.drawMenu(window);
    window.clear();

    Pacman pacman("pacman.png", 945, 780);

    std::vector<Ghost*> ghostsVector;
    if (menu.selectedMode() != GameMode::TRAINING) {
        ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 14 * 30, 0.095, true));
        ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 17 * 30, 0.095, false));
        ghostsVector.push_back(new Ghost(11 * 30 + 540 + 15, 17 * 30, 0.095, false));
        ghostsVector.push_back(new Ghost(15 * 30 + 540 + 15, 17 * 30, 0.095, false));
    }

    Map map;

    Clock clock;
    int ghostsSpawnTimer = 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

        if (menu.selectedMode() != GameMode::TRAINING) {
            if (!ghostsVector[1]->isStart()) {
                ghostsSpawnTimer += time;
            }
            if (ghostsSpawnTimer > 2000000 && !ghostsVector[1]->isStart()) {
                ghostsVector[1]->start();
                ghostsSpawnTimer = 0;
            }
            if (!ghostsVector[2]->isStart() && pacman.pointsEaten() > 30) {
                ghostsVector[2]->start();
            }
            if (!ghostsVector[3]->isStart() && pacman.pointsEaten() > 80) {
                ghostsVector[3]->start();
            }
        }     

        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed || Keyboard::isKeyPressed(Keyboard::Escape))
                window.close();
        }

        if (event.type == Event::KeyPressed)
        {
            pacman.checkKeys(event.key, map);
        }

        pacman.update(time, map);

        for (auto& ghost : ghostsVector) {
            (*ghost).update(time, pacman.getCoordinates(), pacman.getDirection(), pacman.isBoosted(), map);
        }

        for (auto& ghost : ghostsVector) {
            ghostAndPacmanInteraction(pacman, (*ghost));
        }

        if (pacman.getLifes() == 0)
        {
            window.close();
        }

        window.clear();

        map.drawMap(window);

        window.draw(pacman.score());
        window.draw(pacman.lifes());
        window.draw(pacman.sprite());

        for (auto& ghost : ghostsVector) {
            window.draw((*ghost).sprite());
        }

        window.display();
    }

    return 0;
}