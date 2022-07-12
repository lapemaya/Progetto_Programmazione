//
// Created by lapo on 09/06/22.
//

#include "Tool.h"
Tool::~Tool() {

}

Tool::Tool(int N) {


    if(N==0){
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
    if(N==1){
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
    if(N==2){
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
}

void Tool::chooseRarityFirst() {
    int N=rand()%100;
    if(N<=4) {
        this->rarity = 4;
        this->cost=160;
    }
    if(N>=5&&N<=19){
        this->rarity=3;
        this->cost=80;}
    if(N>=20&&N<=49){
        this->rarity=2;
        this->cost=20;}
    if(N>=50&&N<=99){
        this->rarity=1;
        this->cost=5;}
}

Tool::Tool(const Tool &tool) {

    auto texture=new sf::Texture;

    this->rarity=tool.rarity;
    this->posx=tool.posx;
    this->posy=tool.posy;
    this->bonus=tool.bonus;
    this->type=tool.type;
    if(type==0){
        texture->loadFromFile("./sprite/Tools/torso.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(300);
        this->setPosition(posx,posy);
    }
    if(type==1){
        texture->loadFromFile("./sprite/Tools/scarpa.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(300);
        this->setPosition(posx,posy);
    }
    if(type==2){
        texture->loadFromFile("./sprite/Tools/anello.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(rarity*32, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(600);
        this->setPosition(posx,posy);
    }
    this->setScale(6.25,6.25);
}

void Tool::chooseRaritySecond() {
    int N=rand()%9;
    if(N==0||N==1) {
        this->rarity = 4;
        this->cost=160;
    }
    if(N==2||N==3){
        this->rarity=3;
        this->cost=80;}
    if(N==4||N==5||N==6){
        this->rarity=2;
        this->cost=20;}
    if(N==7||N==8||N==9){
        this->rarity=1;
        this->cost=5;}
}

Tool::Tool() {

}

