//
// Created by lapo on 09/06/22.
//

#include "Enemy.h"


Enemy::Enemy() {
}
Enemy::~Enemy() {
}
bool Enemy::IsDead() const{
    if(this->getHp()<=0)
        return true;
    else{
        return false;
    }
}
void Enemy::Regen() {
    this->setStaminaBar(this->getStaminaBar()+this->getStamina());
}
bool Enemy::CanAttack()const {
    if(this->getStaminaLeft()>0){
        return true;
    }
    else{
        return false;
    }
}
void Enemy::TakeDamage(int damage) {
    this->setHp(this->getHp()-damage);
}
int Enemy::Attack() {
    int damage=this->getStrenght()+rand()%6;
    return damage;
}
void Enemy::AttackAnimation() {}
void Enemy::Draw(sf::RenderWindow &finestra) {
    finestra.draw(*this);
}