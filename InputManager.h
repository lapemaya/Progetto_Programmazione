//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_INPUTMANAGER_H
#define GIOCO2_INPUTMANAGER_H
#include "SFML/Graphics.hpp"


class InputManager {

    public:
        InputManager() = default;
        ~InputManager() = default;

        bool response(int x,int y,int dx,int dy);


};


#endif //GIOCO2_INPUTMANAGER_H
