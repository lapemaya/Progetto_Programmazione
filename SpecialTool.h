//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_SPECIALTOOL_H
#define GIOCO2_SPECIALTOOL_H


#include "Tool.h"

class SpecialTool:public Tool {
public:
    SpecialTool(int N);
    virtual ~SpecialTool();

    SpecialTool(const Tool& tool,int O);
    int getSpecial() const {
        return Special;
    }
protected:
    int Special;
};
#endif //GIOCO2_SPECIALTOOL_H
