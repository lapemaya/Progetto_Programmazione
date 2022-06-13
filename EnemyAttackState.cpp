//
// Created by lapo on 10/06/22.
//

#include "EnemyAttackState.h"

EnemyAttackState::EnemyAttackState(GameDataRef data) {
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
    text1->setPosition((200*data->lenght)/1920,(700*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
}


EnemyAttackState::~EnemyAttackState() {
delete explosion;
    delete text1;
}

void EnemyAttackState::Update() {
    time1=sf::milliseconds(62.5);
    if (data->enemyptr->canAttack() || isExplosion == true) {
        if (data->enemyptr->isAttackEnded() == false && isExplosion == false)
            data->enemyptr->attackAnimation();
        if (data->enemyptr->isAttackEnded() == true) {
            data->heroptr->takeDamage(damage);
            data->enemyptr->setAttackEnded(false);
            data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() - 2);
            isExplosion = true;
        }
        if (isExplosion) {
            explosion->setPosition((100 * data->lenght) / 1920, (500 * data->width) / 1080);
            explosion->setTextureRect(sf::IntRect(32 * countExplosion, 0, 32, 32));
            countExplosion++;
            clock1.restart();
            while (clock1.getElapsedTime() < time1) {}

            std::stringstream ciao1;
            ciao1<<"-"<<damage;
            text1->setString(ciao1.str());

            if (countExplosion == 16) {

                isExplosion = false;
                countExplosion = 0;
                explosion->setTextureRect(sf::IntRect(0, 0, 32, 32));
                damage = 0;
                if (data->heroptr->isDead()){
                    this->data->machine.setNewState(StateRef(new DedState(data)));
                    this->data->machine.setReplace(true);
                }
                else{
                    this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                    this->data->machine.setReplace(true);
                }
            }
        }

    } else {
        data->enemyptr->setStaminaLeft(data->enemyptr->getStaminaLeft() + data->enemyptr->getStamina());
        //TODO cambio fase
        this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
        this->data->machine.setReplace(true);
    }
}
void EnemyAttackState::Init() {
    delete data->menu;
    data->menu=new NullMenu;
    damage=data->enemyptr->attack();
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
    data->heroptr->drawHero(data->window);
    data->enemyptr->drawMe(data->window);
    if(isExplosion){
        data->window.draw(*this->explosion);
        data->window.draw(*text1);
    }
}
