//
// Created by lapo on 10/06/22.
//

#include "HeroCheckMenu.h"
HeroCheckMenu::HeroCheckMenu() {
    this->posx=0;
    this->posy=0;

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/statMenu.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    this->setPosition(posx,posy);
}

HeroCheckMenu::~HeroCheckMenu() {

}
