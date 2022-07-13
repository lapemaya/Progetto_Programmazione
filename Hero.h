//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_HERO_H
#define GIOCO2_HERO_H


#include <SFML/Graphics.hpp>

#include "Tool.h"

#include "SpecialTool.h"

class Hero:public sf::Sprite {
public:
    Hero();
    virtual ~Hero();

    virtual bool IsDead();
    virtual void TakeDamage(int damage);
    virtual bool CanAttack();
    virtual int Attack();
    virtual int AttackLight();
    virtual int AttackNormal();
    virtual int AttackStrong();
    virtual void Regen();
    virtual void AttackAnimation();
    virtual void Draw(sf::RenderWindow &finestra);
    virtual void ResetBonus()=0;
    void Upgrade(Tool* tool);
    void ChangeTool(Tool* tool);
    void UpgradeStat(int quale);

    int getStaminaLeft() const {
        return StaminaLeft;
    }
    void setStaminaLeft(int StaminaLeft) {
        Hero::StaminaLeft = StaminaLeft;
    }
    int getHp() const {
        return Hp;
    }
    void setHp(int hp) {
        Hp = hp;
    }
    int getStamina() const {
        return Stamina;
    }
    void setStamina(int Stamina) {
        Hero::Stamina = Stamina;
    }
    int getNping() const {
        return Nping;
    }
    void setNping(int Nping) {
        Hero::Nping = Nping;
    }
    int getStrenght() const {
        return Strenght;
    }
    void setStrenght(int Strenght) {
        Hero::Strenght = Strenght;
    }
    int getPosx() const {
        return Posx;
    }
    void setPosx(int posx) {
        Hero::Posx = Posx;
    }
    int getPosy() const {
        return Posy;
    }
    void setPosy(int posy) {
        Hero::Posy = Posy;
    }
    int getAttack() const {
        return Attack1;
    }
    void setAttack(int Attack1) {
        Hero::Attack1 = Attack1;
    }
    bool isisAttacking() const {
        return IsAttacking;
    }
    void setIsAttacking(bool IsAttacking) {
        Hero::IsAttacking = IsAttacking;
    }
    int getStaminaBar() const {
        return StaminaBar;
    }
    void setStaminaBar(int StaminaBar) {
        Hero::StaminaBar = StaminaBar;
    }
    bool isDonePing() const {
        return DonePing;
    }
    void setDonePing(bool DonePing) {
        Hero::DonePing = DonePing;
    }
    bool isAttackEnded() const {
        return AttackEnded;
    }
    void setAttackEnded(bool AttackEnded) {
        Hero::AttackEnded = AttackEnded;
    }
    int getFaseAttack() const {
        return FaseAttack;
    }
    void setFaseAttack(int FaseAttack) {
        Hero::FaseAttack = FaseAttack;
    }
    int getCountAttack() const {
        return CountAttack;
    }
    void setCountAttack(int CountAttack) {
        Hero::CountAttack = CountAttack;
    }
    int getPingHit() const {
        return PingHit;
    }
    void setPingHit(int PingHit) {
        Hero::PingHit = PingHit;
    }
    void setHasLight(bool HasLight){
        Hero::HasLight=HasLight;
    }
    bool isHasLight() const {
        return HasLight;
    }
    int getMaxHp() const {
        return MaxHp;
    }
    void setMaxHp(int MaxHp) {
        Hero::MaxHp = MaxHp;
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
        return Money;
    }
    void setMoney(int Money) {
        Hero::Money = Money;
    }
protected:
    int Attack1;
    int Hp;
    int MaxHp;
    int Stamina;
    int StaminaBar;
    int StaminaLeft;
    int Nping;
    int PingHit;
    int Strenght;
    int Posx=100;
    int Posy=500;
    bool IsAttacking;
    int FaseAttack=0;
    int CountAttack=0;
    bool DonePing=false;
    bool AttackEnded=false;
    bool HasLight=false;
    int Money=0;

    Tool* torso;
    Tool* ring;
    Tool* shoes;
    SpecialTool* specialTool;
};


#endif //GIOCO2_HERO_H
