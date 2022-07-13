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
    sf::Text* text1;
    sf::Text* text2;
    sf::Text* text3;
    sf::Text* text4;
    sf::Text* text5;
    sf::Text* text6;
    sf::Text* text7;
};
#endif //GIOCO2_LOOTSTATE_H
