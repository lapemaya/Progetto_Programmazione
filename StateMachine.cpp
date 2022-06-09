//
// Created by lapo on 08/06/22.
//

#include "StateMachine.h"


void StateMachine::AddState(StateRef newState) {
    this->isAdding = true;
    if(state)
        delete state;
    state=newState;

}


void StateMachine::ProcessStateChanges() {
    if(isAdding) {
       state->Init();
        isAdding=false;
    }
}

StateRef &StateMachine::GetActiveState() {
    return state;
}
