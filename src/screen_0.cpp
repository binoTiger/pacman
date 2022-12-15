#include "screen_0.h"

menu_0::menu_0()
{
    _parameters = readParametersFromFile("players.txt");

    startGameKeyImage.loadFromFile("../images/startGame.png");
    exitGameKeyImage.loadFromFile("../images/exit.png");
    settingsKeyImage.loadFromFile("../images/settings.png");
    pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.jpg");
    rightSideMapImage.loadFromFile("../images/rightSideMap.png");
    leftSideMapImage.loadFromFile("../images/leftSideMap.png");

    startGameKeyTexture.loadFromImage(startGameKeyImage);
    exitGameKeyTexture.loadFromImage(exitGameKeyImage);
    settingsKeyTexture.loadFromImage(settingsKeyImage);
    pacmanOnLoadScreenTexture.loadFromImage(pacmanOnLoadScreenImage);
    rightSideMapTexture.loadFromImage(rightSideMapImage);
    leftSideMapTexture.loadFromImage(leftSideMapImage);

    startGameKeySprite.setTexture(startGameKeyTexture);
    exitGameKeySprite.setTexture(exitGameKeyTexture);
    settingsKeySprite.setTexture(settingsKeyTexture);
    pacmanOnLoadScreenSprite.setTexture(pacmanOnLoadScreenTexture);
    rightSideMapSprite.setTexture(rightSideMapTexture);
    leftSideMapSprite.setTexture(leftSideMapTexture);
}

int menu_0::Run(sf::RenderWindow& window)
{
    sf::Mouse::setPosition(sf::Vector2i(960, 540), window);

    startGameKeySprite.setPosition(710, 600);
    settingsKeySprite.setPosition(760, 690);
    exitGameKeySprite.setPosition(860, 800);
    pacmanOnLoadScreenSprite.setPosition(508, 100);
    leftSideMapSprite.setPosition(0, 80);
    rightSideMapSprite.setPosition(1494, 80);

    bool menuIsOpen = true;
    int menuNum = 0;

    while (menuIsOpen)
    {
        menuNum = 0;
        window.clear(sf::Color(0, 0, 0));
        startGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
        exitGameKeySprite.setColor(sf::Color{ 0xA4FCFF });
        settingsKeySprite.setColor(sf::Color{ 0xA4FCFF });


        if (sf::IntRect(710, 600, 500, 100).contains(sf::Mouse::getPosition(window))) {
            startGameKeySprite.setColor(sf::Color::White);
            menuNum = 1;
        }
        if (sf::IntRect(760, 700, 400, 100).contains(sf::Mouse::getPosition(window))) {
            settingsKeySprite.setColor(sf::Color::White);
            menuNum = 2;
        }
        if (sf::IntRect(860, 800, 200, 100).contains(sf::Mouse::getPosition(window))) {
            exitGameKeySprite.setColor(sf::Color::White);
            menuNum = 3;
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            if (menuNum == 1) {
                return 1;
            }
            if (menuNum == 2) {
                return 2;
            }
            if (menuNum == 3) {
                return -1;
            }
        }

        window.draw(startGameKeySprite);
        window.draw(settingsKeySprite);
        window.draw(exitGameKeySprite);
        window.draw(pacmanOnLoadScreenSprite);
        window.draw(leftSideMapSprite);
        window.draw(rightSideMapSprite);
        window.display();
    }
    window.clear();
}