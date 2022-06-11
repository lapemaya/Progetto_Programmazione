//
// Created by lapo on 10/06/22.
//

#include "ShopMenu.h"

ShopMenu::~ShopMenu() {

}

ShopMenu::ShopMenu() {
    this->posx=0;
    this->posy=0;

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/shopMenu.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    this->setPosition(posx,posy);
}
