//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_RAT_H
#define GIOCO2_RAT_H

#include "Enemy.h"

class Rat: public Enemy {
public:
    Rat(int N);
    virtual ~Rat();

    virtual void AttackAnimation()override;
};


#endif //GIOCO2_RAT_H
