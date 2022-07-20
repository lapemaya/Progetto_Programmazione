//
// Created by lapo on 10/06/22.
//

#include "LootState.h"

LootState::LootState(GameDataRef data) {
this->data=data;
}
LootState::~LootState() {
    Vtext.clear();
}
void LootState::Update() {}
void LootState::Init() {
    if(data->first) {
        data->Vtool=data->toolInterface.orderTool(data->heroptr,data->Vtool,"Loot");
        data->first=false;
    }
    data->menu->setTextureRect(sf::IntRect(0,1080,1920,1080));
    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
    std::stringstream ciao1;
    ciao1<<"Pick da Loot";
    auto text1=new sf::Text;

    text1->setFont(data->font);
    text1->setString(ciao1.str());
    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((700*data->lenght)/1920,(390*data->width)/1080);
    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text1);
/////////////////////////////////////////////////

    std::stringstream ciao2;
    ciao2<<"My Hero";
    auto text2=new sf::Text;

    text2->setFont(data->font);
    text2->setString(ciao2.str());
    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1370*data->lenght)/1920,(270*data->width)/1080);
    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text2);
    /////////////////////////////////////////////////

    std::string ciao3="Leave + Money+10";
    auto text3=new sf::Text;

    text3->setFont(data->font);
    text3->setString(ciao3);
    text3->setCharacterSize(50);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((820*data->lenght)/1920,(900*data->width)/1080);
    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text3);
    /////////////////////////////////////////////////

    std::stringstream ciao4;
    ciao4<<"Money= " <<data->heroptr->getMoney();
    auto text4=new sf::Text;

    text4->setFont(data->font);
    text4->setString(ciao4.str());
    text4->setCharacterSize(50);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((420*data->lenght)/1920,(900*data->width)/1080);
    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text4);
    /////////////////////////////////////////////////

    std::string ciao5=*data->Vtool[0]->getDescription();
    auto text5=new sf::Text;

    text5->setFont(data->font);
    text5->setString(ciao5);
    text5->setCharacterSize(50);
    text5->setScale(data->lenght/1920,data->width/1080);
    text5->setPosition((500*data->lenght)/1920,(800*data->width)/1080);
    text5->setFillColor(sf::Color::Black);
    text5->setOutlineThickness(5);
    text5->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text5);
    /////////////////////////////////////////////////

    std::string ciao6=*data->Vtool[1]->getDescription();
    auto text6=new sf::Text;

    text6->setFont(data->font);
    text6->setString(ciao6);
    text6->setCharacterSize(50);
    text6->setScale(data->lenght/1920,data->width/1080);
    text6->setPosition((900*data->lenght)/1920,(800*data->width)/1080);
    text6->setFillColor(sf::Color::Black);
    text6->setOutlineThickness(5);
    text6->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text6);
    /////////////////////////////////////////////////

    std::string ciao7=*data->Vtool[2]->getDescription();
    auto text7=new sf::Text;

    text7->setFont(data->font);
    text7->setString(ciao7);
    text7->setCharacterSize(50);
    text7->setScale(data->lenght/1920,data->width/1080);
    text7->setPosition((1300*data->lenght)/1920,(800*data->width)/1080);
    text7->setFillColor(sf::Color::Black);
    text7->setOutlineThickness(5);
    text7->setOutlineColor(sf::Color::Red);
    Vtext.push_back(text7);
}
void LootState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();
        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            if (data->input.response((500 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                auto tool = data->Vtool.at(0);
                data->heroptr->ChangeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((900 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                auto tool = data->Vtool.at(1);
                data->heroptr->ChangeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((1300 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                auto tool = data->Vtool.at(2);
                data->heroptr->ChangeTool(tool);
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->first=true;
                data->prima=false;
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((775 * data->lenght) / 1920, (900 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (100 * data->width) / 1080)) {
                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new ShopState(data)));
                this->data->machine.setReplace(true);
                data->heroptr->setMoney(data->heroptr->getMoney() + 10);
                data->first=true;
                data->prima=false;
                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((1300 * data->lenght) / 1920, (200 * data->width) / 1080,
                                     (300 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                this->data->machine.setNewState(StateRef(new HeroCheckState(data)));
                this->data->machine.setReplace(true);
                data->music3.stop();
                data->music3.play();
            }
        }
        }
}
void LootState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*Vtext.at(0));
    data->window.draw(*Vtext.at(1));
    data->window.draw(*Vtext.at(2));
    data->window.draw(*Vtext.at(3));
    for(int i=0;i<3;i++) {
        data->window.draw(*(data->Vtool.at(i)));
        }
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    if (globalPosition.x > (500*data->lenght)/1920 && globalPosition.x < (700*data->lenght)/1920 &&
            globalPosition.y > (600*data->width)/1080 && globalPosition.y < (800*data->width)/1080){
        data->window.draw(*Vtext.at(4));
    }
    if (globalPosition.x > (900*data->lenght)/1920 && globalPosition.x < (1100*data->lenght)/1920 &&
            globalPosition.y > (600*data->width)/1080 && globalPosition.y < (800*data->width)/1080){
        data->window.draw(*Vtext.at(5));
    }
    if (globalPosition.x > (1300*data->lenght)/1920 && globalPosition.x < (1500*data->lenght)/1920 &&
            globalPosition.y > (600*data->width)/1080&& globalPosition.y < (800*data->width)/1080){
        data->window.draw(*Vtext.at(6));
    }
}

