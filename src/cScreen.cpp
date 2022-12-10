#include "cScreen.h"

std::vector<std::string> readParametersFromFile(std::string fileName)
{
    std::ifstream file(fileName, std::ios::out | std::ios::app);

    std::vector<std::string> parameters;

    if (file.peek() == EOF) {
        return std::vector<std::string>{ "player", "yellow", "arrows", "player2", "blue", "wasd" };
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
    if (color == "blue") {
        return PacmanColors::BLUE;
    }
    if (color == "red") {
        return PacmanColors::RED;
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
    case PacmanColors::BLUE:
        return "blue";
    case PacmanColors::RED:
        return "red";
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


GameMode cScreen::_gameMode = GameMode::NONE;
std::vector<std::string> cScreen::_parameters = {};