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

    Pacman pacman("pacman.png", 945, 780);
    Ghost ghost1("ghost.png", 945, 420);

    Map map;

    Clock clock;

    while (window.isOpen())
    {
        float time = clock.getElapsedTime().asMicroseconds();
        clock.restart();
        time /= 800;

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
        ghost1.update(time, pacman.getCoordinates(), pacman.isBoosted(), map);

        ghostAndPacmanInteraction(pacman, ghost1);

        if (pacman.getLifes() == 0)
        {
            window.close();
        }

        window.clear();

        map.drawMap(window);
        
        window.draw(pacman.score());
        window.draw(pacman.lifes());
        window.draw(pacman.sprite());
        window.draw(ghost1.sprite());
        
        window.display();
    }

    return 0;
}
