#include "screen_3.h"

int game_screen::Run(sf::RenderWindow& window)
{
    std::vector<Pacman*> pacmanVector;
        if (_gameMode != GameMode::DUO) {
            pacmanVector.push_back(new Pacman(_parameters[1], _parameters[2], 945, 780, 0.1));
        }
        else {
            pacmanVector.push_back(new Pacman(_parameters[1], _parameters[2], 925, 780, 0.1));
            pacmanVector.push_back(new Pacman(_parameters[4], _parameters[5], 965, 780, 0.1));
        }
    
        std::vector<Ghost*> ghostsVector;
        if (_gameMode != GameMode::TRAINING) {
            ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 14 * 30, 0.095, true));
            ghostsVector.push_back(new Ghost(13 * 30 + 540 + 15, 17 * 30, 0.095, false));
            ghostsVector.push_back(new Ghost(11 * 30 + 540 + 15, 17 * 30, 0.095, false));
            ghostsVector.push_back(new Ghost(15 * 30 + 540 + 15, 17 * 30, 0.095, false));
        }
    
        Map map;
    
        sf::Clock clock;
    
        while (window.isOpen())
        {
            float time = clock.getElapsedTime().asMicroseconds();
            clock.restart();
            time /= 800;
    
            int pointsEaten = 0;
            for (auto& player : pacmanVector) {
                pointsEaten += player->pointsEaten();
            }
    
            if (_gameMode != GameMode::TRAINING) {
                if (!ghostsVector[1]->isStart()) {
                    ghostsVector[1]->start();
                }
                if (!ghostsVector[2]->isStart() && pointsEaten > 30) {
                    ghostsVector[2]->start();
                }
                if (!ghostsVector[3]->isStart() && pointsEaten > 80) {
                    ghostsVector[3]->start();
                }
            }     
    
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
                    return 0;
                }
            }
    
            for (auto& player : pacmanVector) {
                player->checkKeys(map);
            }
            for (auto& player : pacmanVector) {
                player->update(time, map);
            }
            
            if (_gameMode == GameMode::SINGLE) {
                for (auto& ghost : ghostsVector) {
                    (*ghost).update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted(), map);
                }
    
                for (auto& ghost : ghostsVector) {
                    ghostAndPacmanInteraction((*pacmanVector[0]), (*ghost));
                }
            }
            if (_gameMode == GameMode::DUO) {
                ghostsVector[0]->update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
                ghostsVector[1]->update(time, pacmanVector[1]->getCoordinates(), pacmanVector[1]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
                ghostsVector[2]->update(time, pacmanVector[0]->getCoordinates(), pacmanVector[0]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
                ghostsVector[3]->update(time, pacmanVector[1]->getCoordinates(), pacmanVector[1]->getDirection(), pacmanVector[0]->isBoosted() || pacmanVector[1]->isBoosted(), map);
    
                for (auto& ghost : ghostsVector) {
                    ghostAndPacmanInteraction((*pacmanVector[0]), (*pacmanVector[1]), (*ghost));
                }
    
                pacmanAndPacmanInteraction((*pacmanVector[0]), (*pacmanVector[1]));
            }
    
            window.clear();
    
            map.drawMap(window);
    
            for (auto& player : pacmanVector) {
                window.draw(player->score());
            }
            for (auto& player : pacmanVector) {
                window.draw(player->lifes());
            }
            for (auto& player : pacmanVector) {
                window.draw(player->sprite());
            }
    
            for (auto& ghost : ghostsVector) {
                window.draw((*ghost).sprite());
            }
    
            window.display();
        }
    
        return 0;
}

//#include "screen_3.h"
//
//int game_screen::Run(sf::RenderWindow& window)
//{
//    Pacman pacman (_parameters[1], _parameters[2], 945, 780, 0.1);
//
//    Map map;
//
//    sf::Clock clock;
//
//    while (window.isOpen())
//    {
//        float time = clock.getElapsedTime().asMicroseconds();
//        clock.restart();
//        time /= 800;
//
//        sf::Event event;
//        while (window.pollEvent(event))
//        {
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
//                return 0;
//            }
//        }
//
//        pacman.checkKeys(map);
//        
//        pacman.update(time, map);
//
//        window.clear();
//
//        map.drawMap(window);
//
//        window.draw(pacman.score());
//        window.draw(pacman.lifes());
//        window.draw(pacman.sprite());
//
//        window.display();
//    }
//
//    return 0;
//}
