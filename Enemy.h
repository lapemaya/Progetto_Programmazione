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
    virtual bool IsDead()const;
    virtual int Attack();
    virtual void Regen();
    virtual void AttackAnimation();
    virtual void TakeDamage(int damage);
    virtual bool CanAttack()const;
    virtual void Draw(sf::RenderWindow &finestra);

    int getHp() const {
        return Hp;
    }
    void setHp(int hp) {
        Hp = hp;
    }
    int getStamina() const {
        return Stamina;
    }
    void setStamina(int stamina) {
        stamina = stamina;
    }
    int getStrenght() const {
        return Strenght;
    }
    void setStrenght(int Strenght) {
        Enemy::Strenght = Strenght;
    }
    int getStaminaBar() const {
        return StaminaBar;
    }
    void setStaminaBar(int StaminaBar) {
        Enemy::StaminaBar = StaminaBar;
    }
    int getPosx() const {
        return Posx;
    }
    void setPosx(int Posx) {
        Enemy::Posx = Posx;
    }
    int getPosy() const {
        return Posy;
    }
    void setPosy(int Posy) {
        Enemy::Posy = Posy;
    }
    int getFaseAttack() const {
        return FaseAttack;
    }
    void setFaseAttack(int FaseAttack) {
        Enemy::FaseAttack = FaseAttack;
    }
    int getStaminaLeft() const {
        return StaminaLeft;
    }
    void setStaminaLeft(int StaminaLeft) {
        Enemy::StaminaLeft = StaminaLeft;
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
    int Stamina=1;
    int StaminaBar=1;
    int StaminaLeft;
    int Strenght=1;
    int Posx=1400;
    int Posy=500;
    int FaseAttack=0;
    int CountAttack=0;
    bool AttackEnded=false;
    int Level;


};


#endif //GIOCO2_ENEMY_H
