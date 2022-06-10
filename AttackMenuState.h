//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_ATTACKMENUSTATE_H
#define GIOCO2_ATTACKMENUSTATE_H
#include "State.h"
#include "Game.h"
#include "AttackMenu.h"
#include "Goblin.h"
#include "Dragon.h"
#include "Rat.h"
#include "PingState.h"
class AttackMenuState:public State {
public:
    AttackMenuState(GameDataRef data);


    virtual ~AttackMenuState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;

private:
    GameDataRef data;

};


#endif //GIOCO2_ATTACKMENUSTATE_H
