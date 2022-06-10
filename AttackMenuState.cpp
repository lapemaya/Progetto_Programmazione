//
// Created by lapo on 09/06/22.
//

#include "AttackMenuState.h"
#include "iostream"
AttackMenuState::AttackMenuState(GameDataRef data) {
    this->data=data;
}

void AttackMenuState::Init() {
    delete data->menu;
    data->menu=new AttackMenu();
    data->menu->setScale(((1 * data->lenght) / 1920), ((1 * data->width) / 1080));
    if(data->first){
        data->first=false;
        data->heroptr->setPosx((data->heroptr->getPosx() * data->lenght) / 1920);
        data->heroptr->setPosx((data->heroptr->getPosx() * data->width) / 1080);
        data->heroptr->setPosition(data->heroptr->getPosx(), data->heroptr->getPosy());
        data->heroptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));

        data->enemyptr->setPosx(data->lenght - ((data->lenght * (1920 - data->enemyptr->getPosx())) / 1920));
        data->enemyptr->setPosx((data->enemyptr->getPosx() * data->width) / 1080);
        data->enemyptr->setPosition(data->enemyptr->getPosx(), data->enemyptr->getPosy());
        data->enemyptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));
    }
    if(data->again== true) {
        data->again=false;
    }
}

AttackMenuState::~AttackMenuState() {

}

void AttackMenuState::Update() {

}

void AttackMenuState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((1000 * data->lenght) / 1920, (400 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                //regen
                data->heroptr->regen();
                data->heroptr->setHasLight(false);

                this->data->machine.setNewState(StateRef(new EnemyAttackState(data)));
                this->data->machine.setReplace(true);

            }
            if(data->heroptr->canAttack()) {
                if (data->input.response((800 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    //normal

                    data->heroptr->setAttack(0);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                }
                if (data->input.response((800 * data->lenght) / 1920, (400 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    if(data->heroptr->isHasLight()==false) {
                        //light
                        data->heroptr->setAttack(1);
                        this->data->machine.setNewState(StateRef(new PingState(data)));
                        this->data->machine.setReplace(true);
                    }
                }
                if (data->input.response((1000 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                    //strong
                    data->heroptr->setAttack(2);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                }
                }
            }
        }
}

void AttackMenuState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*data->heroptr);
    data->window.draw(*data->enemyptr);


}


