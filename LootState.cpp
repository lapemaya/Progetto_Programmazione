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
    if(data->first) {
        creationToolGeneral();
        data->first=false;
    }
delete data->menu;
data->menu=new LootMenu;

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void LootState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {

            if (data->input.response((500 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                auto tool = data->Vtool.at(0);
                data->heroptr->changeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
            }
            if (data->input.response((900 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                auto tool = data->Vtool.at(1);
                data->heroptr->changeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
            }
            if (data->input.response((1300 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                auto tool = data->Vtool.at(2);
                data->heroptr->changeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
            }
            if (data->input.response((775 * data->lenght) / 1920, (900 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (100 * data->width) / 1080, globalPosition)) {

                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setMoney(data->heroptr->getMoney() + 10);
                data->first=true;
                data->prima=false;
            }
            if (data->input.response((1300 * data->lenght) / 1920, (200 * data->width) / 1080,
                                     (300 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {

                this->data->machine.setNewState(StateRef(new HeroCheckState(data)));
                this->data->machine.setReplace(true);
            }
        }
        }
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