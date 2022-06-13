//
// Created by lapo on 09/06/22.
//
#include "Knight.h"
Knight::Knight() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/knight.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);

    auto swordA1=new sf::Sprite;
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/swordKnight.png");
    swordA1->setTexture(*texture1);
    swordA1->setTextureRect(sf::IntRect(0, 0, 32, 32));
    swordA1->setPosition(1300,300);
    swordA1->setScale(15,15);

    swordA=swordA1;

    auto sword1=new Sword;
    this->specialTool=sword1;

    maxHp=30;
    Hp=maxHp;
    stamina=4;
    nping=3;
    strenght=4;
    staminaBar=6;
    staminaLeft=staminaBar;

}
Knight::~Knight() {

}

void Knight::attackAnimation() {


    auto time1 = new sf::Time;
    *time1 = sf::seconds(0.1);


    auto clock1 = new sf::Clock;


    if(this->faseAttack==0) {
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->move(100, 0);
        this->countAttack++;
        if (countAttack == 9) {
            this->faseAttack = 1;
            this->countAttack=0;


        }
    }
    if(this->faseAttack==1){
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->setTextureRect(sf::IntRect(this->countAttack* 32, 0, 32, 32));
        if(crit){
            swordA->setPosition(1300,300);
            swordA->setTextureRect(sf::IntRect(this->countAttack* 32, 0, 32, 32));
        }
        this->countAttack++;
        if(this->countAttack==6){
            this->faseAttack = 2;
            this->countAttack=0;
            crit=false;
        }

    }
    if(this->faseAttack==2){
        clock1->restart();
        while (clock1->getElapsedTime() < *time1);
        this->move(-100, 0);
        this->countAttack++;
        if (countAttack == 9) {
            this->faseAttack = 0;
            this->countAttack = 0;
            this->setTextureRect(sf::IntRect(this->countAttack* 32, 0, 32, 32));
            this->attackEnded=true;
            swordA->setTextureRect(sf::IntRect(0,0,32,32));

        }
    }
    delete time1;
    delete clock1;
}

int Knight::Attack() {
    int damage;
    int random=rand()%100;
    if(random<=3*nping)
        crit=true;

    if(this->attack==0)
        damage=attackNormal();
    if(this->attack==1)
        damage=attackLight();
    if(this->attack==2)
        damage=attackStrong();
    if(crit==true) {
        damage = damage * 5;

    }
    staminaLeft-=2;
    return damage;
}

void Knight::drawHero(sf::RenderWindow &finestra) {
    finestra.draw(*this);
    if(this->crit==true&&this->faseAttack==1)
        finestra.draw(*swordA);


}

void Knight::resetBonus() {
    crit=false;
}
