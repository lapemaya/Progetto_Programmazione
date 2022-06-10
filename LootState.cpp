//
// Created by lapo on 10/06/22.
//

#include "LootState.h"

LootState::LootState(GameDataRef data) {
this->data=data;
}

LootState::~LootState() {

}

void LootState::Update() {

}

void LootState::Init() {
creationToolGeneral();
delete data->menu;
data->menu=new LootMenu;
}

void LootState::HandleInput() {

}

void LootState::Draw() {
    data->window.draw(*data->menu);
    for(int i=0;i<3;i++) {
        data->window.draw(*(data->Vtool.at(i)));
        }
}

void LootState::creationToolGeneral() {
    for (int i = 0; i < 3; i++) {
        Tool *tool = creationTool();
        tool->setPosx(500 + 400 * i);
        tool->setPosy(600);
        tool->setPosition(tool->getPosx(), tool->getPosy());
        tool->setTextureRect(sf::IntRect(tool->getRarity() * 32, 0, 32, 32));
        data->Vtool.push_back(tool);
    }

}
Tool* LootState::creationTool(){
    int N = rand() % 4;
    if (N == 0) {
        auto tool = new Torso();
        tool->chooseRarityFirst();
        return tool;
    }
    if (N == 1) {
        auto tool = new Shoes();
        tool->chooseRarityFirst();
        return tool;
    }
    if (N == 2) {
        auto tool = new Anello();
        tool->chooseRarityFirst();
        return tool;
    }
    if (N == 3) {
        if (data->heroptr->getSpecialTool()->getSpecial() == 0) {
            auto tool = new Wand;
            tool->chooseRarityFirst();
            return tool;
        }
        if (data->heroptr->getSpecialTool()->getSpecial() == 1) {
            auto tool = new Nature;
            tool->chooseRarityFirst();
            return tool;

        }
        if (data->heroptr->getSpecialTool()->getSpecial() == 2) {
            auto tool = new Sword;
            tool->chooseRarityFirst();
            return tool;
        }
    }
}