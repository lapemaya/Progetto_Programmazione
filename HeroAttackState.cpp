//
// Created by lapo on 09/06/22.
//

#include "HeroAttackState.h"

HeroAttackState::HeroAttackState(GameDataRef data) {
    this->data=data;
    auto explosion1=new sf::Sprite;
    explosion=explosion1;
    auto texture=new sf::Texture;
    texture->loadFromFile("./sprite/Varie/explosion.png");
    explosion->setTexture(*texture);
    explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
    explosion->setScale((12.5*data->lenght)/1920,(12.5*data->width)/1080);



    auto texti=new sf::Text;
    text1=texti;

    text1->setFont(data->font);


    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((1500*data->lenght)/1920,(700*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);

}

HeroAttackState::~HeroAttackState() {
delete explosion;
delete text1;
}

void HeroAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if(data->heroptr->isAttackEnded()==false&&isExplosion==false){
        data->heroptr->attackAnimation();
    }
    if(data->heroptr->isAttackEnded()&&isExplosion==false) {

        data->heroptr->setFaseAttack(0);
        data->heroptr->setCountAttack(0);

        //  RESET VETTORE PING(DESTROY)


        if(data->heroptr->getPingHit()==data->V.size()+data->bye&&data->heroptr->isHasLight()){
            data->again=true;
        }

        int N=data->V.size();
        for (int i = 0; i < N; i++){
            delete data->V.at(i);
        }
        data->PingHit=0;
        data->bye=0;
        data->V.clear();


        data->heroptr->setPingHit(0);
        isExplosion=true;
        data->music2.stop();
        data->music2.play();


    }
    if(isExplosion) {
        explosion->setPosition(((1400 * data->lenght) / 1920), (500 * data->width) / 1080);
        explosion->setTextureRect(sf::IntRect(32 * countExplosion, 0, 32, 32));
        countExplosion++;
        clock1.restart();
        std::stringstream ciao1;
        ciao1<<"-"<<damage;
        text1->setString(ciao1.str());

        while (clock1.getElapsedTime() < time1) {}

        if (countExplosion == 16) {

            data->heroptr->setAttackEnded(true);
            isExplosion = false;
            explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
            countExplosion = 0;
            data->enemyptr->takeDamage(damage);

        }
        if (data->enemyptr->isDead() == false&&data->heroptr->isAttackEnded()&&isExplosion==false) {
            if (data->again) {
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setAttackEnded(false);

            } else {
                this->data->machine.setNewState(StateRef(new EnemyAttackState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setHasLight(false);
                data->heroptr->setAttackEnded(false);

            }
        }
    }


    if (data->enemyptr->isDead()) {
        data->again = false;
        data->heroptr->resetBonus();

        data->music1.stop();
        data->music1.openFromFile("./music/deltarune.wav");
        data->music1.play();
        this->data->machine.setNewState(StateRef(new LootState(data)));
        this->data->machine.setReplace(true);
        data->heroptr->setMoney(data->heroptr->getMoney() + data->level * 5 + rand() % 6);
        data->first=true;



    }

}

void HeroAttackState::Init() {
    data->heroptr->setPingHit(data->PingHit);
    damage=data->heroptr->Attack();

}

void HeroAttackState::HandleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
}

void HeroAttackState::Draw() {
    data->window.draw(*data->menu);

    data->enemyptr->drawMe(data->window);
    data->heroptr->drawHero(data->window);
    if(isExplosion){
        data->window.draw(*this->explosion);
        data->window.draw(*text1);
    }
}
