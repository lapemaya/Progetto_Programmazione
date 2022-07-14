//
// Created by lapo on 14/06/22.
//



#include "Druid.h"

Druid::Druid() {
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/character/druido.png");
    this->setTexture(*texture);
    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    this->setPosition(Posx,Posy);
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

    MaxHp=10;
    Hp=MaxHp;
    Stamina=6;
    Nping=4;
    Strenght=3;
    StaminaBar=6;
    StaminaLeft=StaminaBar;
}
Druid::~Druid() {
    delete this->leaf;
    for(int i=0;i<3;i++)
        Vd.erase(Vd.begin());
}
void Druid::AttackAnimation() {
    if (!AttackEnded) {
        auto time1 = new sf::Time;
        *time1 = sf::seconds(0.5);
        auto time2 = new sf::Time;
        *time2 = sf::seconds(0.15);
        auto clock1 = new sf::Clock;

        if (Transform == 0) {
            if (this->FaseAttack == 0) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time1);
                CountAttack++;
                if (this->CountAttack == 3) {
                    this->FaseAttack = 1;
                    this->CountAttack = 0;
                }
            }
            if (this->FaseAttack == 1) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                CountAttack++;
                leaf->move(0, -60);
                if (CountAttack == 12) {
                    AttackEnded = true;
                    FaseAttack = 0;
                    leaf->setPosition(1400, 1080);
                }
            }
            delete time1;
            delete time2;
            delete clock1;
        }
        if (Transform==1) {
            if (FaseAttack == 0) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                this->move(100, 0);
                this->CountAttack++;
                if (CountAttack == 11) {
                    this->FaseAttack = 1;
                    this->CountAttack = 0;
                }
            }
            if (FaseAttack == 1) {
                clock1->restart();
                while (clock1->getElapsedTime() < *time2);
                this->move(-100, 0);
                this->CountAttack++;
                if (CountAttack == 11) {
                    AttackEnded = true;
                    FaseAttack = 0;
                    CountAttack=0;
                    Transform=0;
                    Posy -= 100;
                    this->setPosition(Posx, Posy);
                    this->setTextureRect(sf::IntRect(0, 0, 32, 32));
                }
            }
        }
    }
    if(this->Attack1==1&&AttackEnded) {
        Transform = 1;
        Posy += 100;
        this->setPosition(Posx, Posy);
        this->setTextureRect(sf::IntRect(0, 32, 32, 32));
    }
}

void Druid::Draw(sf::RenderWindow &finestra)const {
    if(Transform==0) {
        finestra.draw(*this);
        if (this->FaseAttack == 0) {
            if (this->CountAttack == 1){
                finestra.draw(*Vd.at(0));
            }
            if (this->CountAttack == 2) {
                finestra.draw(*Vd.at(0));
                finestra.draw(*Vd.at(1));
            }
            if (this->CountAttack == 3) {
                finestra.draw(*Vd.at(0));
                finestra.draw(*Vd.at(1));
                finestra.draw(*Vd.at(2));
            }
        }
        if (this->FaseAttack == 1) {
            finestra.draw(*Vd.at(0));
            finestra.draw(*Vd.at(1));
            finestra.draw(*Vd.at(2));
            finestra.draw(*(this->leaf));
        }
    }
    if(Transform==1){
        finestra.draw(*this);
    }
}
void Druid::ResetBonus() {
    if(Transform==1) {
        Posy -= 100;
        this->setPosition(Posx, Posy);
        Transform = 0;
        this->setTextureRect(sf::IntRect(0, 0, 32, 32));
    }
}
int Druid::Attack() {
    int damage;
    if(this->Attack1==0){
        damage=AttackNormal();}
    if(this->Attack1==1) {
        damage = AttackLight();
    }
    if(this->Attack1==2){
        damage=AttackStrong();}
    if(Transform==1) {
        damage = damage * 2;
        }
    StaminaLeft-=2;
    return damage;
}

