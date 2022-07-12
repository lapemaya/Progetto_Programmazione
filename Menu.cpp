//
// Created by lapo on 12/07/22.
//

#include "Menu.h"

Menu::Menu() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/Menu.png");
    this->setTexture(*texture);
}
