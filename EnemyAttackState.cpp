//
// Created by lapo on 10/06/22.
//

#include "EnemyAttackState.h"

EnemyAttackState::EnemyAttackState(GameDataRef data) {
    this->data=data;
    auto explosion1=new sf::Sprite;
    explosion=explosion1;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/explosion.png");
    explosion->setTexture(*texture);
    explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
    explosion->setScale((12.5*data->lenght)/1920,(12.5*data->width)/1080);
}

EnemyAttackState::~EnemyAttackState() {
delete explosion;
}

void EnemyAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if (data->enemyptr->canAttack() || isExplosion == true) {
        if (data->enemyptr->isAttackEnded() == false && isExplosion == false)
            data->enemyptr->attackAnimation();
        if (data->enemyptr->isAttackEnded() == true) {
            data->heroptr->takeDamage(damage);
            data->enemyptr->setAttackEnded(false);
            data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() - 2);
            isExplosion = true;
        }
        if (isExplosion) {
            explosion->setPosition((100 * data->lenght) / 1920, (500 * data->width) / 1080);
            explosion->setTextureRect(sf::IntRect(32 * countExplosion, 0, 32, 32));
            countExplosion++;
            clock1.restart();
            while (clock1.getElapsedTime() < time1) {}
            if (countExplosion == 16) {

                isExplosion = false;
                countExplosion = 0;
                explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
                damage = 0;
                if (data->heroptr->isDead()){
                    this->data->machine.setNewState(StateRef(new DedState(data)));
                    this->data->machine.setReplace(true);
                }
                else{
                    this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                    this->data->machine.setReplace(true);
                }
            }
        }

    } else {
        data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() + data->enemyptr->getStamina());
        //TODO cambio fase
        this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
        this->data->machine.setReplace(true);
    }
}
void EnemyAttackState::Init() {
    damage=data->enemyptr->attack();

}

void EnemyAttackState::HandleInput() {

}

void EnemyAttackState::Draw() {
    data->window.draw(*data->menu);
    data->heroptr->drawHero(data->window);
    data->enemyptr->drawMe(data->window);
    if(isExplosion){
        data->window.draw(*this->explosion);
    }
}
