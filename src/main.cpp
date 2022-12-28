#include <SFML/Graphics.hpp>

#include "../include/map.h"
#include "../include/pacman.h"
#include "../include/ghost.h"
#include "../include/gameInteraction.h"

using namespace sf;

constexpr unsigned WINDOW_WIDTH = 1920;
constexpr unsigned WINDOW_HEIGHT = 1080;

#include "../include/cScreen.h"
#include "../include/startMenuScreen.h"
#include "../include/selectGameModeScreen.h"
#include "../include/settingsMenuScreen.h"
#include "../include/singlePlayerScreen.h"
#include "../include/duoPlayerScreen.h"
#include "../include/trainingScreen.h"
#include "../include/pauseMenuScreen.h"
#include "../include/gameOverSingleScreen.h"
#include "../include/gameOverDuoScreen.h"

int main(int argc, char** argv)
{
	std::vector<cScreen*> screens;
	int screen = 0;

	RenderWindow window(VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "pacman", Style::Fullscreen);
	window.setKeyRepeatEnabled(true);
	window.setFramerateLimit(144);

	startMenu s0;
	screens.push_back(&s0);
	selectGameMode s1;
	screens.push_back(&s1);
	settingsMenu s2;
	screens.push_back(&s2);
	singlePlayer s3;
	screens.push_back(&s3);
	duoPlayer s4;
	screens.push_back(&s4);
	training s5;
	screens.push_back(&s5);
	pauseMenu s6;
	screens.push_back(&s6);
	gameOverSingle s7;
	screens.push_back(&s7);
	gameOverDuo s8;
	screens.push_back(&s8);

	while (screen >= 0)
	{
		screen = screens[screen]->Run(window);
	}

	return EXIT_SUCCESS;
}