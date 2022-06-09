//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_SWORD_H
#define GIOCO2_SWORD_H


#include "SpecialTool.h"

class Sword: public SpecialTool{
public:
    Sword();
    virtual ~Sword();
    Sword(const SpecialTool &specialTool);
};

#endif //GIOCO2_SWORD_H
