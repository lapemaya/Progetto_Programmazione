//
// Created by lapo on 11/06/22.
//

#ifndef GIOCO2_HOWSTATE_H
#define GIOCO2_HOWSTATE_H

#include "Game.h"
#include "State.h"
#include "HowMenu.h"
class HowState:public State {
public:
    HowState(GameDataRef data);
    virtual ~HowState();

    void Update() override;
    void Init() override;
    void HandleInput() override;
    void Draw() override;
private:
    GameDataRef data;
};
#endif //GIOCO2_HOWSTATE_H
