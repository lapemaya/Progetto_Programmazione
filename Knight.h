//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_KNIGHT_H
#define GIOCO2_KNIGHT_H

#include "Hero.h"

class Knight:public Hero {
public:
    Knight();
    virtual ~Knight();
    int Attack()override;
    void AttackAnimation() override;
    virtual void Draw(sf::RenderWindow &finestra)override;
    void ResetBonus()override;
protected:
    bool Crit=false;
    sf::Sprite* swordA;
};


#endif //GIOCO2_KNIGHT_H
