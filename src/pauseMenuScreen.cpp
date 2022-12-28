#include "../include/pauseMenuScreen.h"

pauseMenu::pauseMenu()
{
	backgroundImage.loadFromFile("../images/PauseBackground.png");
	continueGameKeyImage.loadFromFile("../images/Continue.png");
	restartGameKeyImage.loadFromFile("../images/restart.png");
	exitGameKeyImage.loadFromFile("../images/exit.png");

	backgroundTexture.loadFromImage(backgroundImage);
	continueGameKeyTexture.loadFromImage(continueGameKeyImage);
	restartGameKeyTexture.loadFromImage(restartGameKeyImage);
	exitGameKeyTexture.loadFromImage(exitGameKeyImage);

	backgroundSprite.setTexture(backgroundTexture);
	continueGameKeySprite.setTexture(continueGameKeyTexture);
	restartGameKeySprite.setTexture(restartGameKeyTexture);
	exitGameKeySprite.setTexture(exitGameKeyTexture);
}

int pauseMenu::Run(sf::RenderWindow& window)
{
	window.setMouseCursorVisible(true);

	continueGameKeySprite.setPosition(750, 540);
	restartGameKeySprite.setPosition(762, 660);
	exitGameKeySprite.setPosition(863, 750);

	bool menuIsOpen = true;
	int menuNum = 0;

	while (menuIsOpen)
	{
		menuNum = 0;
		window.clear(sf::Color(0, 0, 0));

		continueGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
		restartGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
		exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });

		if (sf::IntRect(750, 540, 420, 80).contains(sf::Mouse::getPosition(window))) {
			continueGameKeySprite.setColor(sf::Color::White);
			menuNum = 3;
		}
		if (sf::IntRect(762, 660, 400, 70).contains(sf::Mouse::getPosition(window))) {
			restartGameKeySprite.setColor(sf::Color::White);
			menuNum = 2;
		}
		if (sf::IntRect(860, 750, 195, 80).contains(sf::Mouse::getPosition(window))) {
			exitGameKeySprite.setColor(sf::Color::White);
			menuNum = 1;
		}
		
		sf::Event event;

		while (window.pollEvent(event)) {
			if (event.type == sf::Event::KeyReleased) {
				if (event.key.code == sf::Keyboard::Escape) {
					window.clear();
					return (int)_gameMode;
				}
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 3:
				window.clear();
				return (int)_gameMode;
			case 2:
				_isGameStart = false;
				window.clear();
				return (int)_gameMode;
			case 1:
				_isGameStart = false;
				window.clear();
				return 0;
			}
		}


		window.draw(backgroundSprite);
		window.draw(continueGameKeySprite);
		window.draw(restartGameKeySprite);
		window.draw(exitGameKeySprite);

		window.display();
	}
}