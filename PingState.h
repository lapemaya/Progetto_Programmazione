//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_PINGSTATE_H
#define GIOCO2_PINGSTATE_H
#include "State.h"
#include "Game.h"
#include "NullMenu.h"
#include "HeroAttackState.h"

class PingState:public State {
public:
    PingState(GameDataRef data);


    virtual ~PingState();

    void Update() override;
    void Init() override;

    void HandleInput()override;

    void Draw() override;

    void creationPing(int N,std::vector<Ping*> &V);
    void drawPings(std::vector<Ping*> &V);
    void clickPing(std::vector<Ping*> &V);
private:
    GameDataRef data;
    sf::Time time1;
    sf::Clock clock1;
    sf::Text* text1;
    sf::Text* text2;
    sf::Text* text3;
    bool end=false;

};


#endif //GIOCO2_PINGSTATE_H
