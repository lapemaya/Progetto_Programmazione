//
// Created by lapo on 10/06/22.
//

#include "DedState.h"

DedState::DedState(GameDataRef data) {
    this->data=data;
}

DedState::~DedState() {

}

void DedState::Update() {

}

void DedState::Init() {
    delete data->menu;
    data->menu=new DedMenu();
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void DedState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((200 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (300 * data->width) / 1080, globalPosition)) {
                delete data->heroptr;
                delete data->enemyptr;
                data->level = 1;
                this->data->machine.setNewState(StateRef(new ClassMenuState(data)));
                this->data->machine.setReplace(true);
            }
            if (data->input.response((1200 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (300 * data->width) / 1080, globalPosition)) {
                this->data->window.close();

            }
        }
    }
}
void DedState::Draw() {
data->window.draw(*data->menu);
}
