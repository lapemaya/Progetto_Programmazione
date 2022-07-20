//
// Created by lapo on 20/07/22.
//

#ifndef GIOCO2_DAMAGEACHIVEMENT_H
#define GIOCO2_DAMAGEACHIVEMENT_H
#include "Observer.h"
#include "Hero.h"

class DamageAchivement: public Observer{
public:
     DamageAchivement(Hero* hero);
    virtual ~DamageAchivement();

    void Attach()override;
    void Update()override;
    void Detach()override;
    sf::Sprite* GetTrophie(){
        return trophie;
    }

private:
    Hero* subject;
    sf::Sprite* trophie;
};


#endif //GIOCO2_DAMAGEACHIVEMENT_H
