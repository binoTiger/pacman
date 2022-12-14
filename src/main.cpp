#include <SFML/Graphics.hpp>

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "menu.h"
#include "gameInteraction.h"

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;

//int main()
//{
//    RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);
//
//    Menu menu;
//    menu.drawMenu(window);
//    window.clear();
//
//    auto mode = menu.selectedMode();
//
//    std::vector<Pacman*> pacmanVector;
//    if (mode != GameMode::DUO) {
//        pacmanVector.push_back(new Pacman(menu.playersParameters()[1], menu.playersParameters()[2], 945, 780, 0.1));
//    }
//    else {
//        pacmanVector.push_back(new Pacman(menu.playersParameters()[1], menu.playersParameters()[2], 925, 780, 0.1));
//        pacmanVector.push_back(new Pacman(menu.playersParameters()[4], menu.playersParameters()[5], 965, 780, 0.1));
//    }
//
//    std::vector<Ghost*> ghostsVector;
//    if (mode != GameMode::TRAINING) {
//        ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 14 * 30, 0.095, true));
//        ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 17 * 30, 0.095, false));
//        ghostsVector.push_back(new Ghost(11 * 30 + 540 + 15, 17 * 30, 0.095, false));
//        ghostsVector.push_back(new Ghost(15 * 30 + 540 + 15, 17 * 30, 0.095, false));
//    }
//
//    Map map;
//
//    Clock clock;
//
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time /= 800;
//
//        int pointsEaten = 0;
//        for (auto& player : pacmanVector) {
//            pointsEaten += player->pointsEaten();
//        }
//
//        if (mode != GameMode::TRAINING) {
//            if (!ghostsVector[1]->isStart()) {
//                ghostsVector[1]->start();
//            }
//            if (!ghostsVector[2]->isStart() && pointsEaten > 30) {
//                ghostsVector[2]->start();
//            }
//            if (!ghostsVector[3]->isStart() && pointsEaten > 80) {
//                ghostsVector[3]->start();
//            }
//        }     
//
//        Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == Event::Closed) {
//                window.close();
//            }
//            if (Keyboard::isKeyPressed(Keyboard::Escape)) {
//                window.close();
//            }
//        }
//
//        for (auto& player : pacmanVector) {
//            player->checkKeys(map);
//        }
//        for (auto& player : pacmanVector) {
//            player->update(time, map);
//        }
//        
//        if (mode == GameMode::SINGLE) {
//            for (auto& ghost : ghostsVector) {
//                (*ghost).update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted(), map);
//            }
//
//            for (auto& ghost : ghostsVector) {
//                ghostAndPacmanInteraction((*pacmanVector[0]), (*ghost));
//            }
//        }
//        if (mode == GameMode::DUO) {
//            ghostsVector[0]->update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
//            ghostsVector[1]->update(time, pacmanVector[1]->getCoordinates(), pacmanVector[1]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
//            ghostsVector[2]->update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
//            ghostsVector[3]->update(time, pacmanVector[1]->getCoordinates(), pacmanVector[1]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
//
//            for (auto& ghost : ghostsVector) {
//                ghostAndPacmanInteraction((*pacmanVector[0]), (*pacmanVector[1]), (*ghost));
//            }
//
//            pacmanAndPacmanInteraction((*pacmanVector[0]), (*pacmanVector[1]));
//        }
//
//        window.clear();
//
//        map.drawMap(window);
//
//        for (auto& player : pacmanVector) {
//            window.draw(player->score());
//        }
//        for (auto& player : pacmanVector) {
//            window.draw(player->lifes());
//        }
//        for (auto& player : pacmanVector) {
//            window.draw(player->sprite());
//        }
//
//        for (auto& ghost : ghostsVector) {
//            window.draw((*ghost).sprite());
//        }
//
//        window.display();
//    }
//
//    return 0;
//}

#include "cScreen.h"
#include "screen_0.h"
#include "screen_1.h"
#include "screen_2.h"
#include "screen_3.h"
#include "screen_4.h"
#include "screen_5.h"
#include "screen_6.h"

int main(int argc, char** argv)
{
	//Applications variables
	std::vector<cScreen*> Screens;
	int screen = 0;

	//Window creation
	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);

	//Screens preparations
	menu_0 s0;
	Screens.push_back(&s0);
	menu_1 s1;
	Screens.push_back(&s1);
	menu_2 s2;
	Screens.push_back(&s2);
	game_screen_single s3;
	Screens.push_back(&s3);
	game_screen_duo s4;
	Screens.push_back(&s4);
	game_screen_training s5;
	Screens.push_back(&s5);
	pauseMenu s6;
	Screens.push_back(&s6);



	//Main loop
	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);
	}

	return EXIT_SUCCESS;
}