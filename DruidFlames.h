//
// Created by lapo on 14/06/22.
//

#ifndef GIOCO2_DRUIDFLAMES_H
#define GIOCO2_DRUIDFLAMES_H


#include "SFML/Graphics.hpp"

class DruidFlames:public sf::Sprite {
public:
    DruidFlames(int x,int y);
    DruidFlames();

    virtual ~DruidFlames();
private:
    int posx;
    int posy;

};


#endif //GIOCO2_DRUIDFLAMES_H
