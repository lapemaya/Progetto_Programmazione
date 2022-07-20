//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_HEROATTACKSTATE_H
#define GIOCO2_HEROATTACKSTATE_H

#include "State.h"
#include "Game.h"
#include "EnemyAttackState.h"
#include "LootState.h"
class HeroAttackState:public State {
public:
    HeroAttackState(GameDataRef data);
    virtual ~HeroAttackState();

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
    std::vector<sf::Text*>Vtext;
};


#endif //GIOCO2_HEROATTACKSTATE_H
