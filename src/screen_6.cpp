#pragma once

#include "screen_6.h"

pauseMenu::pauseMenu()
{
	_parameters = readParametersFromFile("players.txt");

	backgroundImage.loadFromFile("../images/PauseBackground.png");
	continueGameKeyImage.loadFromFile("../images/Continue.png");
	exitGameKeyImage.loadFromFile("../images/exit.png");

	backgroundTexture.loadFromImage(backgroundImage);
	continueGameKeyTexture.loadFromImage(continueGameKeyImage);
	exitGameKeyTexture.loadFromImage(exitGameKeyImage);

	backgroundSprite.setTexture(backgroundTexture);
	continueGameKeySprite.setTexture(continueGameKeyTexture);
	exitGameKeySprite.setTexture(exitGameKeyTexture);
}

int pauseMenu::Run(sf::RenderWindow& window)
{
	//backgroundSprite.setPosition(1, 1);
	continueGameKeySprite.setPosition(750, 570);
	exitGameKeySprite.setPosition(860, 700);

	bool menuIsOpen = true;
	int menuNum = 0;

	while (menuIsOpen)
	{
		menuNum = 0;
		window.clear(sf::Color(0, 0, 0));

		continueGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
		exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });

		if (sf::IntRect(750, 570, 420, 80).contains(sf::Mouse::getPosition(window))) {
			continueGameKeySprite.setColor(sf::Color::White);
			menuNum = 3;
		}
		if (sf::IntRect(860, 700, 195, 80).contains(sf::Mouse::getPosition(window))) {
			exitGameKeySprite.setColor(sf::Color::White);
			menuNum = 1;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 3:
				return (int)_gameMode;
			case 1:
				_isGameStart = false;
				return 0;
			}
		}

		window.draw(backgroundSprite);
		window.draw(continueGameKeySprite);
		window.draw(exitGameKeySprite);

		window.display();
	}

	window.clear();
}