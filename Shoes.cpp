//
// Created by lapo on 09/06/22.
//

#include "Shoes.h"

Shoes::Shoes() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/scarpa.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosx(1300);
    this->setPosy(300);
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
    this->type=1;
    this->rarity=0;
    bonus=1;
    auto description1=new std::string ;
    *description1="Stamina UP";
    description=description1;


}

Shoes::~Shoes() {

}

Shoes::Shoes(const Tool &tool) : Tool(tool) {
    bonus=1;

    this->rarity=tool.getRarity();
    this->posx=tool.getPosx();
    this->posy=tool.getPosy();
    this->bonus=tool.getBonus();
    this->type=tool.getType();
    this->cost=tool.getCost();
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/scarpa.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(32*rarity, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
}
