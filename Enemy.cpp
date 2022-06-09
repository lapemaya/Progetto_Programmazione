//
// Created by lapo on 09/06/22.
//

#include "Enemy.h"
#include "Enemy.h"

Enemy::Enemy() {

    staminaLeft=staminaBar;
}


Enemy::~Enemy() {

}

bool Enemy::isDead() {
    if(this->getHp()<=0)
        return true;
    else{
        return false;
    }
}

void Enemy::regen() {
    this->setStaminaBar(this->getStaminaBar()+this->getStamina());
}

bool Enemy::canAttack() {
    if(this->getStaminaLeft()>0){
        return true;
    }
    else{
        return false;
    }
}

void Enemy::takeDamage(int damage) {
    this->setHp(this->getHp()-damage);
}

int Enemy::attack() {
    int damage=this->getStrenght()+rand()%6;
    return damage;
}

void Enemy::attackAnimation() {

}

void Enemy::drawMe(sf::RenderWindow &finestra) {

    finestra.draw(*this);
}