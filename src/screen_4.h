#pragma once

#include <iostream>
#include "cScreen.h"

#include "map.h"
#include "pacman.h"
#include "ghost.h"
#include "gameInteraction.h"

#include <SFML/Graphics.hpp>

class game_screen_duo : public cScreen
{
public:
    //game_screen();
    virtual int Run(sf::RenderWindow& window);
private:

};

//game_screen::game_screen()
//{
//    
//}
