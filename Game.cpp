//
// Created by lapo on 08/06/22.
//

#include "Game.h"
#include "MainMenuState.h"
#include"iostream"
    Game::Game() {

        data->window.create(sf::VideoMode::getDesktopMode(), "da Game");
        data->lenght=data->window.getSize().x;
        data->width=data->window.getSize().y;
        data->window.setSize(data->window.getSize());
        data->machine.AddState(StateRef(new MainMenuState(this->data)));

        this->Run();
    }

    void Game::Run() {
        srand(time(NULL));

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

