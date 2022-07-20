//
// Created by lapo on 20/07/22.
//

#include "KillsAchivement.h"

KillsAchivement::~KillsAchivement(){
    delete trophie;
}

KillsAchivement::KillsAchivement(Hero *hero) {
    subject=hero;
    trophie=new sf::Sprite;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/trophie.png");
    trophie->setTexture(*texture);
    trophie->setTextureRect(sf::IntRect(0, 0, 32, 32));
    trophie->setPosition(0,700);
    trophie->setScale(6.25,6.25);
    this->Attach();
}

void KillsAchivement::Update() {
    if(subject->getKill()>5){
        this->done=true;
    }
}

void KillsAchivement::Attach() {
    subject->Subscribe(this);
}

void KillsAchivement::Detach() {
    subject->Unsubscribe(this);
}



