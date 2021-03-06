//
// Created by lapo on 08/06/22.
//
#include "iostream"
#include "MainMenuState.h"
#include "HowState.h"

void MainMenuState::Init() {
    std::string ciao1="Da Game";
    auto text1=new sf::Text;

    text1->setFont(data->font);
    text1->setString(ciao1);
    text1->setCharacterSize(300);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((150*data->lenght)/1920,(50*data->width)/1080);
    text1->setStyle(sf::Text::Bold | sf::Text::Underlined);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
/////////////////////////////////////////////////

    std::string ciao2="New Game";
    auto text2=new sf::Text;

    text2->setFont(data->font);
    text2->setString(ciao2);
    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1530*data->lenght)/1920,(370*data->width)/1080);
    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text2);
    /////////////////////////////////////////////////

    std::string ciao3="How to Play";
    auto text3=new sf::Text;

    text3->setFont(data->font);
    text3->setString(ciao3);
    text3->setCharacterSize(50);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((1530*data->lenght)/1920,(570*data->width)/1080);
    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text3);
    /////////////////////////////////////////////////

    std::string ciao4="Exit to desktop";
    auto text4=new sf::Text;

    text4->setFont(data->font);
    text4->setString(ciao4);
    text4->setCharacterSize(50);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((1490*data->lenght)/1920,(770*data->width)/1080);
    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text4);
}
void MainMenuState::Draw() {
    data->window.draw(*data->menu);
    for(int i=0;i<Vtext.size();i++) {
        data->window.draw(*Vtext.at(i));
    }
}
MainMenuState::MainMenuState(GameDataRef data) {
    data->menu=new Menu;
    data->menu->setTextureRect(sf::IntRect(0,0,1920,1080));
    this->data=data;
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}
MainMenuState::~MainMenuState() {
    Vtext.clear();
}
void MainMenuState::HandleInput() {
    sf::Event event;
    while (this->data->window.pollEvent(event)) {
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                if (data->input.response((1400 * data->lenght) / 1920, (300 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    this->data->machine.setNewState(StateRef(new ClassMenuState(data)));
                    this->data->machine.setReplace(true);
                    data->music3.play();
                }
                if (data->input.response((1400 * data->lenght) / 1920, (700 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    this->data->window.close();
                }
                if (data->input.response((1400 * data->lenght) / 1920, (500 * data->width) / 1080,
                                         (500 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                    this->data->machine.setNewState(StateRef(new HowState(data)));
                    this->data->machine.setReplace(true);
                    data->music3.play();
                }
                }
            }
        }
    }
void MainMenuState::Update() {}
