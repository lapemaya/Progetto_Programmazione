//
// Created by lapo on 09/06/22.
//

#include "PingState.h"

PingState::PingState(GameDataRef data) {
    this->data=data;
}

PingState::~PingState() {

}

void PingState::Update() {

}

void PingState::Init() {
    delete data->menu;
    data->menu=new NullMenu();
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
    this->creationPing(data->heroptr->getNping(),data->V);




}

void PingState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            clickPing(data->V);
        }
        }

}

void PingState::Draw() {
    data->window.draw(*data->menu);
    this->drawPings(data->V);
    data->heroptr->drawHero(data->window);
    data->enemyptr->drawMe(data->window);

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

void PingState::clickPing(std::vector<Ping *> &V) {
    int N=V.size();
    sf::Vector2i globalPosition = sf::Mouse::getPosition();

    int i=0;
    Ping controllo;
    int dimx=(100*data->lenght) / 1920;
    int dimy=(100* data->width) / 1080;
    for (int i = 0; i < N; i++) {
        controllo = *V.at(i);

        if (globalPosition.x > controllo.getPosx() && globalPosition.x < controllo.getPosx() + dimx
            && globalPosition.y >controllo.getPosy() && globalPosition.y < controllo.getPosy() +dimy ) {
            delete V.at(i);
            V.erase(V.begin()+i);
            data->bye++;
            N=N-data->bye;
            data->PingHit++;


        }

    }
}
