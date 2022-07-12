//
// Created by lapo on 14/06/22.
//

#ifndef GIOCO2_DRUID_H
#define GIOCO2_DRUID_H


#include "Hero.h"


class Druid:public Hero {
public:
    Druid();
    virtual ~Druid();

    void attackAnimation() override;
    void drawHero(sf::RenderWindow &finestra)override;
    void resetBonus()override;
     int Attack()override;



private:
    std::vector<sf::Sprite*> Vd;

    sf::Sprite* leaf;
    SpecialTool* nature;
    int transform=0;
};

#endif //GIOCO2_DRUID_H
