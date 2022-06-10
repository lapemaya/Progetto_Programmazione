//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_DEDSTATE_H
#define GIOCO2_DEDSTATE_H
#include "State.h"
#include "Game.h"
#include "DedMenu.h"
class DedState:public State {
public:
    DedState(GameDataRef data);


    virtual ~DedState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;
private:
    GameDataRef data;

};


#endif //GIOCO2_DEDSTATE_H
