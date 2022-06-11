//
// Created by lapo on 10/06/22.
//

#include "StatState.h"

StatState::StatState(GameDataRef data) {
this->data=data;
}

StatState::~StatState() {

}

void StatState::Update() {

}

void StatState::Init() {
    delete data->menu;
    data->menu=new StatMenu;

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void StatState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int quale;
            if (data->input.response((500 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                quale = 0;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
            }
            if (data->input.response((900 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                quale = 1;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
            }
            if (data->input.response((1300 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                quale = 2;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
            }
            if (data->input.response((775 * data->lenght) / 1920, (900 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (100 * data->width) / 1080, globalPosition)) {
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());

            }
        }
        }

}

void StatState::Draw() {
    data->window.draw(*data->menu);

}
