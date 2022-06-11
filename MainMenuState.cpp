//
// Created by lapo on 08/06/22.
//
#include "iostream"
#include "MainMenuState.h"
#include "HowState.h"


void MainMenuState::Init() {

}

void MainMenuState::Draw() {
    this->data->window.draw(*data->menu);
}

MainMenuState::MainMenuState(GameDataRef data) {
    data->menu=new MainMenu();
    this->data=data;


    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

MainMenuState::~MainMenuState() {

}

void MainMenuState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (data->input.response((1400 * data->lenght) / 1920, (300 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    this->data->machine.setNewState(StateRef(new ClassMenuState(data)));
                    this->data->machine.setReplace(true);
                }
                if (data->input.response((1400 * data->lenght) / 1920, (700 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    this->data->window.close();
                }
                if (data->input.response((1400 * data->lenght) / 1920, (500 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    this->data->machine.setNewState(StateRef(new HowState(data)));
                    this->data->machine.setReplace(true);
                }
                }
            }
        }
    }


void MainMenuState::Update() {

}
