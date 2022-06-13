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

        sf::Vector2<unsigned int>ciao{unsigned(int(data->lenght)),unsigned(int(data->width))};
        //sf::Vector2<unsigned int>ciao{700,700};
        data->window.setSize(ciao);
        data->machine.AddState(StateRef(new MainMenuState(this->data)));
        data->font.loadFromFile("font.ttf");

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

