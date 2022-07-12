//
// Created by lapo on 10/06/22.
//

#include "StatState.h"

StatState::StatState(GameDataRef data) {
this->data=data;

    std::stringstream ciao1;

    ciao1<<"Pick da PowerUp";

    auto texti=new sf::Text;
    text1=texti;

    text1->setFont(data->font);
    text1->setString(ciao1.str());

    text1->setCharacterSize(100);
    text1->setScale(data->lenght/1920,data->width/1080);
    text1->setPosition((580*data->lenght)/1920,(260*data->width)/1080);

    text1->setFillColor(sf::Color::Black);
    text1->setOutlineThickness(5);
    text1->setOutlineColor(sf::Color::Red);
/////////////////////////////////////////////////
    std::stringstream ciao2;
    ciao2<<"Hp Up";

    auto texti2=new sf::Text;
    text2=texti2;

    text2->setFont(data->font);
    text2->setString(ciao2.str());

    text2->setCharacterSize(30);
    text2->setScale(data->lenght/1920,data->width/1080);
    text2->setPosition((550*data->lenght)/1920,(750*data->width)/1080);

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
    ciao4<<"Stamina Up";

    auto texti4=new sf::Text;
    this->text4=texti4;

    text4->setFont(data->font);
    text4->setString(ciao4.str());

    text4->setCharacterSize(30);
    text4->setScale(data->lenght/1920,data->width/1080);
    text4->setPosition((920*data->lenght)/1920,(750*data->width)/1080);

    text4->setFillColor(sf::Color::Black);
    text4->setOutlineThickness(5);
    text4->setOutlineColor(sf::Color::Red);

    /////////////////////////////////////////////////
    std::string ciao5="Ping Up";

    auto texti5=new sf::Text;
    this->text5=texti5;

    text5->setFont(data->font);
    text5->setString(ciao5);

    text5->setCharacterSize(30);
    text5->setScale(data->lenght/1920,data->width/1080);
    text5->setPosition((1350*data->lenght)/1920,(750*data->width)/1080);

    text5->setFillColor(sf::Color::Black);
    text5->setOutlineThickness(5);
    text5->setOutlineColor(sf::Color::Red);

}

StatState::~StatState() {

}

void StatState::Update() {

}

void StatState::Init() {
    data->menu->setTextureRect(sf::IntRect(1920*3,1080,1920,1080));

    data->menu->setScale(((1*data->lenght)/1920),((1*data->width)/1080));
}

void StatState::HandleInput() {
    sf::Event event;
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    while (this->data->window.pollEvent(event))
        if (sf::Event::Closed == event.type) {
            this->data->window.close();

        }
    if (event.type == sf::Event::MouseButtonPressed) {
        if (event.mouseButton.button == sf::Mouse::Left) {
            int quale;
            if (data->input.response((500 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                quale = 0;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
                data->music1.stop();
                data->music1.openFromFile("./music/hollow.wav");
                data->music1.play();

                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((900 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                quale = 1;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
                data->music1.stop();
                data->music1.openFromFile("./music/hollow.wav");
                data->music1.play();

                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((1300 * data->lenght) / 1920, (500 * data->width) / 1080,
                                     (200 * data->lenght) / 1920, (200 * data->width) / 1080)) {
                quale = 2;
                data->heroptr->upgradeStat(quale);
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
                data->music1.stop();
                data->music1.openFromFile("./music/hollow.wav");
                data->music1.play();

                data->music3.stop();
                data->music3.play();
            }
            if (data->input.response((775 * data->lenght) / 1920, (900 * data->width) / 1080,
                                     (500 * data->lenght) / 1920, (100 * data->width) / 1080)) {
                this->data->machine.setNewState(StateRef(new AttackMenuState(data)));
                this->data->machine.setReplace(true);

                data->heroptr->setAttackEnded(false);
                data->level++;
                data->first=true;
                data->prima=true;
                data->again=false;
                data->heroptr->setHasLight(false);

                data->heroptr->setHp(data->heroptr->getMaxHp());
                data->heroptr->setStaminaLeft(data->heroptr->getStaminaBar());
                data->music1.stop();
                data->music1.openFromFile("./music/hollow.wav");

                data->music1.play();
                data->music3.stop();
                data->music3.play();

            }
        }
        }

}

void StatState::Draw() {
    data->window.draw(*data->menu);
    data->window.draw(*text1);
    data->window.draw(*text2);
    data->window.draw(*text3);
    data->window.draw(*text4);
    data->window.draw(*text5);


}
