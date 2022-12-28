#include "../include/gameOverDuoScreen.h"

using namespace sf;

gameOverDuo::gameOverDuo()
    : gameOverSingle()
{
	_textOfScore2 = Text("", _font, 40);
	_textOfScore2.setFillColor(Color::Yellow);
	_textOfScore2.setStyle(Text::Bold);

	_winnerPlayer = Text("", _font, 48);
	_winnerPlayer.setFillColor(Color::Yellow);
	_winnerPlayer.setStyle(Text::Bold);
}

int gameOverDuo::Run(sf::RenderWindow& window)
{
	window.setMouseCursorVisible(true);

	std::ostringstream playerScore;

	_winnerPlayer.setString(_winner + " won!");
	_winnerPlayer.setPosition(540, 550);

	playerScore << _firstPlayerScore;
	_textOfScore1.setString(_parameters[0] + " has collected " + playerScore.str() + " points ");
	_textOfScore1.setPosition(540, 400);

	playerScore.clear();
	playerScore << _secondPlayerScore;
	_textOfScore2.setString(_parameters[3] + " has collected " + playerScore.str() + " points ");
	_textOfScore2.setPosition(540, 460);

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
				return (int)_gameMode;
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
		window.draw(_textOfScore2);
		window.draw(_winnerPlayer);

		window.display();
	}
}