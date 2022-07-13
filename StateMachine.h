//
// Created by lapo on 08/06/22.
//

#ifndef GIOCO2_STATEMACHINE_H
#define GIOCO2_STATEMACHINE_H

#include <memory>
#include <stack>
#include "State.h"
typedef State* StateRef;
class StateMachine {
public:
    StateMachine() {};
    ~StateMachine() {};

    void AddState(StateRef newState);
    void ProcessStateChanges();
    StateRef &GetActiveState();
    void setNewState( State *newState) {
        this->newState = newState;
    }
     State *getNewState()  {
        return newState;
    }
    bool isReplace() const {
        return replace;
    }
    void setReplace(bool replace) {
        StateMachine::replace = replace;
    }
private:
    StateRef state;
    StateRef newState;
    bool isAdding=true;
    bool replace=false;
};
#endif //GIOCO2_STATEMACHINE_H
