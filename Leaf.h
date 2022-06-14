//
// Created by lapo on 14/06/22.
//

#ifndef GIOCO2_LEAF_H
#define GIOCO2_LEAF_H


#include "SFML/Graphics.hpp"

class Leaf: public sf::Sprite{
public:
    Leaf();

    virtual ~Leaf();



    int getPosx() const {
        return posx;
    }

    void setPosx(int posx) {
        Leaf::posx = posx;
    }

    int getPosy() const {
        return posy;
    }

    void setPosy(int posy) {
        Leaf::posy = posy;
    }

private:
    int posy=1080;
    int posx=1400;
};


#endif //GIOCO2_LEAF_H
