//
// Created by lapo on 08/06/22.
//

#include "MainMenu.h"

MainMenu::MainMenu() {
    this->posx=0;
    this->posy=0;
    this->distx=1920;
    this->disty=1080;

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Menu/main.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 1920, 1080));
    this->setPosition(posx,posy);
}

MainMenu::~MainMenu() {

}
