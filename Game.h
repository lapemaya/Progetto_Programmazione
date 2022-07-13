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
#include "ToolInterface.h"
#include "SFML/Audio.hpp"
    struct GameData {
        int level=1;
        int bye=0;
        int PingHit;
        float lenght;
        float width;
        bool again=false;
        bool first=true;
        bool prima=true;
        sf::Music music1;
        sf::Music music2;
        sf::Music music3;
        sf::Music music4;
        sf::RenderWindow window;
        StateMachine machine;
        Menu* menu;
        InputManager input;
        Hero* heroptr;
        Enemy* enemyptr;
        std::vector<Ping*> V;
        std::vector<Tool*> Vtool;
        ToolInterface toolInterface;
        sf::Font font;
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
