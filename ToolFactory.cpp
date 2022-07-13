//
// Created by lapo on 13/06/22.
//

#include "ToolFactory.h"

Tool *ToolFactory::createTool(Hero *heroptr,std::string type) {
    Tool* tool=0;
    int N = rand() % 4;
    if(type.compare("Loot")) {
        if(N!=3) {
            tool = new Tool(N);
            tool->ChooseRarityFirst();
            return tool;
        }
        if (N == 3) {
            int M=heroptr->getSpecialTool()->getSpecial();
            tool = new SpecialTool(M);
            tool->ChooseRarityFirst();
            return tool;
        }
    }
    if(type.compare("Shop")) {
        if(N!=3) {
            tool = new Tool(N);
            tool->ChooseRaritySecond();
            return tool;
        }
        if (N == 3) {
            int M=heroptr->getSpecialTool()->getSpecial();
            tool = new SpecialTool(M);
            tool->ChooseRaritySecond();
            return tool;
        }
    }
}
