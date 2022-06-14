//
// Created by lapo on 09/06/22.
//

#include "ClassMenuState.h"


ClassMenuState::ClassMenuState(GameDataRef data) {
    this->data=data;

    std::string ciao1="Pick da Class";

    auto texti=new sf::Text;
    text1=texti;

    text1->setFont(data->font);
    text1->setString(ciao1);

    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((690*data->lenght)/1920,(100*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
/////////////////////////////////////////////////
    std::string ciao2="Mage";

    auto texti2=new sf::Text;
    this->text2=texti2;

    text2->setFont(data->font);
    text2->setString(ciao2);

    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((270*data->lenght)/1920,(950*data->width)/1080);

    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::string ciao3="Knight";

    auto texti3=new sf::Text;
    this->text3=texti3;

    text3->setFont(data->font);
    text3->setString(ciao3);

    text3->setCharacterSize(50);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((900*data->lenght)/1920,(950*data->width)/1080);

    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao4="Druid";

    auto texti4=new sf::Text;
    this->text4=texti4;

    text4->setFont(data->font);
    text4->setString(ciao4);

    text4->setCharacterSize(50);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((1540*data->lenght)/1920,(950*data->width)/1080);

    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);
}

ClassMenuState::~ClassMenuState() {
    delete text1;
    delete text2;
    delete text3;
    delete text4;
}

void ClassMenuState::Update() {

}

void ClassMenuState::Init() {
    delete data->menu;
    data->menu=new ClassMenu();


    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void ClassMenuState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {

            if (data->input.response((100 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080)) {

                data-> heroptr=new Mage;
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

            }
            if (data->input.response((730 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080)) {

               data-> heroptr=new Knight;
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);


            }
            if (data->input.response((1350 * data->lenght) / 1920, (300 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (600 * data->width) / 1080)) {

                data-> heroptr=new Druid;
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

            }
            }
        }
        }




void ClassMenuState::Draw() {
    this->data->window.draw(*data->menu);
    data->window.draw(*text1);
    data->window.draw(*text2);
    data->window.draw(*text3);
    data->window.draw(*text4);
}

