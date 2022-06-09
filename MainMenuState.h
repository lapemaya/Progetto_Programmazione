//
// Created by lapo on 08/06/22.
//

#ifndef GIOCO2_MAINMENUSTATE_H
#define GIOCO2_MAINMENUSTATE_H
#pragma once
#include "State.h"
#include "MainMenu.h"
#include "Game.h"
#include "ClassMenuState.h"

class MainMenuState:public State {
public:
    MainMenuState(GameDataRef data);


    virtual ~MainMenuState();

    void Update() override;
    void Init() override;

     void HandleInput()override;

     void Draw() override;
private:
    GameDataRef data;

};


#endif //GIOCO2_MAINMENUSTATE_H
