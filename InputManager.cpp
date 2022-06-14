//
// Created by lapo on 09/06/22.
//

#include "InputManager.h"

bool InputManager::response(int x, int y, int dx, int dy) {
    sf::Vector2i globalPosition = sf::Mouse::getPosition();
    if (globalPosition.x > x && globalPosition.x < x + dx
        && globalPosition.y > y && globalPosition.y < y + dy) {
        return true;
    }
    else{
        return false;
    }
}
