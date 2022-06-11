//
// Created by lapo on 09/06/22.
//

#include "ClassMenuState.h"


ClassMenuState::ClassMenuState(GameDataRef data) {
    this->data=data;
}

ClassMenuState::~ClassMenuState() {

}

void ClassMenuState::Update() {

}

void ClassMenuState::Init() {
    delete data->menu;
    data->menu=new ClassMenu();


    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void ClassMenuState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {

            if (data->input.response((100 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080, globalPosition)) {
                //TODO mage

            }
            if (data->input.response((730 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080, globalPosition)) {
                //TODO knight
               data-> heroptr=new Knight;
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);


            }
            if (data->input.response((1350 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080, globalPosition)) {
                //TODO Druid

            }
            }
        }
        }




void ClassMenuState::Draw() {
    this->data->window.draw(*data->menu);
}

