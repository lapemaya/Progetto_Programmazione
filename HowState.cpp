//
// Created by lapo on 11/06/22.
//

#include "HowState.h"
#include "MainMenuState.h"

HowState::HowState(GameDataRef data) {
this->data=data;
}
HowState::~HowState() {
}
void HowState::Update() {
if(data->bye>=6){
    this->data->machine.setNewState(StateRef(new MainMenuState(data)));
    this->data->machine.setReplace(true);
    data->bye=0;
}
}
void HowState::Init() {
delete data->menu;
data->menu=new HowMenu;
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}
void HowState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((1670 * data->lenght) / 1920, (830 * data->width) / 1080,
                                     (250 * data->lenght) / 1920, (250 * data->width) / 1080)) {
                data->bye++;
                data->menu->setTextureRect(sf::IntRect(1920* data->bye, 0, 1920, 1080) );
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((0 * data->lenght) / 1920, (830 * data->width) / 1080,
                                     (250 * data->lenght) / 1920, (250 * data->width) / 1080)) {
                data->bye--;
                data->menu->setTextureRect(sf::IntRect(1920* data->bye, 0, 1920, 1080) );
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((0 * data->lenght) / 1920, (0 * data->width) / 1080,
                                     (250 * data->lenght) / 1920, (250 * data->width) / 1080)) {
                data->bye=6;
                data->music3.stop();
                data->music3.play();
            }
        }
        }
}
void HowState::Draw() {
data->window.draw(*data->menu);
}
