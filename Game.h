//
// Created by lapo on 08/06/22.
//

#ifndef GIOCO2_GAME_H
#define GIOCO2_GAME_H
#pragma once

#include <memory>
#include"SFML/Graphics.hpp"
#include "StateMachine.h"
#include "InputManager.h"
#include "Menu.h"
#include "Hero.h"
#include "Enemy.h"
#include "Ping.h"
    struct GameData {
        StateMachine machine;
        sf::RenderWindow window;
        float lenght;
        float width;
        Menu* menu;
        InputManager input;
        Hero* heroptr;
        Enemy* enemyptr;
        int level=1;
        std::vector<Ping*> V;
        std::vector<Tool*> Vtool;
        int bye=0;
        int PingHit;
        bool again=false;
        bool first=true;
        bool prima=true;
    };

    typedef std::shared_ptr<GameData> GameDataRef;

    class Game {
    public:
        explicit Game();

        void Run();

    private:


        GameDataRef data = std::make_shared<GameData>();


    };


#endif //GIOCO2_GAME_H
