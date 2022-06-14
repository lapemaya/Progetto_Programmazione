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

    DruidFlames *getFlame1() const {
        return flame1;
    }

    void setFlame1(DruidFlames *flame1) {
        Druid::flame1 = flame1;
    }

    DruidFlames *getFlame2() const {
        return flame2;
    }

    void setFlame2(DruidFlames *flame2) {
        Druid::flame2 = flame2;
    }

    DruidFlames *getFlame3() const {
        return flame3;
    }

    void setFlame3(DruidFlames *flame3) {
        Druid::flame3 = flame3;
    }

private:
    DruidFlames* flame1;
    DruidFlames* flame2;
    DruidFlames* flame3;
    Leaf* leaf;
    Nature* nature;
    int transform=0;
};

#endif //GIOCO2_DRUID_H
