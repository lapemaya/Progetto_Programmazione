//
// Created by lapo on 09/06/22.
//

#include "Hero.h"

Hero::Hero(){

    auto torso1=new Torso();
    this->torso=torso1;
    auto ring1=new Anello();
    this->ring=ring1;
    auto shoes1=new Shoes();
    this->shoes=shoes1;


}

bool Hero::isDead() {
    if(this->getHp()<=0)
        return true;
    else
        return false;
}

void Hero::takeDamage(int damage) {
    this->setHp(Hp-damage);
}

bool Hero::canAttack() {
    if(this->getStaminaLeft()>0)
        return true;
    else
        return false;
}

int Hero::attackLight() {
    int damage;
    damage=(pingHit*strenght)/2;
    this->hasLight=true;
    return damage;
}

int Hero::attackNormal() {

    int damage;
    damage=(pingHit*strenght);
    return damage;
}

int Hero::attackStrong() {
    int damage;
    damage=(pingHit*strenght)*2;
    if(pingHit!=nping){
        damage=0;
    }
    return damage;
}

void Hero::regen() {
    this->setStaminaLeft(this->getStamina()+this->getStaminaLeft());
    if(staminaLeft>staminaBar)
        staminaLeft=staminaBar;

}

void Hero::attackAnimation() {

}





int Hero::Attack() {
    int damage;
    if(this->attack==0)
        damage=attackNormal();
    if(this->attack==1)
        damage=attackLight();
    if(this->attack==2)
        damage=attackStrong();
    return damage;

}






void Hero::drawHero(sf::RenderWindow &finestra) {
    finestra.draw(*this);
}

Hero::~Hero() {

}

void Hero::upgrade(Tool* tool) {

    int controll=tool->getType();
    if(controll==2){
        Anello* used=this->getRing();
        this->setNping(this->getNping()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }

    if(controll==0){
        Torso* used=this->getTorso();
        this->setMaxHp(this->getMaxHp()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }
    if(controll==1){
        Shoes* used=this->getShoes();

        this->setStaminaBar(this->getStaminaBar()+((tool->getRarity()-(used->getRarity()))*2));
        this->setStamina(this->getStamina()+((tool->getRarity()-(used->getRarity()))*1));
    }

    if(controll==3){
        SpecialTool* used=this->getSpecialTool();
        this->setStrenght(this->getStrenght()+((tool->getRarity()-(used->getRarity()))*tool->getBonus()));
    }

}

void Hero::changeTool(Tool* tool) {
    if (tool->getType() == 0) {
        tool->setPosx(1000);
        tool->setPosy(300);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->upgrade(tool);
        delete this->torso;
        this->torso=new Torso(*tool);

    }
    if (tool->getType() == 1) {
        tool->setPosx(1300);
        tool->setPosy(300);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->upgrade(tool);
        delete this->shoes;
        this->shoes=new Shoes(*tool);

    }
    if (tool->getType() == 2) {
        tool->setPosx(1000);
        tool->setPosy(600);
        tool->setPosition(tool->getPosx(),tool->getPosy());
        this->upgrade(tool);
        delete this->ring;
        this->ring=new Anello(*tool);


    }
    if (tool->getType() == 3) {
        tool->setPosx(1300);
        tool->setPosy(600);
        tool->setPosition(tool->getPosx(), tool->getPosy());
        this->upgrade(tool);
        if (this->specialTool->getSpecial() == 0) {
            delete this->specialTool;
            this->specialTool = new Wand(*tool);
        }
        if (this->specialTool->getSpecial() == 1) {
            delete this->specialTool;
            this->specialTool = new Nature(*tool);
        }
        if (this->specialTool->getSpecial() == 2) {
            delete this->specialTool;
            this->specialTool = new Sword(*tool);
        }

    }

}

void Hero::upgradeStat(int quale) {
    if(quale==0){
        maxHp+=15;
    }
    if(quale==1){
        staminaBar++;
    }
    if(quale==2){
        nping++;
    }
}
