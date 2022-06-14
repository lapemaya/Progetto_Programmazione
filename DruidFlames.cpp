//
// Created by lapo on 14/06/22.
//

#include "DruidFlames.h"

DruidFlames::~DruidFlames() {

}

DruidFlames::DruidFlames(int x, int y) {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/druidflames.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(x,y);
    this->setScale(6.25,6.25);
    posx=x;
    posy=y;

}

DruidFlames::DruidFlames() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/druidflames.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);
}
