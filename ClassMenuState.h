//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_CLASSMENUSTATE_H
#define GIOCO2_CLASSMENUSTATE_H

#include "State.h"
#include "Game.h"
#include "Knight.h"
#include "Mage.h"
#include "Druid.h"
#include "AttackMenuState.h"
class ClassMenuState:public State {
public:
    ClassMenuState(GameDataRef data);
    virtual ~ClassMenuState();

    void Update() override;
    void Init() override;
    void HandleInput()override;
    void Draw() override;
private:
    GameDataRef data;

    std::vector<sf::Text*>Vtext;
};


#endif //GIOCO2_CLASSMENUSTATE_H
