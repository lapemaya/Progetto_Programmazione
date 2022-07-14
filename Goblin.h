//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_GOBLIN_H
#define GIOCO2_GOBLIN_H


#include "Enemy.h"

class Goblin: public Enemy{
public:
    Goblin(int N);
    virtual ~Goblin();

    virtual void AttackAnimation()override;
    virtual void Draw(sf::RenderWindow &finestra)const override;
protected:
    sf::Sprite* sprite;
};
#endif //GIOCO2_GOBLIN_H
