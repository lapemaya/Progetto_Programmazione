//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_FIREBALL_H
#define GIOCO2_FIREBALL_H


#include <SFML/Graphics.hpp>

class Fireball:public sf::Sprite {
public:

    Fireball(int posx=300,int posy=400);
    virtual ~Fireball();

    int getPosx() const {
        return posx;
    }

    void setPosx(int posx) {
        Fireball::posx = posx;
    }

    int getPosy() const {
        return posy;
    }

    void setPosy(int posy) {
        Fireball::posy = posy;
    }

protected:
    int posx=300;
    int posy=400;

};

#endif //GIOCO2_FIREBALL_H
