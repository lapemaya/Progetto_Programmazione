//
// Created by lapo on 11/06/22.
//

#include "HowMenu.h"

HowMenu::~HowMenu() {}
HowMenu::HowMenu() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/howMenu.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
}
