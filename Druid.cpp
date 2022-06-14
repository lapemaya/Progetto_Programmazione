//
// Created by lapo on 14/06/22.
//



#include "Druid.h"

Druid::Druid() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/druido.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(posx,posy);
    this->setScale(12.5,12.5);

    DruidFlames* flame1t=new DruidFlames(0,500);
    DruidFlames* flame2t=new DruidFlames(200,300);
    DruidFlames* flame3t=new DruidFlames(400,500);
    Leaf* leaf=new Leaf();

    this->setFlame1(flame1t);
    this->setFlame2(flame2t);
    this->setFlame3(flame3t);
    this->leaf=leaf;
    auto nature1=new Nature;
    this->specialTool=nature1;

    maxHp=10;
    Hp=maxHp;
    stamina=6;
    nping=4;
    strenght=3;
    staminaBar=6;
    staminaLeft=staminaBar;
}

Druid::~Druid() {
    delete this->leaf;
    delete this->flame1;
    delete this->flame2;
    delete this->flame3;
}

void Druid::attackAnimation() {
    if (attackEnded == false) {


        auto time1 = new sf::Time;
        *time1 = sf::seconds(0.5);

        auto time2 = new sf::Time;
        *time2 = sf::seconds(0.15);


        auto clock1 = new sf::Clock;

        if (transform == 0) {
            if (this->faseAttack == 0) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time1);
                countAttack++;
                if (this->countAttack == 3) {
                    this->faseAttack = 1;
                    this->countAttack = 0;
                }

            }
            if (this->faseAttack == 1) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                countAttack++;
                leaf->move(0, -60);
                if (countAttack == 12) {
                    attackEnded = true;
                    faseAttack = 0;
                    leaf->setPosition(leaf->getPosx(), leaf->getPosy());

                }

            }
            delete time1;
            delete time2;
            delete clock1;
        }
        if (transform==1) {
            if (faseAttack == 0) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                this->move(100, 0);
                this->countAttack++;
                if (countAttack == 11) {
                    this->faseAttack = 1;
                    this->countAttack = 0;
                }

            }
            if (faseAttack == 1) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                this->move(-100, 0);
                this->countAttack++;
                if (countAttack == 11) {
                    attackEnded = true;
                    faseAttack = 0;
                    countAttack=0;
                    transform=0;
                    posy -= 100;
                    this->setPosition(posx, posy);
                    this->setTextureRect(sf::IntRect(0, 0, 32, 32));


                }
            }
        }
    }
    if(this->attack==1&&attackEnded) {
        transform = 1;
        posy += 100;
        this->setPosition(posx, posy);
        this->setTextureRect(sf::IntRect(0, 32, 32, 32));
    }
}

void Druid::drawHero(sf::RenderWindow &finestra) {


    if(transform==0) {
        finestra.draw(*this);
        if (this->faseAttack == 0) {
            if (this->countAttack == 1){
                finestra.draw(*(this->getFlame1()));
            }
            if (this->countAttack == 2) {
                finestra.draw(*(this->getFlame1()));
                finestra.draw(*(this->getFlame2()));

            }
            if (this->countAttack == 3) {
                finestra.draw(*(this->getFlame1()));
                finestra.draw(*(this->getFlame2()));
                finestra.draw(*(this->getFlame3()));

            }

        }
        if (this->faseAttack == 1) {
            finestra.draw(*(this->getFlame1()));
            finestra.draw(*(this->getFlame2()));
            finestra.draw(*(this->getFlame3()));
            finestra.draw(*(this->leaf));

        }
    }
    if(transform==1){

        finestra.draw(*this);
    }
}

void Druid::resetBonus() {
    transform=0;
    this->setTextureRect(sf::IntRect(0,0,32,32));


}

int Druid::Attack() {
    int damage;
    if(this->attack==0){
        damage=attackNormal();}
    if(this->attack==1) {
        damage = attackLight();
    }
    if(this->attack==2){
        damage=attackStrong();}
    if(transform==1) {
        damage = damage * 2;
        }


    return damage;
}

