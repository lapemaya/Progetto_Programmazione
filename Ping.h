//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_PING_H
#define GIOCO2_PING_H


#include "SFML/Graphics.hpp"

class Ping:public sf::Sprite {
public:
    Ping(int posx,int posy);
    Ping();

    //virtual ~Ping();

    void drawMe(sf::RenderWindow &finestra);


    int getPosx() const {
        return posx;
    }

    void setPosx(int posx) {
        Ping::posx = posx;
    }

    int getPosy() const {
        return posy;
    }

    void setPosy(int posy) {
        Ping::posy = posy;
    }

private:
    int posx=0;
    int posy=0;



};


#endif //GIOCO2_PING_H
