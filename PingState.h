//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_PINGSTATE_H
#define GIOCO2_PINGSTATE_H

#include "State.h"
#include "Game.h"
#include "HeroAttackState.h"
class PingState:public State {
public:
    PingState(GameDataRef data);
    virtual ~PingState();

    void Update() override;
    void Init() override;
    void HandleInput()override;
    void Draw() override;

    void CreationPing(int N,std::vector<Ping*> &V);
    void DrawPings(std::vector<Ping*> &V);
    void ClickPing();
private:
    GameDataRef data;
    sf::Time time1;
    sf::Clock clock1;

    std::vector<sf::Text*>Vtext;
    bool End=false;
    bool Hit=false;
    int Quale=0;
};
#endif //GIOCO2_PINGSTATE_H
