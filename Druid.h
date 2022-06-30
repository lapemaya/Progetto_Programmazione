//
// Created by lapo on 14/06/22.
//

#ifndef GIOCO2_DRUID_H
#define GIOCO2_DRUID_H


#include "Hero.h"
#include "Leaf.h"
#include "DruidFlames.h"

class Druid:public Hero {
public:
    Druid();
    virtual ~Druid();

    void attackAnimation() override;
    void drawHero(sf::RenderWindow &finestra)override;
    void resetBonus()override;
    virtual int Attack()override;



private:
    std::vector<DruidFlames*> Vd;

    Leaf* leaf;
    Nature* nature;
    int transform=0;
};

#endif //GIOCO2_DRUID_H
