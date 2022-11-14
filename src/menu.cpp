#include "menu.h"

using namespace sf;

Menu::Menu() {
    menuIsOpen = true;
    startGameKeyImage.loadFromFile("../images/startGame.png");
    exitGameKeyImage.loadFromFile("../images/exit.png");
    pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.jpg");
    rightSideMapImage.loadFromFile("../images/rightSideMap.png");
    leftSideMapImage.loadFromFile("../images/leftSideMap.png");

    startGameKeyImage.createMaskFromColor(Color::White);
    exitGameKeyImage.createMaskFromColor(Color::White);

    startGameKeyTexture.loadFromImage(startGameKeyImage);
    exitGameKeyTexture.loadFromImage(exitGameKeyImage);
    pacmanOnLoadScreenTexture.loadFromImage(pacmanOnLoadScreenImage);
    rightSideMapTexture.loadFromImage(rightSideMapImage);
    leftSideMapTexture.loadFromImage(leftSideMapImage);

    startGameKeySprite.setTexture(startGameKeyTexture);
    exitGameKeySprite.setTexture(exitGameKeyTexture);
    pacmanOnLoadScreenSprite.setTexture(pacmanOnLoadScreenTexture);
    rightSideMapSprite.setTexture(rightSideMapTexture);
    leftSideMapSprite.setTexture(leftSideMapTexture);
}

void Menu::drawMenu(RenderWindow& window)
{
    startGameKeySprite.setPosition(710, 600);
    exitGameKeySprite.setPosition(860, 700);
    pacmanOnLoadScreenSprite.setPosition(508, 100);
    leftSideMapSprite.setPosition(0, 80);
    rightSideMapSprite.setPosition(1494, 80);

    int menuNum = 0;
    while (menuIsOpen)
    {
        menuNum = 0;
        window.clear(Color(0, 0, 0));
        startGameKeySprite.setColor(Color{ 0xA4FCFF });
        exitGameKeySprite.setColor(Color{ 0xA4FCFF });

        if (IntRect(710, 600, 500, 100).contains(Mouse::getPosition(window))) {
            startGameKeySprite.setColor(Color::White);
            menuNum = 1;
        }
        if (IntRect(860, 700, 200, 100).contains(Mouse::getPosition(window))) {
            exitGameKeySprite.setColor(Color::White);
            menuNum = 2;
        }
        if (Mouse::isButtonPressed(Mouse::Left))
        {
            if (menuNum == 1) {
                menuIsOpen = false;
            }
            if (menuNum == 2) {
                window.close();
                menuIsOpen = false;
            }
        }
        window.draw(startGameKeySprite);
        window.draw(exitGameKeySprite);
        window.draw(pacmanOnLoadScreenSprite);
        window.draw(leftSideMapSprite);
        window.draw(rightSideMapSprite);
        window.display();
    }
}