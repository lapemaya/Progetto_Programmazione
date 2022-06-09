//
// Created by lapo on 09/06/22.
//

#include "Goblin.h"

Goblin::~Goblin() {

}

Goblin::Goblin(int N) {
    level=N*2;
    Hp=8*level*3/2;
    strenght=5*level;
    staminaBar=8*level;
    stamina=8*level;
    staminaLeft=staminaBar;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/goblin.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);
    sprite=new sf::Sprite;
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/cuore.png");
    sprite->setTexture(*texture1);
    sprite->setPosition(300,500);
    sprite->setTextureRect(sf::IntRect(0,0,32,32));
}

void Goblin::attackAnimation() {
    if (this->isAttackEnded() == false) {


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
                this->faseAttack = 1;
                this->CountAttack = 0;
                sprite->setScale(1/8,1/8);

            }

        }
        if (this->faseAttack == 1) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time2);
            CountAttack++;
            sprite->setScale(0.625*CountAttack,0.625*CountAttack);
            if (CountAttack == 15) {
                this->faseAttack = 2;
                this->CountAttack = 0;
            }
        }
        if (this->faseAttack == 2){

            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            CountAttack++;
            sprite->setTextureRect(sf::IntRect (CountAttack*32,0,32,32));
            if(CountAttack==7){
                this->faseAttack=3;
                this->CountAttack=0;
            }

        }


        if (this->faseAttack == 3) {
            clock1->restart();
            while (clock1->getElapsedTime() < *time1);
            this->move(50, 0);
            this->CountAttack++;
            if (CountAttack == 22) {
                this->faseAttack = 0;
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

void Goblin::drawMe(sf::RenderWindow &finestra) {
    finestra.draw(*this);
    if(faseAttack==1||faseAttack==2){
        finestra.draw(*sprite);
    }
}
