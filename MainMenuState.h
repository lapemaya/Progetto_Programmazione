//
// Created by lapo on 08/06/22.
//

#ifndef GIOCO2_MAINMENUSTATE_H
#define GIOCO2_MAINMENUSTATE_H

#include "State.h"
#include "Game.h"
#include "ClassMenuState.h"
class MainMenuState:public State {
public:
    MainMenuState(GameDataRef data);
    virtual ~MainMenuState();

    void Update() override;
    void Init() override;
     void HandleInput()override;
     void Draw() override;
private:
    GameDataRef data;

    std::vector<sf::Text*>Vtext;
};
#endif //GIOCO2_MAINMENUSTATE_H
