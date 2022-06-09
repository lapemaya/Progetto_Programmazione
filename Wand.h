//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_WAND_H
#define GIOCO2_WAND_H


#include "SpecialTool.h"


class Wand: public SpecialTool{
public:

    Wand();
    virtual ~Wand();
    Wand(const SpecialTool& specialTool);

};



#endif //GIOCO2_WAND_H
