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

    void AttackAnimation() override;
    void Draw(sf::RenderWindow &finestra)const override;
    void ResetBonus()override;
     int Attack()override;
private:
    std::vector<sf::Sprite*> Vd;
    sf::Sprite* leaf;
    SpecialTool* nature;
    int Transform=0;
};
#endif //GIOCO2_DRUID_H
