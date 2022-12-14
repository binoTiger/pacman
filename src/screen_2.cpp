#include "screen_2.h"

menu_2::menu_2()
{
    _parameters = readParametersFromFile("players.txt");

    _firstPlayerColor = getColor(_parameters[1]);
    _firstPlayerControls = getControls(_parameters[2]);

    _secondPlayerColor = getColor(_parameters[4]);
    _secondPlayerControls = getControls(_parameters[5]);

    firstPlayerImage.loadFromFile("../images/firstPlayer.png");
    secondPlayerImage.loadFromFile("../images/secondPlayer.png");
    nicknameImage.loadFromFile("../images/nickname.png");
    chooseColorImage.loadFromFile("../images/chooseColor.png");
    greyImage.loadFromFile("../images/grey.png");
    greenImage.loadFromFile("../images/green.png");;
    pinkImage.loadFromFile("../images/pink.png");
    yellowImage.loadFromFile("../images/yellow.png");
    greyColorImage.loadFromFile("../images/greyColor.png");
    greenColorImage.loadFromFile("../images/greenColor.png");;
    pinkColorImage.loadFromFile("../images/pinkColor.png");
    yellowColorImage.loadFromFile("../images/yellowColor.png");
    selectManagementImage.loadFromFile("../images/selectManagement.png");
    arrowsImage.loadFromFile("../images/arrows.png");
    wasdImage.loadFromFile("../images/wasd.png");

    greyColorImage.createMaskFromColor(sf::Color::Green);
    pinkColorImage.createMaskFromColor(sf::Color::Green);
    greenColorImage.createMaskFromColor(sf::Color::Green);
    yellowColorImage.createMaskFromColor(sf::Color::Green);


    firstPlayerTexture.loadFromImage(firstPlayerImage);
    secondPlayerTexture.loadFromImage(secondPlayerImage);
    nicknameTexture.loadFromImage(nicknameImage);
    chooseColorTexture.loadFromImage(chooseColorImage);
    greyTexture.loadFromImage(greyImage);
    greenTexture.loadFromImage(greenImage);
    pinkTexture.loadFromImage(pinkImage);
    yellowTexture.loadFromImage(yellowImage);
    greyColorTexture.loadFromImage(greyColorImage);
    greenColorTexture.loadFromImage(greenColorImage);
    pinkColorTexture.loadFromImage(pinkColorImage);
    yellowColorTexture.loadFromImage(yellowColorImage);
    selectManagementTexture.loadFromImage(selectManagementImage);
    arrowsTexture.loadFromImage(arrowsImage);
    wasdTexture.loadFromImage(wasdImage);

    firstPlayerSprite.setTexture(firstPlayerTexture);
    secondPlayerSprite.setTexture(secondPlayerTexture);
    nicknameSprite.setTexture(nicknameTexture);
    chooseColorSprite.setTexture(chooseColorTexture);
    greySprite.setTexture(greyTexture);
    greenSprite.setTexture(greenTexture);
    pinkSprite.setTexture(pinkTexture);
    yellowSprite.setTexture(yellowTexture);
    greyColorSprite.setTexture(greyColorTexture);
    greenColorSprite.setTexture(greenColorTexture);
    pinkColorSprite.setTexture(pinkColorTexture);
    yellowColorSprite.setTexture(yellowColorTexture);
    selectManagementSprite.setTexture(selectManagementTexture);
    arrowsSprite.setTexture(arrowsTexture);
    wasdSprite.setTexture(wasdTexture);
}

