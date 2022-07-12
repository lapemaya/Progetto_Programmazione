//
// Created by lapo on 09/06/22.
//

#include "SpecialTool.h"


SpecialTool::SpecialTool(int N) {
    bonus=2;
    type=3;
    auto description1=new std::string ;
    *description1="Strenght UP";
    description=description1;
    if(N==2) {
        auto texture = new sf::Texture;
        texture->loadFromFile("./sprite/Tools/sword.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(posx, posy);
        this->setScale(6.25, 6.25);
        special = 2;
    }
    if(N==0){
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
    if(N==1){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/nature.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(posx,posy);
        this->setScale(6.25,6.25);

        special=1;
    }

}

SpecialTool::SpecialTool(const Tool &tool,int O) {
    this->rarity=tool.getRarity();
    this->posx=tool.getPosx();
    this->posy=tool.getPosy();
    this->bonus=tool.getBonus();
    this->type=tool.getType();
    bonus=tool.getBonus();
    this->setScale(6.25,6.25);
    type=3;
    if(O==0){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/wand.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(posx,posy);
    }
    if(O==1){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/nature.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(posx,posy);

    }
    if(O==2){
        auto texture = new sf::Texture;
        texture->loadFromFile("./sprite/Tools/sword.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(posx, posy);
    }


}

SpecialTool::~SpecialTool() {

}
