//
// Created by lapo on 09/06/22.
//

#include "SpecialTool.h"
SpecialTool::~SpecialTool() {


}

SpecialTool::SpecialTool() {
    bonus=2;
    type=3;
    auto description1=new std::string ;
    *description1="Strenght UP";
    description=description1;
}

SpecialTool::SpecialTool(const Tool &tool) : Tool(tool) {
    this->rarity=tool.getRarity();
    this->posx=tool.getPosx();
    this->posy=tool.getPosy();
    this->bonus=tool.getBonus();
    this->type=tool.getType();
    bonus=tool.getBonus();
    type=3;

}