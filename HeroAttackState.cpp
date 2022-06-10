//
// Created by lapo on 09/06/22.
//

#include "HeroAttackState.h"

HeroAttackState::HeroAttackState(GameDataRef data) {
    this->data=data;
    auto explosion1=new sf::Sprite;
    explosion=explosion1;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/explosion.png");
    explosion->setTexture(*texture);
    explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
    explosion->setScale((12.5*data->lenght)/1920,(12.5*data->width)/1080);

}

HeroAttackState::~HeroAttackState() {
delete explosion;
}

void HeroAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if(data->heroptr->isAttackEnded()==false&&isExplosion==false){
        data->heroptr->attackAnimation();
    }
    if(data->heroptr->isAttackEnded()) {

        data->heroptr->setFaseAttack(0);
        data->heroptr->setCountAttack(0);

        //  RESET VETTORE PING(DESTROY)
        data->heroptr->setPingHit(data->PingHit);

        if(data->heroptr->getPingHit()==data->V.size()+data->bye&&data->heroptr->isHasLight()==true){
            data->again=true;
        }

        int N=data->V.size();
        for (int i = 0; i < N; i++){
            delete data->V.at(i);
        }
        data->PingHit=0;
        data->bye=0;
        data->V.clear();


        data->heroptr->setPingHit(0);
        isExplosion=true;


    }
    if(isExplosion) {
        explosion->setPosition(((1400 * data->lenght) / 1920), (500 * data->width) / 1080);
        explosion->setTextureRect(sf::IntRect(32 * countExplosion, 0, 32, 32));
        countExplosion++;
        clock1.restart();
        while (clock1.getElapsedTime() < time1) {}

        if (countExplosion == 16) {
            //TODO cambio fase
            data->heroptr->setAttackEnded(true);
            isExplosion = false;
            explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
            countExplosion = 0;
            data->enemyptr->takeDamage(damage);
        }
        if (data->enemyptr->isDead() == false&&data->heroptr->isAttackEnded()&&isExplosion==false) {
            if (data->again) {
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setAttackEnded(false);

            } else {
                this->data->machine.setNewState(StateRef(new EnemyAttackState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setHasLight(false);
                data->heroptr->setAttackEnded(false);

            }
        }
    }


    if (data->enemyptr->isDead()) {
        data->again = false;
        data->heroptr->resetBonus();

        this->data->machine.setNewState(StateRef(new LootState(data)));
        this->data->machine.setReplace(true);
        //TODO loot


    }

}

void HeroAttackState::Init() {
    data->heroptr->setPingHit(data->PingHit);
    damage=data->heroptr->Attack();

}

void HeroAttackState::HandleInput() {

}

void HeroAttackState::Draw() {
    data->window.draw(*data->menu);
    data->heroptr->drawHero(data->window);
    data->enemyptr->drawMe(data->window);
    if(isExplosion){
        data->window.draw(*this->explosion);
    }
}
