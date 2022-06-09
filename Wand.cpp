//
// Created by lapo on 09/06/22.
//

#include "Wand.h"

Wand::~Wand() {

}

Wand::Wand() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/wand.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosx(1300);
    this->setPosy(600);
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
    special=0;
}

Wand::Wand(const SpecialTool &specialTool) {
    this->rarity=specialTool.getRarity();
    this->posx=specialTool.getPosx();
    this->posy=specialTool.getPosy();
    this->bonus=specialTool.getBonus();
    this->type=specialTool.getType();
    this->cost=specialTool.getCost();
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Tools/wand.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(32*rarity, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(6.25,6.25);
    special=0;
}
