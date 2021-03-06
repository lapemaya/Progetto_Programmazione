//
// Created by lapo on 10/06/22.
//

#include "DedState.h"
#include "ClassMenuState.h"

DedState::DedState(GameDataRef data) {
    this->data=data;
}
DedState::~DedState() {}
void DedState::Update() {}
void DedState::Init() {
    data->menu->setTextureRect(sf::IntRect(0,1080*2,1920,1080));
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
    std::stringstream ciao1;
    ciao1<<"New Game";
    auto text1=new sf::Text;

    text1->setFont(data->font);
    text1->setString(ciao1.str());
    text1->setCharacterSize(50);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((320*data->lenght)/1920,(700*data->width)/1080);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
/////////////////////////////////////////////////

    std::stringstream ciao2;
    ciao2<<"Exit to\ndesktop";
    auto text2=new sf::Text;

    text2->setFont(data->font);
    text2->setString(ciao2.str());
    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1360*data->lenght)/1920,(680*data->width)/1080);
    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text2);
    /////////////////////////////////////////////////

    std::stringstream ciao3;
    ciao3<<"Ya Ded\nRecord= "<<data->level;
    auto text3=new sf::Text;

    text3->setFont(data->font);
    text3->setString(ciao3.str());
    text3->setCharacterSize(100);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((760*data->lenght)/1920,(200*data->width)/1080);
    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text3);
}
void DedState::HandleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((200 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (300 * data->width) / 1080)) {
                delete data->heroptr;
                delete data->enemyptr;
                data->Va.clear();
                data->level = 1;
                this->data->machine.setNewState(StateRef(new ClassMenuState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->music3.stop();
                data->music3.play();
                data->music1.stop();
                data->music1.openFromFile("./music/elevator.wav");
                data->music1.play();
            }
            if (data->input.response((1200 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (300 * data->width) / 1080)) {
                this->data->window.close();
            }
        }
    }
}
void DedState::Draw() {
data->window.draw(*data->menu);
    for(int i=0;i<Vtext.size();i++) {
        data->window.draw(*Vtext.at(i));
    }
}
