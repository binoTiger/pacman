#include "../include/startMenuScreen.h"

using namespace sf;

startMenu::startMenu()
{
    _parameters = readParametersFromFile("players.txt");

    startGameKeyImage.loadFromFile("../images/startGame.png");
    exitGameKeyImage.loadFromFile("../images/exit.png");
    settingsKeyImage.loadFromFile("../images/settings.png");
    pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.png");
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

int startMenu::Run(RenderWindow& window)
{
    Mouse::setPosition(Vector2i(960, 540), window);

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
        window.clear(Color(0, 0, 0));
        startGameKeySprite.setColor(Color{ 0xA4FCFF });
        exitGameKeySprite.setColor(Color{ 0xA4FCFF });
        settingsKeySprite.setColor(Color{ 0xA4FCFF });


        if (IntRect(710, 600, 500, 100).contains(Mouse::getPosition(window))) {
            startGameKeySprite.setColor(Color::White);
            menuNum = 1;
        }
        if (IntRect(760, 700, 400, 100).contains(Mouse::getPosition(window))) {
            settingsKeySprite.setColor(Color::White);
            menuNum = 2;
        }
        if (IntRect(860, 800, 200, 100).contains(Mouse::getPosition(window))) {
            exitGameKeySprite.setColor(Color::White);
            menuNum = 3;
        }

        Event event{};
        while (window.pollEvent(event))
        {}

        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                window.clear();
                return 1;
            }
            if (menuNum == 2) {
                window.clear();
                return 2;
            }
            if (menuNum == 3) {
                window.clear();
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
}