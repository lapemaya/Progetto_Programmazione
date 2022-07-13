//
// Created by lapo on 09/06/22.
//

#include "Rat.h"

Rat::~Rat() {}
Rat::Rat(int N) {
    Level=N*2;
    Hp=10*Level*3/2;
    Strenght=5*Level;
    StaminaBar=6*Level;
    Stamina=6*Level;
    StaminaLeft=StaminaBar;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/rat.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(Posx,Posy);
    this->setScale(12.5,12.5);
}
void Rat::AttackAnimation() {
    if (!this->isAttackEnded()) {
        auto time1 = new sf::Time;
        *time1 = sf::seconds(0.125);
        auto clock1 = new sf::Clock;

        if (this->getFaseAttack() == 0) {
            this->move(-50, 0);
            this->CountAttack++;
            clock1->restart();
            while (clock1->getElapsedTime() < *time1) {
            }
            if (CountAttack == 22) {
                this->FaseAttack = 1;
                this->CountAttack = 0;
            }
        }
        if (this->FaseAttack == 1) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            this->CountAttack++;
            this->setTextureRect(sf::IntRect(this->CountAttack * 32, 0, 32, 32));
            if (this->CountAttack == 5) {
                this->FaseAttack = 2;
                this->CountAttack = 0;
                this->setTextureRect(sf::IntRect(this->CountAttack * 32, 0, 32, 32));
            }
        }
        if (this->FaseAttack == 2) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            this->move(50, 0);
            this->CountAttack++;
            if (CountAttack == 22) {
                this->FaseAttack = 0;
                this->CountAttack = 0;
                this->setAttackEnded(true);
            }
        }
        delete time1;
        delete clock1;
    }
}
