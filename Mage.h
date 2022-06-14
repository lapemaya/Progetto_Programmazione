//
// Created by lapo on 14/06/22.
//

#ifndef GIOCO2_MAGE_H
#define GIOCO2_MAGE_H

#include "Hero.h"
#include "Fireball.h"

    class Mage:public Hero {
    public:
        Mage();

        virtual int Attack()override;
        void attackAnimation()override;
        void drawHero(sf::RenderWindow &finestra) override;
        void resetBonus()override;

        virtual ~Mage();



        Fireball *getFireptr() const {
            return fireptr;
        }

        void setFireptr(Fireball *fireptr) {
            Mage::fireptr = fireptr;
        }




    protected:

        Fireball* fireptr;
        int countPing=0;
        int aura=0;


};


#endif //GIOCO2_MAGE_H