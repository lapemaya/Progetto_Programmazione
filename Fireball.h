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
        return Posx;
    }
    void setPosx(int Posx) {
        Fireball::Posx = Posx;
    }
    int getPosy() const {
        return Posy;
    }
    void setPosy(int Posy) {
        Fireball::Posy = Posy;
    }
protected:
    int Posx=300;
    int Posy=400;
};

#endif //GIOCO2_FIREBALL_H
