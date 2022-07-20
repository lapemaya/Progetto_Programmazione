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

    virtual ~Ping();

    void Draw(sf::RenderWindow &finestra);
    int getPosx() const {
        return Posx;
    }
    void setPosx(int Posx) {
        Ping::Posx = Posx;
    }
    int getPosy() const {
        return Posy;
    }
    void setPosy(int Posy) {
        Ping::Posy = Posy;
    }
private:
    int Posx=0;
    int Posy=0;
};
#endif //GIOCO2_PING_H
