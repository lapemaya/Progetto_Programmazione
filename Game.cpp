//
// Created by lapo on 08/06/22.
//

#include "Game.h"
#include "MainMenuState.h"
#include"iostream"
    Game::Game() {

        data->window.create(sf::VideoMode::getDesktopMode(), "da Game",sf::Style::Fullscreen
        );
        data->lenght=data->window.getSize().x;
        data->width=data->window.getSize().y;

        data->music1.setVolume(50);
        data->music1.setLoop(true);
        data->music1.openFromFile("./music/elevator.wav");
        data->music1.play();

        data->music2.setVolume(100);
        data->music2.setLoop(false);
        data->music2.openFromFile("./music/oof.wav");


        data->music3.setVolume(50);
        data->music3.setLoop(false);
        data->music3.openFromFile("./music/ding.wav");

        data->music4.setVolume(100);
        data->music4.setLoop(false);
        data->music4.openFromFile("./music/ping.wav");


        sf::Vector2<unsigned int>ciao{unsigned(int(data->lenght)),unsigned(int(data->width))};

        data->window.setSize(ciao);
        data->machine.AddState(StateRef(new MainMenuState(this->data)));
        data->font.loadFromFile("font.ttf");

        this->Run();
    }

    void Game::Run() {


        while (this->data->window.isOpen()) {
            if(data->machine.isReplace()) {
                data->machine.AddState(data->machine.getNewState());
                data->machine.setReplace(false);
            }
            this->data->machine.ProcessStateChanges();


            this->data->machine.GetActiveState()->Update();
            this->data->window.clear();
            this->data->machine.GetActiveState()->Draw();
            this->data->window.display();
            this->data->machine.GetActiveState()->HandleInput();

        }
    }

