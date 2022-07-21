//
// Created by lapo on 09/06/22.
//
#include "Knight.h"
Knight::Knight() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/knight.png");
    this->setTexture(*new sf::Texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(Posx,Posy);
    this->setScale(12.5,12.5);
     swordA=new sf::Sprite;
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/swordKnight.png");
    swordA->setTexture(*texture1);
    swordA->setTextureRect(sf::IntRect(0, 0, 32, 32));
    swordA->setPosition(1300,300);
    swordA->setScale(15,15);
    auto sword1=new SpecialTool(2);
    this->specialTool=sword1;

    MaxHp=30;
    Hp=MaxHp;
    Stamina=4;
    Nping=3;
    Strenght=400;
    StaminaBar=6;
    StaminaLeft=StaminaBar;
}
Knight::~Knight() {}
void Knight::AttackAnimation() {
    auto time1 = new sf::Time;
    *time1 = sf::seconds(0.1);
    auto clock1 = new sf::Clock;

    if(this->FaseAttack==0) {
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->move(100, 0);
        this->CountAttack++;
        if (CountAttack == 9) {
            this->FaseAttack = 1;
            this->CountAttack=0;
        }
    }
    if(this->FaseAttack==1){
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->setTextureRect(sf::IntRect(this->CountAttack* 32, 0, 32, 32));
        if(Crit){
            swordA->setPosition(1300,300);
            swordA->setTextureRect(sf::IntRect(this->CountAttack* 32, 0, 32, 32));
        }
        this->CountAttack++;
        if(this->CountAttack==6){
            this->FaseAttack = 2;
            this->CountAttack=0;
            Crit=false;
        }
    }
    if(this->FaseAttack==2){
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->move(-100, 0);
        this->CountAttack++;
        if (CountAttack == 9) {
            this->FaseAttack = 0;
            this->CountAttack = 0;
            this->setTextureRect(sf::IntRect(this->CountAttack* 32, 0, 32, 32));
            this->AttackEnded=true;
            swordA->setTextureRect(sf::IntRect(0,0,32,32));
        }
    }
    delete time1;
    delete clock1;
}

int Knight::Attack() {
    int damage;
    int random=rand()%100;
    if(random<=3*Nping)
        Crit=true;
    if(this->Attack1==0)
        damage=AttackNormal();
    if(this->Attack1==1)
        damage=AttackLight();
    if(this->Attack1==2)
        damage=AttackStrong();
    if(Crit==true) {
        damage = damage * 5;
    }
    StaminaLeft-=2;
    return damage;
}

void Knight::Draw(sf::RenderWindow &finestra)const {
    finestra.draw(*this);
    if(this->Crit && this->FaseAttack == 1)
        finestra.draw(*swordA);
}

void Knight::ResetBonus() {
    Crit=false;
}
