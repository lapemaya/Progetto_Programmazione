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
    sf::Text* text1;
    sf::Text* text2;
    sf::Text* text3;
    sf::Text* text4;
    sf::Text* text5;
    sf::Text* text6;
    sf::Text* text7;
    sf::Text* text8;
    sf::Text* text9;
    sf::Text* text10;
};


#endif //GIOCO2_SHOPSTATE_H
