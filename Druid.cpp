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

    sf::Sprite* flame1t=new sf::Sprite();
    flame1t->setPosition(0,500);
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/druidflames.png");
    flame1t->setTexture(*texture1);
    flame1t->setTextureRect(sf::IntRect(0, 0, 32, 32));
    flame1t->setScale(6.25,6.25);

    sf::Sprite* flame2t=new sf::Sprite();
    flame2t->setPosition(200,300);
    flame2t->setTexture(*texture1);
    flame2t->setTextureRect(sf::IntRect(0, 0, 32, 32));
    flame2t->setScale(6.25,6.25);

    sf::Sprite* flame3t=new sf::Sprite();
    flame3t->setPosition(400,500);
    flame3t->setTexture(*texture1);
    flame3t->setTextureRect(sf::IntRect(0, 0, 32, 32));
    flame3t->setScale(6.25,6.25);

    Vd.push_back(flame1t);
    Vd.push_back(flame2t);
    Vd.push_back(flame3t);
    auto leaf=new sf::Sprite();
    auto texture2=new sf::Texture;
    texture2->loadFromFile("./sprite/Varie/leaf.png");
    leaf->setTexture(*texture2);
    leaf->setTextureRect(sf::IntRect(0, 0, 32, 32));
    leaf->setScale(12.5,12.5);
    leaf->setPosition(1400,1080);



    this->leaf=leaf;
    auto nature1=new SpecialTool(1);
    this->specialTool=nature1;

    maxHp=10;
    Hp=maxHp;
    stamina=6;
    nping=4;
    strenght=9993;
    staminaBar=6;
    staminaLeft=staminaBar;
}

Druid::~Druid() {
    delete this->leaf;
    for(int i=0;i<3;i++)
        Vd.erase(Vd.begin());

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
                    leaf->setPosition(1400, 1080);

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
                finestra.draw(*Vd.at(0));
            }
            if (this->countAttack == 2) {
                finestra.draw(*Vd.at(0));
                finestra.draw(*Vd.at(1));

            }
            if (this->countAttack == 3) {
                finestra.draw(*Vd.at(0));
                finestra.draw(*Vd.at(1));
                finestra.draw(*Vd.at(2));

            }

        }
        if (this->faseAttack == 1) {
            finestra.draw(*Vd.at(0));
            finestra.draw(*Vd.at(1));
            finestra.draw(*Vd.at(2));
            finestra.draw(*(this->leaf));

        }
    }
    if(transform==1){

        finestra.draw(*this);
    }
}

void Druid::resetBonus() {
    if(transform==1) {
        posy -= 100;
        this->setPosition(posx, posy);
        transform = 0;
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));

    }
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

    staminaLeft-=2;
    return damage;
}

