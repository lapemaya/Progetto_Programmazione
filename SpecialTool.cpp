//
// Created by lapo on 09/06/22.
//

#include "SpecialTool.h"

SpecialTool::SpecialTool(int N) {
    Bonus=2;
    Type=3;
    description=new std::string ;
    *description="Strenght UP";

    if(N==2) {
        auto texture = new sf::Texture;
        texture->loadFromFile("./sprite/Tools/sword.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx, Posy);
        this->setScale(6.25, 6.25);
        this->Special = 2;
    }
    if(N==0){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/wand.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
        this->setScale(6.25,6.25);
        this->Special=0;
    }
    if(N==1){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/nature.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
        this->setScale(6.25,6.25);
        this->Special=1;
    }
}
SpecialTool::SpecialTool(const Tool &tool,int O) {
    this->Rarity=tool.getRarity();
    this->Posx=tool.getPosx();
    this->Posy=tool.getPosy();
    this->Bonus=tool.getBonus();
    this->Type=tool.getType();
    Bonus=tool.getBonus();
    this->setScale(6.25,6.25);
    Type=3;
    if(O==0){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/wand.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
        Special=O;
    }
    if(O==1){
        auto texture=new sf::Texture;
        texture->loadFromFile("./sprite/Tools/nature.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
        Special=O;
    }
    if(O==2){
        auto texture = new sf::Texture;
        texture->loadFromFile("./sprite/Tools/sword.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(600);
        this->setPosition(Posx, Posy);
        Special=O;
    }
}
SpecialTool::~SpecialTool() {
delete description;
}
