//
// Created by lapo on 09/06/22.
//

#include "Torso.h"
Torso::~Torso() {

}

Torso::Torso() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/torso.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosx(1000);
    this->setPosy(300);
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
    bonus=15;
    this->type=0;
    this->rarity=0;
    auto description1=new std::string ;
    *description1="Hp UP";
    description=description1;
}

Torso::Torso(const Tool &tool) : Tool(tool) {
    bonus=tool.getBonus();
    this->rarity=tool.getRarity();
    this->posx=tool.getPosx();
    this->posy=tool.getPosy();
    this->bonus=tool.getBonus();
    this->type=tool.getType();
    this->cost=tool.getCost();
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/torso.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(32*rarity, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
}