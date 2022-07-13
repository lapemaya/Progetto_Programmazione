//
// Created by lapo on 09/06/22.
//

#include "Goblin.h"

Goblin::~Goblin() {

}

Goblin::Goblin(int N) {
    Level=N*2;
    Hp=8*Level*3/2;
    Strenght=5*Level;
    StaminaBar=8*Level;
    Stamina=8*Level;
    StaminaLeft=StaminaBar;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/goblin.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(Posx,Posy);
    this->setScale(12.5,12.5);
    sprite=new sf::Sprite;
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/cuore.png");
    sprite->setTexture(*texture1);
    sprite->setPosition(300,500);
    sprite->setTextureRect(sf::IntRect(0,0,32,32));
}

void Goblin::AttackAnimation() {
    if (!this->isAttackEnded()) {
        auto time1 = new sf::Time;
        *time1 = sf::seconds(0.125);
        auto time2 = new sf::Time;
        *time2 = sf::seconds(0.05);
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
                sprite->setScale(1/8,1/8);
            }
        }
        if (this->FaseAttack == 1) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time2);
            CountAttack++;
            sprite->setScale(0.625*CountAttack,0.625*CountAttack);
            if (CountAttack == 15) {
                this->FaseAttack = 2;
                this->CountAttack = 0;
            }
        }
        if (this->FaseAttack == 2){
            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            CountAttack++;
            sprite->setTextureRect(sf::IntRect (CountAttack*32,0,32,32));
            if(CountAttack==7){
                this->FaseAttack=3;
                this->CountAttack=0;
            }
        }
        if (this->FaseAttack == 3) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            this->move(50, 0);
            this->CountAttack++;
            if (CountAttack == 22) {
                this->FaseAttack = 0;
                this->CountAttack = 0;
                this->setAttackEnded(true);
                sprite->setScale(1,1);
                sprite->setTextureRect(sf::IntRect(0,0,32,32));
            }
        }
        delete time1;
        delete time2;
        delete clock1;
    }
}
void Goblin::Draw(sf::RenderWindow &finestra) {
    finestra.draw(*this);
    if(FaseAttack==1||FaseAttack==2){
        finestra.draw(*sprite);
    }
}
