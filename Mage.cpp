//
// Created by lapo on 14/06/22.
//

#include "Mage.h"
Mage::Mage() {

    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/mago2.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(aura, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);

    auto fireptr=new Fireball();

    this->setFireptr(fireptr);
    auto wand1=new SpecialTool(0);
    this->specialTool=wand1;

    maxHp=20;
    Hp=maxHp;
    stamina=4;
    nping=5;
    strenght=2;
    staminaBar=6;
    staminaLeft=staminaBar;

}

Mage::~Mage() {
    delete this->fireptr;
}


void Mage::attackAnimation() {
    if(this->isAttackEnded()==false) {



        sf::Time *time1;
        time1 = new sf::Time;
        *time1 = sf::seconds(0.10);

        sf::Clock *clock1;
        clock1 = new sf::Clock;


        if (this->getFaseAttack() == 0) {

            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            this->setCountAttack(this->getCountAttack() + 1);
            this->setTextureRect(sf::IntRect(this->getCountAttack() * 32, aura*32, 32, 32));
            if (this->getCountAttack() == 2) {
                this->setFaseAttack(1);
                this->setCountAttack(0);
            }


        }
        if (this->getFaseAttack() == 1) {
            if(countPing>=8){
                fireptr->setScale(12.5,12.5);}
            fireptr->move(50,5.55);

            clock1->restart();
            while (clock1->getElapsedTime() < *time1) {
            }

            this->setCountAttack(this->getCountAttack() + 1);
            fireptr->setTextureRect(sf::IntRect((this->getCountAttack()%8) * 32, 0, 32, 32));

            if (this->getCountAttack() == 20) {
                this->setFaseAttack(2);
                this->setCountAttack(0);
            }
        }

        if (this->getFaseAttack() == 2) {

            this->setTextureRect(sf::IntRect(64 - this->getCountAttack() * 32, aura*32, 32, 32));

            clock1->restart();
            while (clock1->getElapsedTime() < *time1) {
            }
            this->setCountAttack(this->getCountAttack() + 1);

            if (this->getCountAttack() == 3) {
                this->setFaseAttack(0);
                this->setCountAttack(0);
                this->setAttackEnded(true);

                fireptr->setPosition(fireptr->getPosx(),fireptr->getPosy());
                countPing+=pingHit;
            }
        }
        delete time1;
        delete clock1;
    }
    if(attackEnded&&aura==1){
        countPing=0;
        fireptr->setScale(6.25,6.25);
        aura=0;
        this->setTextureRect(sf::IntRect(0,aura*32,32,32));
    }
    if(countPing>=8&&attackEnded){
        aura=1;
        this->setTextureRect(sf::IntRect(0,32*aura,32,32));}

}

void Mage::drawHero(sf::RenderWindow &finestra) {


    finestra.draw(*this);
    if(this->getFaseAttack()==1){
        finestra.draw(*(this->getFireptr()));
        finestra.draw(*this);}
    finestra.draw(*this);
}

int Mage::Attack() {
    int damage;
    if(this->attack==0)
        damage=attackNormal();
    if(this->attack==1)
        damage=attackLight();
    if(this->attack==2)
        damage=attackStrong();
    if(aura==1){
        damage=damage*1.5;

    }
    staminaLeft-=2;
    return damage;
}

void Mage::resetBonus() {
    countPing=0;
    aura=0;
    this->setTextureRect(sf::IntRect(0,aura*32,32,32));
}




