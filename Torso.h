//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_TORSO_H
#define GIOCO2_TORSO_H


#include "Tool.h"

class Torso: public Tool {
public:
    Torso();
    virtual ~Torso();
    Torso(const Tool& tool);



};

#endif //GIOCO2_TORSO_H
