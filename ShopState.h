//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_SHOPSTATE_H
#define GIOCO2_SHOPSTATE_H

#include "State.h"
#include "Game.h"
#include "StatState.h"
class ShopState:public State {
public:
    ShopState(GameDataRef data);
    virtual ~ShopState();

    void Update() override;
    void Init() override;
    void HandleInput()override;
    void Draw() override;

    bool CanPay(int N);
private:
    GameDataRef data;

    std::vector<sf::Text*>Vtext;
};


#endif //GIOCO2_SHOPSTATE_H
