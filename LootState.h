//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_LOOTSTATE_H
#define GIOCO2_LOOTSTATE_H
#include "State.h"
#include "Game.h"
#include "LootMenu.h"

class LootState:public State {

public:
    LootState(GameDataRef data);


    virtual ~LootState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;
    void creationToolGeneral();
    Tool* creationTool();
private:
    GameDataRef data;
};


#endif //GIOCO2_LOOTSTATE_H