int menu_2::Run(sf::RenderWindow& window)
{
    bool menuIsOpen = true;
    int settingNum = 0;
    firstPlayerSprite.setPosition(178, 50);
    secondPlayerSprite.setPosition(1114, 50);
    nicknameSprite.setPosition(278, 250);
    chooseColorSprite.setPosition(228, 450);

    greySprite.setPosition(15, 590);
    pinkSprite.setPosition(225, 590);
    yellowSprite.setPosition(405, 597);
    greenSprite.setPosition(710, 597);

    greyColorSprite.setPosition(75, 700);
    pinkColorSprite.setPosition(270, 700);
    yellowColorSprite.setPosition(510, 700);
    greenColorSprite.setPosition(790, 700);
    selectManagementSprite.setPosition(103, 820);
    arrowsSprite.setPosition(100, 970);
    wasdSprite.setPosition(457, 970);

    sf::Sprite arrowsSprite2 = arrowsSprite;
    arrowsSprite2.setPosition(1036, 970);
    sf::Sprite wasdSprite2 = wasdSprite;
    wasdSprite2.setPosition(1393, 970);

    sf::Sprite nicknameSprite2 = nicknameSprite;
    nicknameSprite2.setPosition(1214, 250);
    sf::Sprite chooseColorSprite2 = chooseColorSprite;
    chooseColorSprite2.setPosition(1164, 450);

    sf::Sprite greySprite2 = greySprite;
    greySprite2.setPosition(970, 590);
    sf::Sprite pinkSprite2 = pinkSprite;
    pinkSprite2.setPosition(1175, 590);
    sf::Sprite yellowSprite2 = yellowSprite;
    yellowSprite2.setPosition(1355, 597);
    sf::Sprite greenSprite2 = greenSprite;
    greenSprite2.setPosition(1660, 597);

    sf::Sprite greyColorSprite2 = greyColorSprite;
    greyColorSprite2.setTextureRect(sf::IntRect(75, 0, -75, 75));
    greyColorSprite2.setPosition(1025, 700);
    sf::Sprite pinkColorSprite2 = pinkColorSprite;
    pinkColorSprite2.setTextureRect(sf::IntRect(75, 0, -75, 75));
    pinkColorSprite2.setPosition(1220, 700);
    sf::Sprite yellowColorSprite2 = yellowColorSprite;
    yellowColorSprite2.setTextureRect(sf::IntRect(75, 0, -75, 75));
    yellowColorSprite2.setPosition(1465, 700);
    sf::Sprite greenColorSprite2 = greenColorSprite;
    greenColorSprite2.setTextureRect(sf::IntRect(75, 0, -75, 75));
    greenColorSprite2.setPosition(1740, 700);

    sf::Sprite selectManagementSprite2 = selectManagementSprite;
    selectManagementSprite2.setPosition(1039, 820);

    _parameters = readParametersFromFile("players.txt");

    sf::Font arial;
    arial.loadFromFile("../fonts/arialmt.ttf");
    TextBox textbox1(50, sf::Color::White, false, _parameters[0]);
    textbox1.setFont(arial);
    textbox1.setPosition({ 278,350 });
    textbox1.setLimit(true, 15);

    TextBox textbox2(50, sf::Color::White, false, _parameters[3]);
    textbox2.setFont(arial);
    textbox2.setPosition({ 1214,350 });
    textbox2.setLimit(true, 15);

    while (menuIsOpen) {
        settingNum = 0;

        sf::Event event;
        greySprite.setColor(sf::Color{ 0xA4FCFF });
        pinkSprite.setColor(sf::Color{ 0xA4FCFF });
        yellowSprite.setColor(sf::Color{ 0xA4FCFF });
        greenSprite.setColor(sf::Color{ 0xA4FCFF });
        arrowsSprite.setColor(sf::Color{ 0xA4FCFF });
        wasdSprite.setColor(sf::Color{ 0xA4FCFF });
        arrowsSprite2.setColor(sf::Color{ 0xA4FCFF });
        wasdSprite2.setColor(sf::Color{ 0xA4FCFF });

        greySprite2.setColor(sf::Color{ 0xA4FCFF });
        pinkSprite2.setColor(sf::Color{ 0xA4FCFF });
        yellowSprite2.setColor(sf::Color{ 0xA4FCFF });
        greenSprite2.setColor(sf::Color{ 0xA4FCFF });

        if (sf::IntRect(10, 600, 195, 70).contains(sf::Mouse::getPosition(window))) {
            greySprite.setColor(sf::Color::White);
            settingNum = 11;
        }
        if (sf::IntRect(230, 600, 150, 70).contains(sf::Mouse::getPosition(window))) {
            pinkSprite.setColor(sf::Color::White);
            settingNum = 12;
        }
        if (sf::IntRect(410, 600, 280, 70).contains(sf::Mouse::getPosition(window))) {
            yellowSprite.setColor(sf::Color::White);
            settingNum = 13;
        }
        if (sf::IntRect(710, 600, 230, 70).contains(sf::Mouse::getPosition(window))) {
            greenSprite.setColor(sf::Color::White);
            settingNum = 14;
        }

        if (sf::IntRect(100, 970, 320, 100).contains(sf::Mouse::getPosition(window))) {
            arrowsSprite.setColor(sf::Color::White);
            settingNum = 15;
        }
        if (sf::IntRect(457, 970, 400, 75).contains(sf::Mouse::getPosition(window))) {
            wasdSprite.setColor(sf::Color::White);
            settingNum = 16;
        }
        if (sf::IntRect(1036, 970, 320, 100).contains(sf::Mouse::getPosition(window))) {
            arrowsSprite2.setColor(sf::Color::White);
            settingNum = 25;
        }
        if (sf::IntRect(1393, 970, 400, 75).contains(sf::Mouse::getPosition(window))) {
            wasdSprite2.setColor(sf::Color::White);
            settingNum = 26;
        }

        if (sf::IntRect(970, 600, 180, 70).contains(sf::Mouse::getPosition(window))) {
            greySprite2.setColor(sf::Color::White);
            settingNum = 21;
        }
        if (sf::IntRect(1180, 600, 155, 70).contains(sf::Mouse::getPosition(window))) {
            pinkSprite2.setColor(sf::Color::White);
            settingNum = 22;
        }
        if (sf::IntRect(1355, 600, 280, 70).contains(sf::Mouse::getPosition(window))) {
            yellowSprite2.setColor(sf::Color::White);
            settingNum = 23;
        }
        if (sf::IntRect(1660, 600, 230, 70).contains(sf::Mouse::getPosition(window))) {
            greenSprite2.setColor(sf::Color::White);
            settingNum = 24;
        }

        if (sf::IntRect(278, 350, 400, 50).contains(sf::Mouse::getPosition(window))) {
            textbox1.setSelected(true);
            textbox2.setSelected(false);
        }
        if (sf::IntRect(1214, 350, 400, 50).contains(sf::Mouse::getPosition(window))) {
            textbox1.setSelected(false);
            textbox2.setSelected(true);
        }
        if (!sf::IntRect(278, 350, 400, 50).contains(sf::Mouse::getPosition(window)) && !sf::IntRect(1214, 350, 400, 50).contains(sf::Mouse::getPosition(window))) {
            textbox1.setSelected(false);
            textbox2.setSelected(false);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            textbox1.setSelected(false);
            textbox2.setSelected(false);
        }

        while (window.pollEvent(event))
        {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                menuIsOpen = false;
            }
            if (event.type == sf::Event::TextEntered) {
                textbox1.typedOn(event);
                textbox2.typedOn(event);
            }
        }

        if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
        {
            switch (settingNum)
            {
            case 11:
                _firstPlayerColor = PacmanColors::GREY;
                break;
            case 12:
                _firstPlayerColor = PacmanColors::PINK;
                break;
            case 13:
                _firstPlayerColor = PacmanColors::YELLOW;
                break;
            case 14:
                _firstPlayerColor = PacmanColors::GREEN;
                break;
            case 15:
                _firstPlayerControls = PacmanControls::ARROWS;
                _secondPlayerControls = PacmanControls::WASD;
                break;
            case 16:
                _firstPlayerControls = PacmanControls::WASD;
                _secondPlayerControls = PacmanControls::ARROWS;
                break;

            case 21:
                _secondPlayerColor = PacmanColors::GREY;
                break;
            case 22:
                _secondPlayerColor = PacmanColors::PINK;
                break;
            case 23:
                _secondPlayerColor = PacmanColors::YELLOW;
                break;
            case 24:
                _secondPlayerColor = PacmanColors::GREEN;
                break;
            case 25:
                _firstPlayerControls = PacmanControls::WASD;
                _secondPlayerControls = PacmanControls::ARROWS;
                break;
            case 26:
                _firstPlayerControls = PacmanControls::ARROWS;
                _secondPlayerControls = PacmanControls::WASD;
                break;
            }
        }

        switch (_firstPlayerColor)
        {
        case PacmanColors::GREY:
            greySprite.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::PINK:
            pinkSprite.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::YELLOW:
            yellowSprite.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::GREEN:
            greenSprite.setColor(sf::Color::Magenta);
            break;
        }
        switch (_firstPlayerControls)
        {
        case PacmanControls::ARROWS:
            arrowsSprite.setColor(sf::Color::Magenta);
            break;
        case PacmanControls::WASD:
            wasdSprite.setColor(sf::Color::Magenta);
            break;
        }

        switch (_secondPlayerColor)
        {
        case PacmanColors::GREY:
            greySprite2.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::PINK:
            pinkSprite2.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::YELLOW:
            yellowSprite2.setColor(sf::Color::Magenta);
            break;
        case PacmanColors::GREEN:
            greenSprite2.setColor(sf::Color::Magenta);
            break;
        }
        switch (_secondPlayerControls)
        {
        case PacmanControls::ARROWS:
            arrowsSprite2.setColor(sf::Color::Magenta);
            break;
        case PacmanControls::WASD:
            wasdSprite2.setColor(sf::Color::Magenta);
            break;
        }

        window.clear(sf::Color(0, 0, 0));

        sf::Vertex verticalLine[] = { sf::Vertex(sf::Vector2f(957, 0)), sf::Vertex(sf::Vector2f(957, 1080)) };
        sf::Vertex underPlayersLine[] = { sf::Vertex(sf::Vector2f(0, 200)), sf::Vertex(sf::Vector2f(1920, 200)) };
        sf::Vertex underNickNameLine[] = { sf::Vertex(sf::Vector2f(0, 450)), sf::Vertex(sf::Vector2f(1920, 450)) };
        sf::Vertex underSelectColorLine[] = { sf::Vertex(sf::Vector2f(0, 810)), sf::Vertex(sf::Vector2f(1920, 810)) };

        window.draw(verticalLine, 6, sf::Lines);
        window.draw(underPlayersLine, 6, sf::Lines);
        window.draw(underNickNameLine, 6, sf::Lines);
        window.draw(underSelectColorLine, 6, sf::Lines);
        window.draw(firstPlayerSprite);
        window.draw(secondPlayerSprite);
        window.draw(nicknameSprite);
        window.draw(nicknameSprite2);
        window.draw(chooseColorSprite);
        window.draw(chooseColorSprite2);
        window.draw(greySprite);
        window.draw(pinkSprite);
        window.draw(yellowSprite);
        window.draw(greenSprite);
        window.draw(greySprite2);
        window.draw(pinkSprite2);
        window.draw(yellowSprite2);
        window.draw(greenSprite2);
        window.draw(greyColorSprite);
        window.draw(pinkColorSprite);
        window.draw(yellowColorSprite);
        window.draw(greenColorSprite);
        window.draw(greyColorSprite2);
        window.draw(pinkColorSprite2);
        window.draw(yellowColorSprite2);
        window.draw(greenColorSprite2);
        window.draw(selectManagementSprite);
        window.draw(selectManagementSprite2);
        window.draw(arrowsSprite);
        window.draw(wasdSprite);
        window.draw(arrowsSprite2);
        window.draw(wasdSprite2);
        textbox1.drawText(window);
        textbox2.drawText(window);
        window.display();
    }

    _parameters[0] = textbox1.GetText();
    _parameters[1] = setColor(_firstPlayerColor);
    _parameters[2] = setControls(_firstPlayerControls);
    _parameters[3] = textbox2.GetText();
    _parameters[4] = setColor(_secondPlayerColor);
    _parameters[5] = setControls(_secondPlayerControls);

    writeParametersInFile("players.txt", _parameters);

    return 0;
}