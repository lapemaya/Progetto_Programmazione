//
// Created by lapo on 13/06/22.
//

#include "ToolFactory.h"

Tool *ToolFactory::createTool(Hero *heroptr,std::string type) {
    Tool* tool=0;
    int N = rand() % 4;
    if(type.compare("Loot")) {
        if (N == 0) {
            tool = new Torso();
            tool->chooseRarityFirst();
            return tool;
        }
        if (N == 1) {
            tool = new Shoes();
            tool->chooseRarityFirst();
            return tool;
        }
        if (N == 2) {
            tool = new Anello();
            tool->chooseRarityFirst();
            return tool;
        }
        if (N == 3) {
            if (heroptr->getSpecialTool()->getSpecial() == 0) {
                tool = new Wand;
                tool->chooseRarityFirst();
                return tool;
            }
            if (heroptr->getSpecialTool()->getSpecial() == 1) {
                tool = new Nature;
                tool->chooseRarityFirst();
                return tool;

            }
            if (heroptr->getSpecialTool()->getSpecial() == 2) {
                tool = new Sword;
                tool->chooseRarityFirst();
                return tool;
            }
        }
    }
    if(type.compare("Shop")) {
        if (N == 0) {
            tool = new Torso();
            tool->chooseRaritySecond();
            return tool;
        }
        if (N == 1) {
           tool = new Shoes();
            tool->chooseRaritySecond();
            return tool;
        }
        if (N == 2) {
           tool = new Anello();
            tool->chooseRaritySecond();
            return tool;
        }
        if (N == 3) {
            if (heroptr->getSpecialTool()->getSpecial() == 0) {
                tool = new Wand;
                tool->chooseRaritySecond();
                return tool;
            }
            if (heroptr->getSpecialTool()->getSpecial() == 1) {
                tool = new Nature;
                tool->chooseRaritySecond();
                return tool;

            }
            if (heroptr->getSpecialTool()->getSpecial() == 2) {
                tool = new Sword;
                tool->chooseRaritySecond();
                return tool;
            }
        }
    }

}
