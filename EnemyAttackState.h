//
// Created by lapo on 10/06/22.
//

#ifndef GIOCO2_ENEMYATTACKSTATE_H
#define GIOCO2_ENEMYATTACKSTATE_H
#include "State.h"
#include "Game.h"
#include "DedState.h"

class EnemyAttackState:public State {
public:
    EnemyAttackState(GameDataRef data);
    virtual ~EnemyAttackState();

    void Update() override;
    void Init() override;
    void HandleInput()override;
    void Draw() override;
private:
    GameDataRef data;
    sf::Sprite* explosion;
    int Damage=0;
    bool IsExplosion=false;
    int CountExplosion=0;
    sf::Time time1;
    sf::Clock clock1;
    sf::Text* text1;
};


#endif //GIOCO2_ENEMYATTACKSTATE_H
