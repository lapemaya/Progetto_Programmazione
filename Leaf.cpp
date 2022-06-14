//
// Created by lapo on 14/06/22.
//

#include "Leaf.h"

Leaf::~Leaf() {

}

Leaf::Leaf() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/leaf.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);
}

