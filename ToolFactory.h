//
// Created by lapo on 13/06/22.
//

#ifndef GIOCO2_TOOLFACTORY_H
#define GIOCO2_TOOLFACTORY_H

#include "Anello.h"
#include "Torso.h"
#include "Shoes.h"
#include "Sword.h"
#include "Nature.h"
#include "Wand.h"
#include "Hero.h"

class ToolFactory {
public:
    Tool* createTool(Hero* heroptr,std::string type);
};


#endif //GIOCO2_TOOLFACTORY_H
