//
// Created by lapo on 10/06/22.
//

#include "EnemyAttackState.h"
#include "AttackMenuState.h"

EnemyAttackState::EnemyAttackState(GameDataRef data) {
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
    text1->setPosition((200*data->lenght)/1920,(700*data->width)/1080);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
}
EnemyAttackState::~EnemyAttackState() {
delete explosion;
    Vtext.clear();
}
void EnemyAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if (data->enemyptr->CanAttack() || IsExplosion) {
        if (!data->enemyptr->isAttackEnded() && !IsExplosion)
            data->enemyptr->AttackAnimation();
        if (data->enemyptr->isAttackEnded()) {
            data->heroptr->TakeDamage(Damage);
            data->enemyptr->setAttackEnded(false);
            data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() - 2);
            IsExplosion = true;
            data->music2.stop();
            data->music2.play();
        }
        if (IsExplosion) {
            explosion->setPosition((100 * data->lenght) / 1920, (500 * data->width) / 1080);
            explosion->setTextureRect(sf::IntRect(32 * CountExplosion, 0, 32, 32));
            CountExplosion++;
            clock1.restart();
            while (clock1.getElapsedTime() < time1) {}
            std::stringstream ciao1;
            ciao1<<"-"<<Damage;
            Vtext.at(0)->setString(ciao1.str());
            if (CountExplosion == 16) {
                IsExplosion = false;
                CountExplosion = 0;
                explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
                Damage = 0;
                if (data->heroptr->IsDead()){
                    this->data->machine.setNewState(StateRef(new DedState(data)));
                    this->data->machine.setReplace(true);
                    data->music1.stop();
                    data->music1.openFromFile("./music/deadmario.wav");
                    data->music1.play();
                }
                else{
                    this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                    this->data->machine.setReplace(true);
                }
            }
        }
    } else {
        data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() + data->enemyptr->getStamina());
        this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
        this->data->machine.setReplace(true);
    }
}
void EnemyAttackState::Init() {
    data->menu->setTextureRect(sf::IntRect(1920*3,0,1920,1080));
    Damage=data->enemyptr->Attack();
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void EnemyAttackState::HandleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
}
void EnemyAttackState::Draw() {
    data->window.draw(*data->menu);
    data->heroptr->Draw(data->window);
    data->enemyptr->Draw(data->window);
    if(IsExplosion){
        data->window.draw(*this->explosion);
        for(int i=0;i<Vtext.size();i++) {
            data->window.draw(*Vtext.at(i));
        }
    }
    for(int i=0;i<data->heroptr->getObservers().size();i++){
        if(data->heroptr->getObservers().at(i)->done)
            data->window.draw(*data->heroptr->getObservers().at(i)->GetTrophie());
    }
}
