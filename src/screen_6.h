#pragma once
#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class pauseMenu : public cScreen
{
public:
	pauseMenu();
	virtual int Run(sf::RenderWindow& window);

private:
	sf::Image backgroundImage;
	sf::Image continueGameKeyImage;
	sf::Image exitGameKeyImage;

	sf::Texture backgroundTexture;
	sf::Texture continueGameKeyTexture;
	sf::Texture exitGameKeyTexture;

	sf::Sprite backgroundSprite;
	sf::Sprite continueGameKeySprite;
	sf::Sprite exitGameKeySprite;
};

//menu_4::menu_4();
//{
//	_parameters = readParametersFromFile("players.txt");
//
//	backgroundImage.loadFromFile("../images/PauseBackground");
//	continueGameKeyImage.loadFromFile("../images/Continue.png");
//	exitGameKeyImage.loadFromFile("../images/exit.png");
//
//	backgroundTexture.loadFromImage(backgroundImage);
//	continueGameKeyTexture.loadFromImage(continueGameKeyImage);
//	exitGameKeyTexture.loadFromImage(exitGameKeyImage);
//
//	backgroundSprite.setTexture(backgroundTexture);
//	continueGameKeySprite.setTexture(continueGameKeyTexture);
//	exitGameKeySprite.setTexture(exitGameKeyTexture);
//}

//int menu_4::Run(sf::RenderWindow& window)
//{
//	//backgroundSprite.setPosition(0, 0);
//	continueGameKeySprite.setPosition(710, 600);
//	exitGameKeySprite.setPosition(780, 700);
//
//	bool menuIsOpen = true;
//	int menuNum = 0;
//
//	while (menuIsOpen)
//	{
//		menuNum = 0;
//		window.clear(sf::Color(0, 0, 0));
//
//		continueGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
//		exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
//
//		if (sf::IntRect(710, 600, 355, 55).contains(sf::Mouse::getPosition(window))) {
//			continueGameKeySprite.setColor(sf::Color::White);
//			menuNum = 1;
//		}
//		if (sf::IntRect(780, 700, 200, 100).contains(sf::Mouse::getPosition(window))) {
//			exitGameKeySprite.setColor(sf::Color::White);
//			menuNum = 0;
//		}
//
//		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//		{
//			switch (menuNum)
//			{
//			case 1:
//				return 1;
//			case 0:
//				return 0;
//			}
//		}
//
//		window.draw(backgroundSprite);
//		window.draw(continueGameKeySprite);
//		window.draw(exitGameKeySprite);
//
//		window.display();
//	}
//
//	window.clear();
//}