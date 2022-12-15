#include "cScreen.h"

std::vector<std::string> readParametersFromFile(std::string fileName)
{
    std::ifstream file(fileName, std::ios::out | std::ios::app);

    std::vector<std::string> parameters;

    if (file.peek() == EOF) {
        return std::vector<std::string>{ "player", "yellow", "arrows", "player2", "grey", "wasd" };
    }
    else {
        while (!file.eof())
        {
            std::string temp;
            file >> temp;
            parameters.push_back(temp);
        }
    }

    return parameters;
}

PacmanColors getColor(std::string color)
{
    if (color == "grey") {
        return PacmanColors::GREY;
    }
    if (color == "pink") {
        return PacmanColors::PINK;
    }
    if (color == "yellow") {
        return PacmanColors::YELLOW;
    }
    if (color == "green") {
        return PacmanColors::GREEN;
    }
}

std::string setColor(PacmanColors color)
{
    switch (color)
    {
    case PacmanColors::GREY:
        return "grey";
    case PacmanColors::PINK:
        return "pink";
    case PacmanColors::YELLOW:
        return "yellow";
    case PacmanColors::GREEN:
        return "green";
    }
}

PacmanControls getControls(std::string control)
{
    if (control == "arrows") {
        return PacmanControls::ARROWS;
    }
    if (control == "wasd") {
        return PacmanControls::WASD;
    }
}

std::string setControls(PacmanControls control)
{
    switch (control)
    {
    case PacmanControls::ARROWS:
        return "arrows";
    case PacmanControls::WASD:
        return "wasd";
    }
}

void writeParametersInFile(std::string fileName, std::vector<std::string> parameters)
{
    std::ofstream file(fileName);

    for (auto it : parameters) {
        file << (it + " ");
    }
}

void cScreen::clear()
{}

GameMode cScreen::_gameMode = GameMode::NONE;
std::vector<std::string> cScreen::_parameters = {};
bool cScreen::_isGameStart = false;
bool cScreen::_isNewLevel = false;
unsigned cScreen::_level = 1;
std::vector<sf::Vector2f> cScreen::_levelParameters = { {0.1, 0.095}, {0.1, 0.1}, {0.095, 0.1}, {0.095, 0.105} };
unsigned cScreen::_firstPlayerScore = 0;
unsigned cScreen::_secondPlayerScore = 0;
std::string cScreen::_winner = "";
