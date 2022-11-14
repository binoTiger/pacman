#pragma once
class Menu
{
public:
    Menu() {
        menuIsOpen = true;
        startGameKeyImage.loadFromFile("../images/startGame.png");
        exitGameKeyImage.loadFromFile("../images/exit.png");
        pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.jpg");
        rightSideMapImage.loadFromFile("../images/rightSideMap.png");
        leftSideMapImage.loadFromFile("../images/leftSideMap.png");

        startGameKeyImage.createMaskFromColor(sf::Color::White);
        exitGameKeyImage.createMaskFromColor(sf::Color::White);

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
    void drawMenu(sf::RenderWindow& window)
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
            window.clear(sf::Color(0,0,0));
            startGameKeySprite.setColor(sf::Color{0xA4FCFF});
            exitGameKeySprite.setColor(sf::Color{0xA4FCFF});

            if (sf::IntRect(710, 600, 500, 100).contains(sf::Mouse::getPosition(window))) {
                startGameKeySprite.setColor(sf::Color::White);
                menuNum = 1; 
            }
            if (sf::IntRect(860, 700, 200, 100).contains(sf::Mouse::getPosition(window))) {
                exitGameKeySprite.setColor(sf::Color::White);
                menuNum = 2;
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
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

private:
    bool menuIsOpen;

    sf::Image startGameKeyImage;
    sf::Image exitGameKeyImage;
    sf::Image pacmanOnLoadScreenImage;
    sf::Image leftSideMapImage;
    sf::Image rightSideMapImage;

    sf::Texture startGameKeyTexture;
    sf::Texture exitGameKeyTexture;
    sf::Texture pacmanOnLoadScreenTexture;
    sf::Texture leftSideMapTexture;
    sf::Texture rightSideMapTexture;

    sf::Sprite startGameKeySprite;
    sf::Sprite exitGameKeySprite;
    sf::Sprite pacmanOnLoadScreenSprite;
    sf::Sprite leftSideMapSprite;
    sf::Sprite rightSideMapSprite;
};