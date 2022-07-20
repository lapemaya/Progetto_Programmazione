//
// Created by lapo on 20/07/22.
//

#ifndef GIOCO2_KILLSACHIVEMENT_H
#define GIOCO2_KILLSACHIVEMENT_H
#include "Observer.h"
#include "Hero.h"

class KillsAchivement: public Observer{
public:
    KillsAchivement(Hero* hero);
    virtual ~KillsAchivement();

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


#endif //GIOCO2_KILLSACHIVEMENT_H
