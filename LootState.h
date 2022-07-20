//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_LOOTSTATE_H
#define GIOCO2_LOOTSTATE_H

#include "State.h"
#include "Game.h"
#include "ShopState.h"
#include "HeroCheckState.h"
#include "ToolInterface.h"
class LootState:public State {
public:
    LootState(GameDataRef data);
    virtual ~LootState();

    void Update() override;
    void Init() override;
    void HandleInput()override;
    void Draw() override;
private:
    GameDataRef data;

    std::vector<sf::Text*>Vtext;
};
#endif //GIOCO2_LOOTSTATE_H
