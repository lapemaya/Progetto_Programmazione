//
// Created by lapo on 09/06/22.
//

#include "AttackMenuState.h"
#include "iostream"

AttackMenuState::AttackMenuState(GameDataRef data) {
    this->data=data;
}
void AttackMenuState::Init() {
    data->menu->setTextureRect(sf::IntRect(1920*2,0,1920,1080));
    data->menu->setScale(((1 * data->lenght) / 1920), ((1 * data->width) / 1080));
    X=new sf::Sprite;
    auto texture1=new sf::Texture;
    texture1->loadFromFile("./sprite/Varie/X.png");
    X->setTexture(*texture1);
    X->setTextureRect(sf::IntRect(0, 0, 32, 32));
    X->setPosition((800*data->lenght) / 1920,(400*data->width) / 1080);
    X->setScale(((6.25 * data->lenght) / 1920), ((6.25  * data->width) / 1080));
    if(data->first){
        CreationEnemy();
        data->first=false;
        data->heroptr->setPosx((data->heroptr->getPosx() * data->lenght) / 1920);
        data->heroptr->setPosx((data->heroptr->getPosx() * data->width) / 1080);
        data->heroptr->setPosition(data->heroptr->getPosx(), data->heroptr->getPosy());
        data->heroptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));
        data->music1.openFromFile("./music/hollow.wav");
        data->music1.setPlayingOffset(sf::seconds(43));
        data->music1.play();
    }
    if(data->again== true) {
        data->again=false;
    }
    std::stringstream ciao1;
    ciao1<<"Hp= "<<data->heroptr->getHp()<<"\nStamina= "<<data->heroptr->getStaminaLeft()<<"\nMoney= "<<data->heroptr->getMoney();
    auto text1=new sf::Text;
    text1->setFont(data->font);
    text1->setString(ciao1.str());
    text1->setCharacterSize(50);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((50*data->lenght)/1920,(100*data->width)/1080);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
/////////////////////////////////////////////////

    std::stringstream ciao2;
    ciao2<<"HP= "<<data->enemyptr->getHp()<<"\nStamina= "<<data->enemyptr->getStaminaLeft();
    auto text2=new sf::Text;
    text2->setFont(data->font);
    text2->setString(ciao2.str());
    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1550*data->lenght)/1920,(100*data->width)/1080);
    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text2);
    /////////////////////////////////////////////////

    std::string ciao3="Normal\nAttack";
    auto text3=new sf::Text;
    text3->setFont(data->font);
    text3->setString(ciao3);
    text3->setCharacterSize(30);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((850*data->lenght)/1920,(270*data->width)/1080);
    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text3);
    /////////////////////////////////////////////////

    std::string ciao4="Strong\nAttack";
    auto text4=new sf::Text;
    text4->setFont(data->font);
    text4->setString(ciao4);
    text4->setCharacterSize(30);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((1050*data->lenght)/1920,(270*data->width)/1080);
    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text4);
    /////////////////////////////////////////////////

    std::string ciao5="  Light\nAttack";
    auto text5=new sf::Text;
    text5->setFont(data->font);
    text5->setString(ciao5);
    text5->setCharacterSize(30);
    text5->setScale(data->lenght/1920,data->width/1080);
    text5->setPosition((850*data->lenght)/1920,(470*data->width)/1080);
    text5->setFillColor(sf::Color::Black);
    text5->setOutlineThickness(5);
    text5->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text5);
    /////////////////////////////////////////////////

    std::string ciao6="Regen";
    auto text6=new sf::Text;
    text6->setFont(data->font);
    text6->setString(ciao6);
    text6->setCharacterSize(30);
    text6->setScale(data->lenght/1920,data->width/1080);
    text6->setPosition((1060*data->lenght)/1920,(480*data->width)/1080);
    text6->setFillColor(sf::Color::Black);
    text6->setOutlineThickness(5);
    text6->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text6);


}
AttackMenuState::~AttackMenuState() {
    Vtext.clear();
    delete X;
}
void AttackMenuState::Update() {}
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
                data->heroptr->Regen();
                data->heroptr->setHasLight(false);
                this->data->machine.setNewState(StateRef(new EnemyAttackState(data)));
                this->data->machine.setReplace(true);
                data->music3.stop();
                data->music3.play();

            }
            if(data->heroptr->CanAttack()) {
                if (data->input.response((800 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    //normal
                    data->heroptr->setAttack(0);
                    data->heroptr->setHasLight(false);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                    data->music3.stop();
                    data->music3.play();
                }
                if (data->input.response((800 * data->lenght) / 1920, (400 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    if(data->heroptr->isHasLight()==false) {
                        //light
                        data->heroptr->setAttack(1);
                        data->heroptr->setHasLight(true);
                        this->data->machine.setNewState(StateRef(new PingState(data)));
                        this->data->machine.setReplace(true);
                        data->music3.stop();
                        data->music3.play();
                    }
                }
                if (data->input.response((1000 * data->lenght) / 1920, (200 * data->width) / 1080,
                                         (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    //strong
                    data->heroptr->setAttack(2);
                    data->heroptr->setHasLight(false);
                    this->data->machine.setNewState(StateRef(new PingState(data)));
                    this->data->machine.setReplace(true);
                    data->music3.stop();
                    data->music3.play();
                }
                }
            }
        }
}
void AttackMenuState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*data->heroptr);
    data->window.draw(*data->enemyptr);
    for(int i=0;i<Vtext.size();i++) {
       data->window.draw(*Vtext.at(i));
    }
    if(data->heroptr->isHasLight()){
        data->window.draw(*X);
    }
    if(!data->heroptr->CanAttack()){
        X->setPosition((800*data->lenght) / 1920,(400*data->width) / 1080);
        data->window.draw(*X);
        X->setPosition((800*data->lenght) / 1920,(200*data->width) / 1080);
        data->window.draw(*X);
        X->setPosition((1000*data->lenght) / 1920,(200*data->width) / 1080);
        data->window.draw(*X);
        X->setPosition((800*data->lenght) / 1920,(400*data->width) / 1080);
    }
    for(int i=0;i<data->heroptr->getObservers().size();i++){
        if(data->heroptr->getObservers().at(i)->done)
            data->window.draw(*data->heroptr->getObservers().at(i)->GetTrophie());
    }
}
void AttackMenuState::CreationEnemy() {
    int random=rand()%3;
    if(random==0){
        data->enemyptr=new Goblin(data->level);
    data->enemyptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));
    }
    if(random==1){
        data->enemyptr=new Rat(data->level);
    data->enemyptr->setScale(((12.5 * data->lenght) / 1920), ((12.5 * data->width) / 1080));
    }
    if(random==2) {
        data->enemyptr = new Dragon(data->level);
        data->enemyptr->setScale(((9 * data->lenght) / 1920), ((9 * data->width) / 1080));
        data->enemyptr->setPosx(data->lenght - ((data->lenght * (1920 - data->enemyptr->getPosx())) / 1920));
        data->enemyptr->setPosy(((data->enemyptr->getPosy() * data->width) / 1080) - 208);
        data->enemyptr->setPosition(data->enemyptr->getPosx(), data->enemyptr->getPosy());
    }
}


