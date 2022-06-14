//
// Created by lapo on 09/06/22.
//

#include "AttackMenuState.h"
#include "iostream"
#
AttackMenuState::AttackMenuState(GameDataRef data) {
    this->data=data;

}

void AttackMenuState::Init() {
    delete data->menu;
    data->menu=new AttackMenu();
    data->menu->setScale(((1 * data->lenght) / 1920), ((1 * data->width) / 1080));




    if(data->first){
        creationEnemy();
        data->first=false;
        data->heroptr->setPosx((data->heroptr->getPosx() * data->lenght) / 1920);
        data->heroptr->setPosx((data->heroptr->getPosx() * data->width) / 1080);
        data->heroptr->setPosition(data->heroptr->getPosx(), data->heroptr->getPosy());
        data->heroptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));

        data->enemyptr->setPosx(data->lenght - ((data->lenght * (1920 - data->enemyptr->getPosx())) / 1920));
        data->enemyptr->setPosx((data->enemyptr->getPosx() * data->width) / 1080);
        data->enemyptr->setPosition(data->enemyptr->getPosx(), data->enemyptr->getPosy());
        data->enemyptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));
    }
    if(data->again== true) {
        data->again=false;
    }

    std::stringstream ciao1;

    ciao1<<"Hp= "<<data->heroptr->getHp()<<"\nStamina= "<<data->heroptr->getStaminaLeft()<<"\nMoney= "<<data->heroptr->getMoney();

    auto texti=new sf::Text;
    text1=texti;

    text1->setFont(data->font);
    text1->setString(ciao1.str());

    text1->setCharacterSize(50);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((50*data->lenght)/1920,(100*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
/////////////////////////////////////////////////
    std::stringstream ciao2;
    ciao2<<"HP= "<<data->enemyptr->getHp()<<"\nStamina= "<<data->enemyptr->getStaminaLeft();

    auto texti2=new sf::Text;
    text2=texti2;

    text2->setFont(data->font);
    text2->setString(ciao2.str());

    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1550*data->lenght)/1920,(100*data->width)/1080);

    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::string ciao3="Normal\nAttack";

    auto texti3=new sf::Text;
    this->text3=texti3;

    text3->setFont(data->font);
    text3->setString(ciao3);

    text3->setCharacterSize(30);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((850*data->lenght)/1920,(270*data->width)/1080);

    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao4="Strong\nAttack";

    auto texti4=new sf::Text;
    this->text4=texti4;

    text4->setFont(data->font);
    text4->setString(ciao4);

    text4->setCharacterSize(30);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((1050*data->lenght)/1920,(270*data->width)/1080);

    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao5="  Light\nAttack";

    auto texti5=new sf::Text;
    this->text5=texti5;

    text5->setFont(data->font);
    text5->setString(ciao5);

    text5->setCharacterSize(30);
    text5->setScale(data->lenght/1920,data->width/1080);
    text5->setPosition((850*data->lenght)/1920,(470*data->width)/1080);

    text5->setFillColor(sf::Color::Black);
    text5->setOutlineThickness(5);
    text5->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao6="Regen";

    auto texti6=new sf::Text;
    this->text6=texti6;

    text6->setFont(data->font);
    text6->setString(ciao6);

    text6->setCharacterSize(30);
    text6->setScale(data->lenght/1920,data->width/1080);
    text6->setPosition((1060*data->lenght)/1920,(480*data->width)/1080);

    text6->setFillColor(sf::Color::Black);
    text6->setOutlineThickness(5);
    text6->setOutlineColor(sf::Color::Red);

}

AttackMenuState::~AttackMenuState() {
delete text1;
    delete text2;
    delete text3;
    delete text4;
    delete text5;
    delete text6;
}

void AttackMenuState::Update() {

}

void AttackMenuState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((1000 * data->lenght) / 1920, (400 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                //regen
                data->heroptr->regen();
                data->heroptr->setHasLight(false);

                this->data->machine.setNewState(StateRef(new EnemyAttackState(data)));
                this->data->machine.setReplace(true);

            }
            if(data->heroptr->canAttack()) {
                if (data->input.response((800 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    //normal

                    data->heroptr->setAttack(0);
                    data->heroptr->setHasLight(false);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                }
                if (data->input.response((800 * data->lenght) / 1920, (400 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    if(data->heroptr->isHasLight()==false) {
                        //light
                        data->heroptr->setAttack(1);
                        data->heroptr->setHasLight(true);
                        this->data->machine.setNewState(StateRef(new PingState(data)));
                        this->data->machine.setReplace(true);
                    }
                }
                if (data->input.response((1000 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    //strong
                    data->heroptr->setAttack(2);
                    data->heroptr->setHasLight(false);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                }
                }
            }
        }
}

void AttackMenuState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*data->heroptr);
    data->window.draw(*data->enemyptr);
    data->window.draw(*text1);
    data->window.draw(*text2);
    data->window.draw(*text3);
    data->window.draw(*text4);
    data->window.draw(*text5);
    data->window.draw(*text6);

}

void AttackMenuState::creationEnemy() {
    int random=rand()%3;

    if(random==0){
        data->enemyptr=new Goblin(data->level);}
    if(random==1){
        data->enemyptr=new Rat(data->level);}
    if(random==2){
        data->enemyptr=new Dragon(data->level);}
}


