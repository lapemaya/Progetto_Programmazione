//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_HEROCHECKSTATE_H
#define GIOCO2_HEROCHECKSTATE_H
#include "State.h"
#include "Game.h"
#include "HeroCheckMenu.h"

class HeroCheckState:public State {
public:
    HeroCheckState(GameDataRef data);


    virtual ~HeroCheckState();

    void Update() override;

    void Init() override;

    void HandleInput() override;

    void Draw() override;

private:
    GameDataRef data;
};
#endif //GIOCO2_HEROCHECKSTATE_H
