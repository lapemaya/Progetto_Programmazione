//
// Created by lapo on 09/06/22.
//

#include "AttackMenuState.h"

AttackMenuState::AttackMenuState(GameDataRef data) {
    this->data=data;
}

void AttackMenuState::Init() {
    delete data->menu;
    data->menu=new AttackMenu();

    creationEnemy();
    data->heroptr->setPosx((data->heroptr->getPosx()*data->lenght)/1920);
    data->heroptr->setPosx((data->heroptr->getPosx()*data->width)/1080);
    data->heroptr->setPosition(data->heroptr->getPosx(),data->heroptr->getPosy());
    data->heroptr->setScale(((12.5*data->lenght)/1920),((12.5*data->width)/1080));

    data->enemyptr->setPosx(data->lenght-((data->lenght*(1920-data->enemyptr->getPosx()))/1920));
    data->enemyptr->setPosx((data->enemyptr->getPosx()*data->width)/1080);
    data->enemyptr->setPosition(data->enemyptr->getPosx(),data->enemyptr->getPosy());
    data->enemyptr->setScale(((12.5*data->lenght)/1920),((12.5*data->width)/1080));

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
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
}

void AttackMenuState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*data->heroptr);
    data->window.draw(*data->enemyptr);


}

void AttackMenuState::creationEnemy() {
    int random=rand()%3;

    if(random==0){
        data->enemyptr=new Goblin(data->level);}
    if(random==1){
        data->enemyptr=new Rat(data->level);}
    if(random==2){
        data->enemyptr=new Dragon(data->level);}
}
