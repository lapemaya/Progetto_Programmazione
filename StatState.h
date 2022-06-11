//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_STATSTATE_H
#define GIOCO2_STATSTATE_H
#include "StatMenu.h"
#include "State.h"
#include "Game.h"
#include "AttackMenuState.h"

class StatState:public State {

public:
    StatState(GameDataRef data);


    virtual ~StatState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;
private:
    GameDataRef data;
};


#endif //GIOCO2_STATSTATE_H
