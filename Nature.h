//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_NATURE_H
#define GIOCO2_NATURE_H


#include "SpecialTool.h"

class Nature: public SpecialTool{
public:
    Nature();
    virtual ~Nature();
    Nature(const SpecialTool &specialTool);
};



#endif //GIOCO2_NATURE_H
