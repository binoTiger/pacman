#include <SFML/Graphics.hpp>

#include "map.h"
#include "player.h"
#include "menu.h"

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;

int main()
{
    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);


    Menu menu;
    menu.drawMenu(window);

    Pacman pacman("pacman.png", 945, 780);

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

        window.clear();

        map.drawMap(window);
        
        window.draw(pacman.score());
        window.draw(pacman.sprite());
        
        window.display();
    }

    return 0;
}
