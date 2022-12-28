#include "../include/gameOverSingleScreen.h"

using namespace sf;

gameOverSingle::gameOverSingle()
    : pauseMenu()
{
	_font.loadFromFile("../fonts/CrackMan.TTF");

    _textOfScore1 = Text("", _font, 40);
	_textOfScore1.setFillColor(Color::Yellow);
	_textOfScore1.setStyle(Text::Bold);

	gameOverImage.loadFromFile("../images/gameOver.png");

	gameOverTexture.loadFromImage(gameOverImage);

	gameOverSprite.setTexture(gameOverTexture);
}

int gameOverSingle::Run(sf::RenderWindow& window)
{
	window.setMouseCursorVisible(true);

	std::ostringstream playerScore;

	playerScore << _firstPlayerScore;
	_textOfScore1.setString(_parameters[0] + " has collected " + playerScore.str() + " points ");
	_textOfScore1.setPosition(540, 400);

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

        sf::Event event{};
        while (window.pollEvent(event))
        {}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			switch (menuNum)
			{
			case 1:
				_isGameStart = false;
				window.clear();
				return 3;
			case 2:
				_isGameStart = false;
				window.clear();
				return 0;
			}
		}

		window.clear();

		window.draw(backgroundSprite);
		window.draw(gameOverSprite);
		window.draw(restartGameKeySprite);
		window.draw(exitGameKeySprite);
		window.draw(_textOfScore1);

		window.display();
	}
}