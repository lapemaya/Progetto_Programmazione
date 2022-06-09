//
// Created by lapo on 09/06/22.
//

#include "Anello.h"
Anello::~Anello() {

}



Anello::Anello() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/anello.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosx(1000);
    this->setPosy(600);
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
    this->setBonus(1);
    this->type=2;
    this->rarity=0;
    auto description1=new std::string ;
    *description1="Ping UP";
    description=description1;
}

Anello::Anello(const Tool &tool) : Tool(tool) {
    bonus=tool.getBonus();
    this->rarity=tool.getRarity();
    this->posx=tool.getPosx();
    this->posy=tool.getPosy();
    this->bonus=tool.getBonus();
    this->type=tool.getType();
    this->cost=tool.getCost();
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/anello.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(32*rarity, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
}