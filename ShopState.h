//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_SHOPSTATE_H
#define GIOCO2_SHOPSTATE_H
#include "State.h"
#include "Game.h"
#include "ShopMenu.h"
#include "StatState.h"

class ShopState:public State {

public:
    ShopState(GameDataRef data);


    virtual ~ShopState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;

    void creationToolGeneral();
    Tool* creationTool();
    bool canPay(int N);
private:
    GameDataRef data;
};


#endif //GIOCO2_SHOPSTATE_H
