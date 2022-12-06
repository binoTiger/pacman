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

    /*Pacman pacman("pacman.png", 945, 780);
    Ghost ghost1("ghost.png", 945, 420, 0.095);*/
    Pacman pacman("pacman.png", 945, 780);
    //Ghost ghost1(945, 420, 0.095);

    //Ghost ghost1(945, 420, 0.095);
    std::vector<Ghost*> ghostsVector;
    ghostsVector.push_back(new Ghost(945, 420, 0.095));

    Map map;

    Clock clock;
    int ghostsSpawnTimer = 0;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        ghostsSpawnTimer += time;
        clock.restart();
        time /= 800;

        if (ghostsSpawnTimer > 5000000 && Ghost::_count < 4) {
            ghostsVector.push_back(new Ghost(945, 420, 0.095));
            ghostsSpawnTimer = 0;
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
        //ghost1.update(time, pacman.getCoordinates(), pacman.getDirection(), pacman.isBoosted(), map);

        for (auto& ghost : ghostsVector) {
            (*ghost).update(time, pacman.getCoordinates(), pacman.getDirection(), pacman.isBoosted(), map);
        }

        for (auto& ghost : ghostsVector) {
            ghostAndPacmanInteraction(pacman, (*ghost));
        }

        //ghostAndPacmanInteraction(pacman, ghost1);

        if (pacman.getLifes() == 0)
        {
            window.close();
        }

        window.clear();

        map.drawMap(window);

        window.draw(pacman.score());
        window.draw(pacman.lifes());
        window.draw(pacman.sprite());
        //window.draw(ghost1.sprite());

        for (auto& ghost : ghostsVector) {
            window.draw((*ghost).sprite());
        }

        window.display();
    }

    return 0;
}