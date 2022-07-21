//
// Created by lapo on 20/07/22.
//

#include "DamageAchivement.h"

DamageAchivement::DamageAchivement(Hero *hero) {
    subject=hero;
    trophie=new sf::Sprite;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/trophie.png");
    trophie->setTexture(*texture);
    trophie->setTextureRect(sf::IntRect(0, 0, 32, 32));
    trophie->setPosition(300,700);
    trophie->setScale(6.25,6.25);
    this->Attach();
}

void DamageAchivement::Attach() {
    subject->Subscribe(this);
}

void DamageAchivement::Update() {
    if(subject->getDamage()>500){
        this->done=true;
        }
}


DamageAchivement::~DamageAchivement(){
    delete trophie;
};

