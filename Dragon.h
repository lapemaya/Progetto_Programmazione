//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_DRAGON_H
#define GIOCO2_DRAGON_H

#include "Enemy.h"
#include "Fireball.h"
class Dragon:public Enemy {
public:
    Dragon(int level);
    virtual ~Dragon();

    virtual void AttackAnimation()override;
    void Draw(sf::RenderWindow &finestra)override;
private:
    Fireball* fireptr;
    bool InAttack=false;
};


#endif //GIOCO2_DRAGON_H
