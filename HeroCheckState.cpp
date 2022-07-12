//
// Created by lapo on 10/06/22.
//

#include "HeroCheckState.h"
#include "LootState.h"

HeroCheckState::HeroCheckState(GameDataRef data) {
this->data=data;
}

HeroCheckState::~HeroCheckState() {

}

void HeroCheckState::Update() {

}

void HeroCheckState::Init() {
    data->menu->setTextureRect(sf::IntRect(1920*2,1080,1920,1080));

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));

}

void HeroCheckState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if(data->prima){
                this->data->machine.setNewState(StateRef(new LootState(data)));
                this->data->machine.setReplace(true);
                data->music3.stop();
                data->music3.play();
            }
            else{
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->music3.stop();
                data->music3.play();
            }
        }
        }
}

void HeroCheckState::Draw() {
    data->window.draw(*data->menu);
    data->heroptr->setPosition((500*data->lenght)/1920,(400*data->width)/1080);
    data->heroptr->drawHero(data->window);
    data->window.draw(*data->heroptr->getTorso());
    data->window.draw(*data->heroptr->getRing());
    data->window.draw(*data->heroptr->getShoes());
    data->window.draw(*data->heroptr->getSpecialTool());
}
