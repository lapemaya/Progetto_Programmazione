//
// Created by lapo on 09/06/22.
//

#include "Tool.h"
Tool::~Tool() {

}

Tool::Tool() {
    if(rarity==1)
        this->cost=5;
    if(rarity==2)
        cost=10;
    if(rarity==3)
        cost=20;
    if(rarity==4)
        cost=40;
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
    bonus=tool.getBonus();
    this->rarity=tool.rarity;
    this->posx=tool.posx;
    this->posy=tool.posy;
    this->bonus=tool.bonus;
    this->type=tool.type;
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