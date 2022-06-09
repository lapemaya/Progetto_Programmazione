//
// Created by lapo on 09/06/22.
//

#include "AttackMenu.h"

AttackMenu::~AttackMenu() {

}

AttackMenu::AttackMenu() {
    this->posx=0;
    this->posy=0;
    this->distx=1920;
    this->disty=1080;

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/attack.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    this->setPosition(posx,posy);
}
