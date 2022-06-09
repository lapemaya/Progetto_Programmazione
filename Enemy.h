//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_ENEMY_H
#define GIOCO2_ENEMY_H


#include "SFML/Graphics.hpp"

class Enemy: public sf::Sprite {
public:

    Enemy();
    virtual ~Enemy();
    virtual bool isDead();
    virtual int attack();
    virtual void regen();
    virtual void attackAnimation();
    virtual void takeDamage(int damage);
    virtual bool canAttack();
    virtual void drawMe(sf::RenderWindow &finestra);

    int getHp() const {
        return Hp;
    }

    void setHp(int hp) {
        Hp = hp;
    }

    int getStamina() const {
        return stamina;
    }

    void setStamina(int stamina) {
        stamina = stamina;
    }

    int getStrenght() const {
        return strenght;
    }

    void setStrenght(int strenght) {
        Enemy::strenght = strenght;
    }
    int getStaminaBar() const {
        return staminaBar;
    }

    void setStaminaBar(int staminaBar) {
        Enemy::staminaBar = staminaBar;
    }

    int getPosx() const {
        return posx;
    }

    void setPosx(int posx) {
        Enemy::posx = posx;
    }

    int getPosy() const {
        return posy;
    }

    void setPosy(int posy) {
        Enemy::posy = posy;
    }

    int getFaseAttack() const {
        return faseAttack;
    }

    void setFaseAttack(int faseAttack) {
        Enemy::faseAttack = faseAttack;
    }

    int getStaminaLeft() const {
        return staminaLeft;
    }

    void setStaminaLeft(int staminaLeft) {
        Enemy::staminaLeft = staminaLeft;
    }

    bool isAttackEnded() const {
        return AttackEnded;
    }

    void setAttackEnded(bool isAttackEnded) {
        Enemy::AttackEnded = isAttackEnded;
    }
    int getCountAttack() const {
        return CountAttack;
    }

    void setCountAttack(int CountAttack) {
        Enemy::CountAttack = CountAttack;
    }
protected:
    int Hp=10;
    int stamina=1;
    int staminaBar=1;
    int staminaLeft;
    int strenght=1;
    int posx=1400;
    int posy=500;
    int faseAttack=0;
    int CountAttack=0;
    bool AttackEnded=false;
    int level;


};


#endif //GIOCO2_ENEMY_H
