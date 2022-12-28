#include "screen_7.h"

using namespace sf;

gameOverSingle::gameOverSingle()
{
	_font.loadFromFile("../fonts/CrackMan.TTF");

	_textOfScore = Text("", _font, 40);
	_textOfScore.setFillColor(Color::Yellow);
	_textOfScore.setStyle(Text::Bold);

	gameOverImage.loadFromFile("../images/gameOver.png");
	backgroundImage.loadFromFile("../images/PauseBackground.png");
	restartGameKeyImage.loadFromFile("../images/restart.png");
	exitGameKeyImage.loadFromFile("../images/exit.png");

	gameOverTexture.loadFromImage(gameOverImage);
	backgroundTexture.loadFromImage(backgroundImage);
	restartGameKeyTexture.loadFromImage(restartGameKeyImage);
	exitGameKeyTexture.loadFromImage(exitGameKeyImage);

	gameOverSprite.setTexture(gameOverTexture);
	backgroundSprite.setTexture(backgroundTexture);
	restartGameKeySprite.setTexture(restartGameKeyTexture);
	exitGameKeySprite.setTexture(exitGameKeyTexture);
}

int gameOverSingle::Run(sf::RenderWindow& window)
{
	window.setMouseCursorVisible(true);

	std::ostringstream playerScore;

	playerScore << _firstPlayerScore;
	_textOfScore.setString(_parameters[0] + " has collected " + playerScore.str() + " points ");
	_textOfScore.setPosition(540, 400);

	gameOverSprite.setPosition(660, 150);
	restartGameKeySprite.setPosition(762, 660);
	exitGameKeySprite.setPosition(863, 750);

	bool menuIsOpen = true;
	int menuNum = 0;

	while (menuIsOpen)
	{
		menuNum = 0;

		restartGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
		exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });

		if (sf::IntRect(762, 660, 400, 70).contains(sf::Mouse::getPosition(window))) {
			restartGameKeySprite.setColor(sf::Color::White);
			menuNum = 1;
		}
		if (sf::IntRect(860, 750, 195, 80).contains(sf::Mouse::getPosition(window))) {
			exitGameKeySprite.setColor(sf::Color::White);
			menuNum = 2;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 1:
				_isGameStart = false;
				window.clear();
				_needToClean = true;
				return 3;
			case 2:
				_isGameStart = false;
				window.clear();
				_needToClean = true;
				return 0;
			}
		}

		window.clear();

		window.draw(backgroundSprite);
		window.draw(gameOverSprite);
		window.draw(restartGameKeySprite);
		window.draw(exitGameKeySprite);
		window.draw(_textOfScore);

		window.display();
	}

	window.clear();
}