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
    Posx=0;
    Posy=0;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/ping.png");
    this->setTexture(*texture);
}
void Ping::Draw(sf::RenderWindow &finestra) {
    finestra.draw(*this);
}

Ping::~Ping() {

}
