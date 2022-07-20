//
// Created by lapo on 09/06/22.
//

#include "Tool.h"
Tool::~Tool() {
    delete description;
}
Tool::Tool(int N) {
    auto texture=new sf::Texture;
    this->setTexture(*texture);
    if(N==0){
        texture->loadFromFile("./sprite/Tools/torso.png");
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(300);
        this->setPosition(Posx,Posy);
        this->setScale(6.25,6.25);
        Bonus=15;
        this->Type=0;
        this->Rarity=0;
        description=new std::string ;
        *description="Hp UP";

    }
    if(N==1){
        texture->loadFromFile("./sprite/Tools/scarpa.png");
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(300);
        this->setPosition(Posx,Posy);
        this->setScale(6.25,6.25);
        this->Type=1;
        this->Rarity=0;
        Bonus=1;
        description=new std::string ;
        *description="Stamina UP";

    }
    if(N==2){
        texture->loadFromFile("./sprite/Tools/anello.png");
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
        this->setScale(6.25,6.25);
        this->setBonus(1);
        this->Type=2;
        this->Rarity=0;
        description=new std::string ;
        *description="Ping UP";

    }
}

void Tool::ChooseRarityFirst() {
    int N=rand()%100;
    if(N<=4) {
        this->Rarity = 4;
        this->Cost=160;
    }
    if(N>=5&&N<=19){
        this->Rarity=3;
        this->Cost=80;}
    if(N>=20&&N<=49){
        this->Rarity=2;
        this->Cost=20;}
    if(N>=50&&N<=99){
        this->Rarity=1;
        this->Cost=5;}
}
Tool::Tool(const Tool &tool) {
    auto texture=new sf::Texture;
    this->Rarity=tool.Rarity;
    this->Posx=tool.Posx;
    this->Posy=tool.Posy;
    this->Bonus=tool.Bonus;
    this->Type=tool.Type;
    if(Type==0){
        texture->loadFromFile("./sprite/Tools/torso.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(300);
        this->setPosition(Posx,Posy);
    }
    if(Type==1){
        texture->loadFromFile("./sprite/Tools/scarpa.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1300);
        this->setPosy(300);
        this->setPosition(Posx,Posy);
    }
    if(Type==2){
        texture->loadFromFile("./sprite/Tools/anello.png");
        this->setTexture(*texture);
        this->setTextureRect(sf::IntRect(Rarity*32, 0, 32, 32));
        this->setPosx(1000);
        this->setPosy(600);
        this->setPosition(Posx,Posy);
    }
    this->setScale(6.25,6.25);
}
void Tool::ChooseRaritySecond() {
    int N=rand()%9;
    if(N==0||N==1) {
        this->Rarity = 4;
        this->Cost=160;
    }
    if(N==2||N==3){
        this->Rarity=3;
        this->Cost=80;}
    if(N==4||N==5||N==6){
        this->Rarity=2;
        this->Cost=20;}
    if(N==7||N==8||N==9){
        this->Rarity=1;
        this->Cost=5;}
}
Tool::Tool() {

}

