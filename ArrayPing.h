//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_ARRAYPING_H
#define GIOCO2_ARRAYPING_H


#include "Ping.h"
#include "Game.h"

class ArrayPing {
public:
    ArrayPing();
    void creazione(int N,std::vector<Ping*> &V);
    void click(std::vector<Ping*> &V);
    void drawPing(sf::RenderWindow &finestra,std::vector<Ping*> V);
    void destroy(std::vector<Ping*> &V);


    int getBye() const {
        return bye;
    }

    void setBye(int bye) {
        ArrayPing::bye = bye;
    }

    int getPingHit() const {
        return pingHit;
    }

    void setPingHit(int pingHit) {
        ArrayPing::pingHit = pingHit;
    }

protected:
    int bye=0;
    int pingHit=0;
    GameDataRef data;

};


#endif //GIOCO2_ARRAYPING_H
