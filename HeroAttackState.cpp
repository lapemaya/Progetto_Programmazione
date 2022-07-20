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
    auto text1=new sf::Text;

    text1->setFont(data->font);
    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((1500*data->lenght)/1920,(700*data->width)/1080);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
}
HeroAttackState::~HeroAttackState() {
delete explosion;
Vtext.clear();
}
void HeroAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if(!data->heroptr->isAttackEnded() && !IsExplosion){
        data->heroptr->AttackAnimation();
    }
    if(data->heroptr->isAttackEnded() && !IsExplosion) {
        data->heroptr->setFaseAttack(0);
        data->heroptr->setCountAttack(0);
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
        IsExplosion=true;
        data->music2.stop();
        data->music2.play();
    }
    if(IsExplosion) {
        explosion->setPosition(((1400 * data->lenght) / 1920), (500 * data->width) / 1080);
        explosion->setTextureRect(sf::IntRect(32 * CountExplosion, 0, 32, 32));
        CountExplosion++;
        clock1.restart();
        std::stringstream ciao1;
        ciao1<<"-"<<Damage;
        Vtext.at(0)->setString(ciao1.str());
        while (clock1.getElapsedTime() < time1) {}
        if (CountExplosion == 16) {
            data->heroptr->setAttackEnded(true);
            IsExplosion = false;
            explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
            CountExplosion = 0;
            data->enemyptr->TakeDamage(Damage);
        }
        if (!data->enemyptr->IsDead() && data->heroptr->isAttackEnded() && !IsExplosion) {
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
    if (data->enemyptr->IsDead()) {
        data->again = false;
        data->heroptr->ResetBonus();
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
    Damage=data->heroptr->Attack();
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
    data->enemyptr->Draw(data->window);
    data->heroptr->Draw(data->window);
    if(IsExplosion){
        data->window.draw(*this->explosion);
        for(int i=0;i<Vtext.size();i++) {
            data->window.draw(*Vtext.at(i));
        }
    }
}
