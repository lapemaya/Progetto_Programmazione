//
// Created by lapo on 09/06/22.
//

#include "Hero.h"

Hero::Hero(){
    auto torso1=new Tool(0);
    this->torso=torso1;
    auto ring1=new Tool(2);
    this->ring=ring1;
    auto shoes1=new Tool(1);
    this->shoes=shoes1;
}
bool Hero::IsDead() {
    if(this->getHp()<=0)
        return true;
    else
        return false;
}
void Hero::TakeDamage(int damage) {
    this->setHp(Hp-damage);
}
bool Hero::CanAttack() {
    if(this->getStaminaLeft()>0)
        return true;
    else
        return false;
}
int Hero::AttackLight() {
    int damage;
    damage=(PingHit*Strenght)/2;
    this->HasLight=true;
    return damage;
}
int Hero::AttackNormal() {
    int damage;
    damage=(PingHit*Strenght);
    return damage;
}
int Hero::AttackStrong() {
    int damage;
    damage=(PingHit*Strenght)*2;
    if(PingHit!=Nping){
        damage=0;
    }
    return damage;
}
void Hero::Regen() {
    this->setStaminaLeft(this->getStamina()+this->getStaminaLeft());
    if(StaminaLeft>StaminaBar)
        StaminaLeft=StaminaBar;
}

void Hero::AttackAnimation() {}
int Hero::Attack() {
    int damage;
    if(this->Attack1==0)
        damage=AttackNormal();
    if(this->Attack1==1)
        damage=AttackLight();
    if(this->Attack1==2)
        damage=AttackStrong();
    return damage;
}
void Hero::Draw(sf::RenderWindow &finestra) {
    finestra.draw(*this);
}
Hero::~Hero() {}
void Hero::Upgrade(Tool* tool) {
    int controll=tool->getType();
    if(controll==2){
        Tool* used=this->getRing();
        this->setNping(this->getNping()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }
    if(controll==0){
        Tool* used=this->getTorso();
        this->setMaxHp(this->getMaxHp()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }
    if(controll==1){
        Tool* used=this->getShoes();
        this->setStaminaBar(this->getStaminaBar()+((tool->getRarity()-(used->getRarity()))*2));
        this->setStamina(this->getStamina()+((tool->getRarity()-(used->getRarity()))*1));
    }
    if(controll==3){
        SpecialTool* used=this->getSpecialTool();
        this->setStrenght(this->getStrenght()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }
}
void Hero::ChangeTool(Tool* tool) {
    if (tool->getType() == 0) {
        tool->setPosx(1000);
        tool->setPosy(300);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->Upgrade(tool);
        delete this->torso;
        this->torso=new Tool(*tool);
    }
    if (tool->getType() == 1) {
        tool->setPosx(1300);
        tool->setPosy(300);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->Upgrade(tool);
        delete this->shoes;
        this->shoes=new Tool(*tool);
    }
    if (tool->getType() == 2) {
        tool->setPosx(1000);
        tool->setPosy(600);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->Upgrade(tool);
        delete this->ring;
        this->ring=new Tool(*tool);
    }
    if (tool->getType() == 3) {
        tool->setPosx(1300);
        tool->setPosy(600);
        tool->setPosition(tool->getPosx(), tool->getPosy());
        this->Upgrade(tool);
        auto O= this->specialTool->getSpecial();
        delete this->specialTool;
        this->specialTool = new SpecialTool(*tool,O);
    }
}
void Hero::UpgradeStat(int quale) {
    if(quale==0){
        MaxHp+=15;
    }
    if(quale==1){
        StaminaBar++;
    }
    if(quale==2){
        Nping++;
    }
}
