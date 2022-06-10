//
// Created by lapo on 09/06/22.
//

#include "Ping.h"

Ping::Ping(int posx,int posy){
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/ping.png");
    this->setTexture(*texture);

}

Ping::Ping(){
    posx=0;
    posy=0;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/ping.png");
    this->setTexture(*texture);

}



void Ping::drawMe(sf::RenderWindow &finestra) {
    finestra.draw(*this);

}
