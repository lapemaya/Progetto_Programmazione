//
// Created by lapo on 09/06/22.
//

#include "Fireball.h"

Fireball::~Fireball() {}
Fireball::Fireball(int posx,int posy) {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/fireball.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
}
