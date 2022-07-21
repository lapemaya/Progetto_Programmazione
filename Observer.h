//
// Created by lapo on 20/07/22.
//

#ifndef GIOCO2_OBSERVER_H
#define GIOCO2_OBSERVER_H
#include "SFML/Graphics.hpp"
class Observer {
public:
    virtual ~Observer() = default;

    virtual void Update() = 0;
    virtual void Attach() = 0;
    virtual sf::Sprite* GetTrophie()=0;

    bool done = false;
};
#endif //GIOCO2_OBSERVER_H

