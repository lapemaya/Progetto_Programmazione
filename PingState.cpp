//
// Created by lapo on 09/06/22.
//

#include "PingState.h"

PingState::PingState(GameDataRef data) {
    this->data=data;
    ////////////////////////////////////////////////////////////
    std::stringstream ciao1;

    ciao1<<"Hp= "<<data->heroptr->getHp()<<"\nStamina= "<<data->heroptr->getStaminaLeft()<<"\nMoney= "<<data->heroptr->getMoney();

    auto texti1=new sf::Text;
    text1=texti1;

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

    ciao2<<"Hp= "<<data->enemyptr->getHp()<<"\nStamina= "<<data->enemyptr->getStaminaLeft();

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
    std::stringstream ciao3;

    ciao3<<(time1.asSeconds()-clock1.getElapsedTime().asSeconds());

    auto texti3=new sf::Text;
    text3=texti3;

    text3->setFont(data->font);
    text3->setString(ciao3.str());

    text3->setCharacterSize(50);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((900*data->lenght)/1920,(50*data->width)/1080);

    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);
}

PingState::~PingState() {
delete text1;
delete text2;
}

void PingState::Update() {
    std::stringstream ciao3;
    float value = (int)((time1.asSeconds()-clock1.getElapsedTime().asSeconds()) * 10);
    value=(float)value / 10;
    ciao3<<(value);
    text3->setString(ciao3.str());
    if(data->V.size()==0){
        end=true;
    }
    if(clock1.getElapsedTime()>time1){
        end=true;}
    if(end){
        this->data->machine.setNewState(StateRef(new HeroAttackState(data)));
        this->data->machine.setReplace(true);
        hit=false;
    }
    if(hit){
        delete data->V.at(quale);
        data->V.erase(data->V.begin()+quale);
        hit=false;

    }
}

void PingState::Init() {
    data->menu->setTextureRect(sf::IntRect(1920*3,0,1920,1080));
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
    this->creationPing(data->heroptr->getNping(),data->V);
    time1=sf::seconds(3+data->heroptr->getStamina()*0.5);
    clock1.restart();



}

void PingState::HandleInput() {
    sf::Event event;

    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            clickPing();
        }
        }

}

void PingState::Draw() {
    data->window.draw(*data->menu);
    this->drawPings(data->V);
    data->heroptr->drawHero(data->window);
    data->enemyptr->drawMe(data->window);
    data->window.draw(*text1);
    data->window.draw(*text2);
    data->window.draw(*text3);

}

void PingState::creationPing(int N, std::vector<Ping *> &V) {
    for (int i = 0; i < N; i++) {
        bool found = false;


        Ping* ptr = new Ping();

        if (i == 0) {
            int randx = rand() % int((((1400 * data->lenght) / 1920) - ((100* data->lenght) / 1920) - ((700* data->lenght) / 1920) + 1)) + ((700* data->lenght) / 1920);
            int randy = rand() % int(((1080* data->width) / 1080) - ((100* data->width) / 1080)  + 1) + 0;
            ptr->setPosx(randx);
            ptr->setPosy(randy);
            ptr->setPosition(ptr->getPosx(), ptr->getPosy());

        }

        if (i != 0) {
            while (found == false) {
                int a;
                bool bad = false;
                int randx = rand() % int((((1400 * data->lenght) / 1920) - ((100* data->lenght) / 1920) - ((700* data->lenght) / 1920) + 1)) + ((700* data->lenght) / 1920);
                int randy = rand() % int(((1080* data->width) / 1080) - ((100* data->width) / 1080)  + 1) + 0;
                int dimx=(100*data->lenght) / 1920;
                int dimy=(100* data->width) / 1080;

                for (a = 0; a < i; a++) {

                    if (randx >= V.at(a)->getPosx() &&  V.at(a)->getPosx() + dimx>=randx
                        && randy >= V.at(a)->getPosy()-dimy &&  V.at(a)->getPosy()>=randy){
                        bad = true;}


                    if(randx +dimx>= V.at(a)->getPosx() &&  V.at(a)->getPosx() + dimx>=randx+dimx
                       && randy >= V.at(a)->getPosy()-dimy &&  V.at(a)->getPosy()>=randy){
                        bad = true;}


                    if(randx >= V.at(a)->getPosx() &&  V.at(a)->getPosx() + dimx>=randx
                       && randy-dimy >= V.at(a)->getPosy()-dimy &&  V.at(a)->getPosy()>=randy-dimy){
                        bad = true;}


                    if(randx +dimx>= V.at(a)->getPosx() &&  V.at(a)->getPosx() + dimx>=randx+dimx
                       && randy-dimy >= V.at(a)->getPosy()-dimy &&  V.at(a)->getPosy()>=randy-dimy){
                        bad = true;}

                }

                if (bad == false) {
                    ptr->setPosx(randx);
                    ptr->setPosy(randy);
                    ptr->setPosition(ptr->getPosx(), ptr->getPosy());
                    found = true;
                }
            }
        }
        V.push_back(ptr);
        //delete ptr;
    }

}

void PingState::drawPings(std::vector<Ping *> &V) {
    int N=V.size();
    for (int i = 0; i < N; i++) {
        V.at(i)->setScale(((3.125*data->lenght)/1920),((3.125*data->width)/1080));
        V.at(i)->drawMe(data->window);
    }
}

void PingState::clickPing() {
    int N=data->V.size();
    sf::Vector2i globalPosition = sf::Mouse::getPosition();


    Ping controllo;
    int dimx=(100*data->lenght) / 1920;
    int dimy=(100* data->width) / 1080;
    for (int i = 0; i < N; i++) {
        controllo = *data->V.at(i);

        if (globalPosition.x > controllo.getPosx() && globalPosition.x < controllo.getPosx() + dimx
            && globalPosition.y >controllo.getPosy() && globalPosition.y < controllo.getPosy() +dimy) {
            hit=true;
            quale=i;
            data->bye++;
            N=N-data->bye;
            data->PingHit++;
            data->music4.stop();
            data->music4.play();

        }

    }

}
