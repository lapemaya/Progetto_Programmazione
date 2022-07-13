//
// Created by lapo on 13/06/22.
//

#ifndef GIOCO2_TOOLINTERFACE_H
#define GIOCO2_TOOLINTERFACE_H
#include "ToolFactory.h"

class ToolInterface {
public:
    ToolInterface(){
        this->factory=new ToolFactory;
    }
    std::vector<Tool*> orderTool(Hero* heroptr,std::vector<Tool*> Vtool,std::string type){
        for (int i = 0; i < 3; i++) {
            Tool *tool;
            tool = factory->createTool(heroptr,type);
            tool->setPosx(500 + 400 * i);
            tool->setPosy(600);
            tool->setPosition(tool->getPosx(), tool->getPosy());
            tool->setTextureRect(sf::IntRect(tool->getRarity() * 32, 0, 32, 32));
            Vtool.push_back(tool);
        }
        return Vtool;
    }
private:
    ToolFactory* factory;
};


#endif //GIOCO2_TOOLINTERFACE_H
