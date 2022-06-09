//
// Created by lapo on 09/06/22.
//


#include "ArrayPing.h"

ArrayPing::ArrayPing() {

}


void ArrayPing::creazione(int N,std::vector<Ping*> &V) {

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

void ArrayPing::click(std::vector<Ping*> &V) {
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
            this->setBye(this->getBye()+1);
            N=N-this->bye;
            this->setPingHit(this->getPingHit()+1);


        }

    }
}

void ArrayPing::drawPing(sf::RenderWindow &finestra,std::vector<Ping*> V) {
    int N=V.size();
    for (int i = 0; i < N; i++) {
        V.at(i)->drawMe(finestra);
    }
}

void ArrayPing::destroy( std::vector<Ping*> &V) {
    int N=V.size();
    for (int i = 0; i < N; i++){
        delete V.at(i);
    }
    this->pingHit=0;
    this->bye=0;
    V.clear();

}