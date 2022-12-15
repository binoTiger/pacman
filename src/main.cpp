#include <SFML/Graphics.hpp>

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "menu.h"
#include "gameInteraction.h"

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;

#include "cScreen.h"
#include "screen_0.h"
#include "screen_1.h"
#include "screen_2.h"
#include "screen_3.h"
#include "screen_4.h"
#include "screen_5.h"
#include "screen_6.h"
#include "screen_7.h"
#include "screen_8.h"

int main(int argc, char** argv)
{
	std::vector<cScreen*> Screens;
	int screen = 0;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(144);

	menu_0 s0;
	Screens.push_back(&s0);
	menu_1 s1;
	Screens.push_back(&s1);
	menu_2 s2;
	Screens.push_back(&s2);
	gameScreenSingle s3;
	Screens.push_back(&s3);
	gameScreenDuo s4;
	Screens.push_back(&s4);
	gameScreenTraining s5;
	Screens.push_back(&s5);
	pauseMenu s6;
	Screens.push_back(&s6);
	gameOverSingle s7;
	Screens.push_back(&s7);
	gameOverDuo s8;
	Screens.push_back(&s8);

	while (screen >= 0)
	{
		screen = Screens[screen]->Run(window);

		if (!cScreen::_isGameStart) {
			(*Screens[3]).clear();
			(*Screens[4]).clear();
			(*Screens[5]).clear();
		}
	}

	return EXIT_SUCCESS;
}