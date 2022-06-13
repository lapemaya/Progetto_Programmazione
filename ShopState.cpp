//
// Created by lapo on 10/06/22.
//

#include "ShopState.h"

ShopState::ShopState(GameDataRef data) {
this->data=data;
}

ShopState::~ShopState() {
delete text1;
    delete text2;
    delete text3;
    delete text4;
    delete text5;
    delete text6;
    delete text7;

}

void ShopState::Update() {

}

void ShopState::Init() {
    if(data->first) {
        data->Vtool=data->toolInterface.orderTool(data->heroptr,data->Vtool,"Shop");
        data->first=false;
    }
    delete data->menu;
    data->menu=new ShopMenu;

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));

    std::stringstream ciao1;

    ciao1<<"Da Shop";

    auto texti=new sf::Text;
    text1=texti;

    text1->setFont(data->font);
    text1->setString(ciao1.str());

    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((820*data->lenght)/1920,(390*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
/////////////////////////////////////////////////
    std::stringstream ciao2;
    ciao2<<"My Hero";

    auto texti2=new sf::Text;
    text2=texti2;

    text2->setFont(data->font);
    text2->setString(ciao2.str());

    text2->setCharacterSize(50);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((1370*data->lenght)/1920,(270*data->width)/1080);

    text2->setFillColor(sf::Color::Black);
    text2->setOutlineThickness(5);
    text2->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::string ciao3="Leave";

    auto texti3=new sf::Text;
    this->text3=texti3;

    text3->setFont(data->font);
    text3->setString(ciao3);

    text3->setCharacterSize(50);
    text3->setScale(data->lenght/1920,data->width/1080);
    text3->setPosition((970*data->lenght)/1920,(900*data->width)/1080);

    text3->setFillColor(sf::Color::Black);
    text3->setOutlineThickness(5);
    text3->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::stringstream ciao4;
    ciao4<<"Money= " <<data->heroptr->getMoney();

    auto texti4=new sf::Text;
    this->text4=texti4;

    text4->setFont(data->font);
    text4->setString(ciao4.str());

    text4->setCharacterSize(50);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((420*data->lenght)/1920,(900*data->width)/1080);

    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao5=*data->Vtool[0]->getDescription();

    auto texti5=new sf::Text;
    this->text5=texti5;

    text5->setFont(data->font);
    text5->setString(ciao5);

    text5->setCharacterSize(50);
    text5->setScale(data->lenght/1920,data->width/1080);
    text5->setPosition((500*data->lenght)/1920,(800*data->width)/1080);

    text5->setFillColor(sf::Color::Black);
    text5->setOutlineThickness(5);
    text5->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao6=*data->Vtool[1]->getDescription();

    auto texti6=new sf::Text;
    this->text6=texti6;

    text6->setFont(data->font);
    text6->setString(ciao6);

    text6->setCharacterSize(50);
    text6->setScale(data->lenght/1920,data->width/1080);
    text6->setPosition((900*data->lenght)/1920,(800*data->width)/1080);

    text6->setFillColor(sf::Color::Black);
    text6->setOutlineThickness(5);
    text6->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::string ciao7=*data->Vtool[2]->getDescription();

    auto texti7=new sf::Text;
    this->text7=texti7;

    text7->setFont(data->font);
    text7->setString(ciao7);

    text7->setCharacterSize(50);
    text7->setScale(data->lenght/1920,data->width/1080);
    text7->setPosition((1300*data->lenght)/1920,(800*data->width)/1080);

    text7->setFillColor(sf::Color::Black);
    text7->setOutlineThickness(5);
    text7->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::stringstream ciao8;
    ciao8<<data->Vtool[0]->getCost()<<"$";

    auto texti8=new sf::Text;
    this->text8=texti8;

    text8->setFont(data->font);
    text8->setString(ciao8.str());

    text8->setCharacterSize(30);
    text8->setScale(data->lenght/1920,data->width/1080);
    text8->setPosition((570*data->lenght)/1920,(550*data->width)/1080);

    text8->setFillColor(sf::Color::Black);
    text8->setOutlineThickness(5);
    text8->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::stringstream ciao9;
    ciao9<<data->Vtool[1]->getCost()<<"$";

    auto texti9=new sf::Text;
    this->text9=texti9;

    text9->setFont(data->font);
    text9->setString(ciao9.str());

    text9->setCharacterSize(30);
    text9->setScale(data->lenght/1920,data->width/1080);
    text9->setPosition((970*data->lenght)/1920,(550*data->width)/1080);

    text9->setFillColor(sf::Color::Black);
    text9->setOutlineThickness(5);
    text9->setOutlineColor(sf::Color::Red);
    /////////////////////////////////////////////////
    std::stringstream ciao10;
    ciao10<<data->Vtool[2]->getCost()<<"$";

    auto texti10=new sf::Text;
    this->text10=texti10;

    text10->setFont(data->font);
    text10->setString(ciao10.str());

    text10->setCharacterSize(30);
    text10->setScale(data->lenght/1920,data->width/1080);
    text10->setPosition((1370*data->lenght)/1920,(550*data->width)/1080);

    text10->setFillColor(sf::Color::Black);
    text10->setOutlineThickness(5);
    text10->setOutlineColor(sf::Color::Red);
}

void ShopState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {

            if (data->input.response((500 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                if (canPay(0)) {
                    auto tool = data->Vtool.at(0);
                    data->heroptr->changeTool(tool);
                    for (int i = 0; i < 3; i++) {
                        delete data->Vtool.at(i);
                    }
                    data->Vtool.clear();
                    this->data->machine.setNewState(StateRef(new StatState(data)));
                    this->data->machine.setReplace(true);
                }
            }
            if (data->input.response((900 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                if (canPay(1)) {
                    auto tool = data->Vtool.at(1);
                    data->heroptr->changeTool(tool);
                    for (int i = 0; i < 3; i++) {
                        delete data->Vtool.at(i);
                    }
                    data->Vtool.clear();
                    this->data->machine.setNewState(StateRef(new StatState(data)));
                    this->data->machine.setReplace(true);
                }
            }
            if (data->input.response((1300 * data->lenght) / 1920, (600 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {
                if (canPay(2)) {
                    auto tool = data->Vtool.at(2);
                    data->heroptr->changeTool(tool);
                    for (int i = 0; i < 3; i++) {
                        delete data->Vtool.at(i);
                    }
                    data->Vtool.clear();
                    this->data->machine.setNewState(StateRef(new StatState(data)));
                    this->data->machine.setReplace(true);
                }
            }
            if (data->input.response((775 * data->lenght) / 1920, (900 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (100 * data->width) / 1080, globalPosition)) {

                for (int i = 0; i < 3; i++) {
                    delete data->Vtool.at(i);
                }
                data->Vtool.clear();
                this->data->machine.setNewState(StateRef(new StatState(data)));
                this->data->machine.setReplace(true);

            }

            if (data->input.response((1300 * data->lenght) / 1920, (200 * data->width) / 1080,
                                     (300 * data->lenght) / 1920, (200 * data->width) / 1080, globalPosition)) {

                this->data->machine.setNewState(StateRef(new HeroCheckState(data)));
                this->data->machine.setReplace(true);
            }

        }
    }
}

void ShopState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*text1);
    data->window.draw(*text2);
    data->window.draw(*text3);
    data->window.draw(*text4);
    for(int i=0;i<3;i++) {
        data->window.draw(*(data->Vtool.at(i)));
    }
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    if (globalPosition.x > (500*data->lenght)/1920 && globalPosition.x < (700*data->lenght)/1920 &&
                                                                         globalPosition.y > (600*data->width)/1080 && globalPosition.y < (800*data->width)/1080){
        data->window.draw(*text5);
    }
    if (globalPosition.x > (900*data->lenght)/1920 && globalPosition.x < (1100*data->lenght)/1920 &&
                                                                         globalPosition.y > (600*data->width)/1080 && globalPosition.y < (800*data->width)/1080){
        data->window.draw(*text6);
    }
    if (globalPosition.x > (1300*data->lenght)/1920 && globalPosition.x < (1500*data->lenght)/1920 &&
                                                                          globalPosition.y > (600*data->width)/1080&& globalPosition.y < (800*data->width)/1080){
        data->window.draw(*text7);
    }
    data->window.draw(*text8);
    data->window.draw(*text9);
    data->window.draw(*text10);
}






bool ShopState::canPay(int N) {
    if(data->heroptr->getMoney()>=data->Vtool.at(N)->getCost()){
        data->heroptr->setMoney(data->heroptr->getMoney()-data->Vtool.at(N)->getCost());
        return true;
    }
    else {
        return false;
    }
}

