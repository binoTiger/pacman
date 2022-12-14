#pragma once
#include <iostream>
#include "cScreen.h"

#include <SFML/Graphics.hpp>

class startMenu : public cScreen
{
public:
    startMenu();
    virtual int Run(sf::RenderWindow& window);

private:
    sf::Image startGameKeyImage;
    sf::Image exitGameKeyImage;
    sf::Image settingsKeyImage;
    sf::Image pacmanOnLoadScreenImage;
    sf::Image leftSideMapImage;
    sf::Image rightSideMapImage;

    sf::Texture startGameKeyTexture;
    sf::Texture exitGameKeyTexture;
    sf::Texture settingsKeyTexture;
    sf::Texture pacmanOnLoadScreenTexture;
    sf::Texture leftSideMapTexture;
    sf::Texture rightSideMapTexture;

    sf::Sprite startGameKeySprite;
    sf::Sprite exitGameKeySprite;
    sf::Sprite settingsKeySprite;
    sf::Sprite pacmanOnLoadScreenSprite;
    sf::Sprite leftSideMapSprite;
    sf::Sprite rightSideMapSprite;
};

//startMenu::startMenu()
//{
//    _parameters = readParametersFromFile("players.txt");
//
//    startGameKeyImage.loadFromFile("../images/startGame.png");
//    exitGameKeyImage.loadFromFile("../images/exit.png");
//    settingsKeyImage.loadFromFile("../images/settings.png");
//    pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.jpg");
//    rightSideMapImage.loadFromFile("../images/rightSideMap.png");
//    leftSideMapImage.loadFromFile("../images/leftSideMap.png");
//
//    startGameKeyTexture.loadFromImage(startGameKeyImage);
//    exitGameKeyTexture.loadFromImage(exitGameKeyImage);
//    settingsKeyTexture.loadFromImage(settingsKeyImage);
//    pacmanOnLoadScreenTexture.loadFromImage(pacmanOnLoadScreenImage);
//    rightSideMapTexture.loadFromImage(rightSideMapImage);
//    leftSideMapTexture.loadFromImage(leftSideMapImage);
//
//    startGameKeySprite.setTexture(startGameKeyTexture);
//    exitGameKeySprite.setTexture(exitGameKeyTexture);
//    settingsKeySprite.setTexture(settingsKeyTexture);
//    pacmanOnLoadScreenSprite.setTexture(pacmanOnLoadScreenTexture);
//    rightSideMapSprite.setTexture(rightSideMapTexture);
//    leftSideMapSprite.setTexture(leftSideMapTexture);
//}
//
//int startMenu::Run(sf::RenderWindow& window)
//{
//    startGameKeySprite.setPosition(710, 600);
//    settingsKeySprite.setPosition(760, 690);
//    exitGameKeySprite.setPosition(860, 800);
//    pacmanOnLoadScreenSprite.setPosition(508, 100);
//    leftSideMapSprite.setPosition(0, 80);
//    rightSideMapSprite.setPosition(1494, 80);
//
//    bool menuIsOpen = true;
//    int menuNum = 0;
//
//    while (menuIsOpen)
//    {
//        menuNum = 0;
//        window.clear(sf::Color(0, 0, 0));
//        startGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
//        exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
//        settingsKeySprite.setColor(sf::Color{ 0xA4FCFF });
//
//
//        if (sf::IntRect(710, 600, 500, 100).contains(sf::Mouse::getPosition(window))) {
//            startGameKeySprite.setColor(sf::Color::White);
//            menuNum = 1;
//        }
//        if (sf::IntRect(760, 700, 400, 100).contains(sf::Mouse::getPosition(window))) {
//            settingsKeySprite.setColor(sf::Color::White);
//            menuNum = 2;
//        }
//        if (sf::IntRect(860, 800, 200, 100).contains(sf::Mouse::getPosition(window))) {
//            exitGameKeySprite.setColor(sf::Color::White);
//            menuNum = 3;
//        }
//
//        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
//        {
//            if (menuNum == 1) {
//                return 1;
//            }
//            if (menuNum == 2) {
//                return 2;
//            }
//            if (menuNum == 3) {
//                return -1;
//            }
//        }
//
//        window.draw(startGameKeySprite);
//        window.draw(settingsKeySprite);
//        window.draw(exitGameKeySprite);
//        window.draw(pacmanOnLoadScreenSprite);
//        window.draw(leftSideMapSprite);
//        window.draw(rightSideMapSprite);
//        window.display();
//    }
//    window.clear();
//}