//
// Created by lapo on 20/07/22.
//

#ifndef GIOCO2_SUBJECT_H
#define GIOCO2_SUBJECT_H
#include "Observer.h"

class Subject {
public:
    virtual void Subscribe(Observer *o) = 0;
    virtual void Unsubscribe(Observer *o) = 0;
    virtual void Notify() = 0;

    virtual ~Subject() = default;
};



#endif //GIOCO2_SUBJECT_H
