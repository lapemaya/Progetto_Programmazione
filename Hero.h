//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_HERO_H
#define GIOCO2_HERO_H


#include <SFML/Graphics.hpp>
//#include "ArrayPing.h"
#include "Tool.h"

#include "SpecialTool.h"

class Hero:public sf::Sprite {

public:

    Hero();

    virtual ~Hero();

    virtual bool isDead();
    virtual void takeDamage(int damage);
    virtual bool canAttack();
    virtual int Attack();
    virtual int attackLight();
    virtual int attackNormal();
    virtual int attackStrong();
    virtual void regen();
    virtual void attackAnimation();
    virtual void drawHero(sf::RenderWindow &finestra);
    virtual void resetBonus()=0;

    void upgrade(Tool* tool);
    void changeTool(Tool* tool);
    void upgradeStat(int quale);


    int getStaminaLeft() const {
        return staminaLeft;
    }

    void setStaminaLeft(int staminaLeft) {
        Hero::staminaLeft = staminaLeft;
    }
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
        Hero::stamina = stamina;
    }
    int getNping() const {
        return nping;
    }
    void setNping(int nping) {
        Hero::nping = nping;
    }
    int getStrenght() const {
        return strenght;
    }
    void setStrenght(int strenght) {
        Hero::strenght = strenght;
    }
    int getPosx() const {
        return posx;
    }
    void setPosx(int posx) {
        Hero::posx = posx;
    }
    int getPosy() const {
        return posy;
    }
    void setPosy(int posy) {
        Hero::posy = posy;
    }
    int getAttack() const {
        return attack;
    }
    void setAttack(int attack) {
        Hero::attack = attack;
    }
    bool isisAttacking() const {
        return isAttacking;
    }
    void setIsAttacking(bool isAttacking) {
        Hero::isAttacking = isAttacking;
    }
    int getStaminaBar() const {
        return staminaBar;
    }
    void setStaminaBar(int staminaBar) {
        Hero::staminaBar = staminaBar;
    }
    bool isDonePing() const {
        return donePing;
    }
    void setDonePing(bool donePing) {
        Hero::donePing = donePing;
    }
    bool isAttackEnded() const {
        return attackEnded;
    }
    void setAttackEnded(bool attackEnded) {
        Hero::attackEnded = attackEnded;
    }
    int getFaseAttack() const {
        return faseAttack;
    }
    void setFaseAttack(int faseAttack) {
        Hero::faseAttack = faseAttack;
    }
    int getCountAttack() const {
        return countAttack;
    }
    void setCountAttack(int countAttack) {
        Hero::countAttack = countAttack;
    }
    int getPingHit() const {
        return pingHit;
    }
    void setPingHit(int pingHit) {
        Hero::pingHit = pingHit;
    }
    void setHasLight(bool hasLight){
        Hero::hasLight=hasLight;
    }
    bool isHasLight() const {
        return hasLight;
    }
    int getMaxHp() const {
        return maxHp;
    }
    void setMaxHp(int maxHp) {
        Hero::maxHp = maxHp;
    }
    Tool *getTorso() const {
        return torso;
    }
    void setTorso(Tool* torso) {
        Hero::torso = torso;
    }
    Tool* getRing()const{
        return ring;
    }
    void setRing(Tool* ring){
        Hero::ring=ring;
    }
    Tool *getShoes() const {
        return shoes;
    }

    void setShoes(Tool *shoes) {
        Hero::shoes = shoes;
    }
    SpecialTool *getSpecialTool() const {
        return specialTool;
    }

    void setSpecialTool(SpecialTool *specialTool) {
        Hero::specialTool = specialTool;
    }
    int getMoney() const {
        return money;
    }

    void setMoney(int money) {
        Hero::money = money;
    }
protected:
    int attack;
    int Hp;
    int maxHp;
    int stamina;
    int staminaBar;
    int staminaLeft;
    int nping;
    int pingHit;
    int strenght;
    int posx=100;
    int posy=500;
    bool isAttacking;
    int faseAttack=0;
    int countAttack=0;
    bool donePing=false;
    bool attackEnded=false;
    bool hasLight=false;
    int money=0;

    Tool* torso;
    Tool* ring;
    Tool* shoes;
    SpecialTool* specialTool;



};


#endif //GIOCO2_HERO_H
