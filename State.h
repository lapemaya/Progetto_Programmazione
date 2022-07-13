//
// Created by lapo on 08/06/22.
//

#ifndef GIOCO2_STATE_H
#define GIOCO2_STATE_H

#include "sstream"
class State {
public:
    virtual void Init() = 0;
    virtual void HandleInput() = 0;
    virtual void Update() = 0;
    virtual void Draw() = 0;
};
#endif //GIOCO2_STATE_H
