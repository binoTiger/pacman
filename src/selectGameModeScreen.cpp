#include "../include/selectGameModeScreen.h"

selectGameMode::selectGameMode()
{
    pacmanOnLoadScreenImage.loadFromFile("../images/pacmanImage.png");
    rightSideMapImage.loadFromFile("../images/rightSideMap.png");
    leftSideMapImage.loadFromFile("../images/leftSideMap.png");
    singlePlayKeyImage.loadFromFile("../images/single.png");
    duoPlayKeyImage.loadFromFile("../images/duo.png");
    trainingPlayKeyImage.loadFromFile("../images/training.png");

    pacmanOnLoadScreenTexture.loadFromImage(pacmanOnLoadScreenImage);
    rightSideMapTexture.loadFromImage(rightSideMapImage);
    leftSideMapTexture.loadFromImage(leftSideMapImage);
    singlePlayKeyTexture.loadFromImage(singlePlayKeyImage);
    duoPlayKeyTexture.loadFromImage(duoPlayKeyImage);
    trainingPlayKeyTexture.loadFromImage(trainingPlayKeyImage);

    pacmanOnLoadScreenSprite.setTexture(pacmanOnLoadScreenTexture);
    rightSideMapSprite.setTexture(rightSideMapTexture);
    leftSideMapSprite.setTexture(leftSideMapTexture);
    singlePlayKeySprite.setTexture(singlePlayKeyTexture);
    duoPlayKeySprite.setTexture(duoPlayKeyTexture);
    trainingPlayKeySprite.setTexture(trainingPlayKeyTexture);
}

int selectGameMode::Run(sf::RenderWindow& window)
{
    sf::Mouse::setPosition(sf::Vector2i(960, 540), window);
    bool secondPageMenuIsOpen = true;
    int menuNum = 0;
    pacmanOnLoadScreenSprite.setPosition(508, 100);
    leftSideMapSprite.setPosition(0, 80);
    rightSideMapSprite.setPosition(1494, 80);
    singlePlayKeySprite.setPosition(810, 600);
    duoPlayKeySprite.setPosition(860, 700);
    trainingPlayKeySprite.setPosition(760, 800);

    while (secondPageMenuIsOpen) {
        _gameMode = GameMode::NONE;

        menuNum = 0;
        window.clear();

        singlePlayKeySprite.setColor(sf::Color{ 0xA4FCFF });
        duoPlayKeySprite.setColor(sf::Color{ 0xA4FCFF });
        trainingPlayKeySprite.setColor(sf::Color{ 0xA4FCFF });

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            window.clear();
            return 0;
        }
        if (sf::IntRect(817, 630, 286, 48).contains(sf::Mouse::getPosition(window))) {
            singlePlayKeySprite.setColor(sf::Color::White);
            menuNum = 1;
        }
        if (sf::IntRect(875, 730, 170, 48).contains(sf::Mouse::getPosition(window))) {
            duoPlayKeySprite.setColor(sf::Color::White);
            menuNum = 2;
        }
        if (sf::IntRect(775, 830, 370, 48).contains(sf::Mouse::getPosition(window))) {
            trainingPlayKeySprite.setColor(sf::Color::White);
            menuNum = 3;
        }

        sf::Event event{};
        while (window.pollEvent(event))
        {}

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            switch (menuNum)
            {
            case 1:
                _gameMode = GameMode::SINGLE;
                window.clear();
                return 3;
            case 2:
                _gameMode = GameMode::DUO;
                window.clear();
                return 4;
            case 3:
                _gameMode = GameMode::TRAINING;
                window.clear();
                return 5;
            }
        }

        window.clear();
        window.draw(pacmanOnLoadScreenSprite);
        window.draw(leftSideMapSprite);
        window.draw(rightSideMapSprite);
        window.draw(singlePlayKeySprite);
        window.draw(duoPlayKeySprite);
        window.draw(trainingPlayKeySprite);
        window.display();
    }
}