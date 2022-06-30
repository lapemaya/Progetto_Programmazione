//
// Created by lapo on 09/06/22.
//

#include "Dragon.h"

Dragon::~Dragon() {
    delete this->fireptr;

}

Dragon::Dragon(int N) {
    level=N*2;
    Hp=8*level*3/2;
    strenght=6*level;
    staminaBar=6*level;
    stamina=6*level;
    staminaLeft=staminaBar;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/drago.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 64, 64));
    this->setPosition(posx,posy);
    this->setScale(3.125,3.125);
    auto fireptr1=new Fireball(1400,400);
    this->fireptr=fireptr1;
    fireptr->setPosx(1400);
    fireptr->setPosy(400);
}

void Dragon::attackAnimation() {
    if(this->isAttackEnded()==false) {
        this->inAttack=true;




        auto time1 = new sf::Time;
        *time1 = sf::seconds(0.10);


        auto clock1 = new sf::Clock;


        if (this->getFaseAttack() == 0)
            fireptr->move(-50,5.55);
        clock1->restart();
        while (clock1->getElapsedTime() < *time1) {
        }

        this->setCountAttack(this->getCountAttack() + 1);
        fireptr->setTextureRect(sf::IntRect((this->getCountAttack()%8) * 32, 0, 32, 32));

        if (this->getCountAttack() == 20) {
            this->setAttackEnded(true);
            fireptr->setPosition(fireptr->getPosx(),fireptr->getPosy());
            this->setCountAttack(0);
            this->inAttack=false;

        }
        delete time1;
        delete clock1;
    }

}

void Dragon::drawMe(sf::RenderWindow &finestra) {
    finestra.draw(*this);
    if(this->inAttack)
        finestra.draw(*(this->fireptr));
}
