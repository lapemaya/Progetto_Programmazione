//
// Created by lapo on 09/06/22.
//

#ifndef GIOCO2_TOOL_H
#define GIOCO2_TOOL_H
#include <SFML/Graphics.hpp>

class Tool:public sf::Sprite {
public:
    Tool();
    Tool(int N);
    Tool(const Tool& tool);
    virtual ~Tool();
    virtual void chooseRarityFirst();
    virtual  void chooseRaritySecond();


    int getRarity() const {
        return rarity;
    }
    void setRarity(int rarity) {
        Tool::rarity = rarity;
    }
    int getPosx() const {
        return posx;
    }
    void setPosx(int posx) {
        Tool::posx = posx;
    }
    int getPosy() const {
        return posy;
    }
    void setPosy(int posy) {
        Tool::posy = posy;
    }
    int getBonus() const {
        return bonus;
    }
    void setBonus(int bonus) {
        Tool::bonus = bonus;
    }
    int getType() const {
        return type;
    }

    void setType(int type) {
        Tool::type = type;
    }
    int getCost() const {
        return cost;
    }

    void setCost(int cost) {
        Tool::cost = cost;
    }

    std::string *getDescription() const {
        return description;
    }

    void setDescription(std::string *description) {
        Tool::description = description;
    }

protected:
    int rarity=0;
    int posx=0;
    int posy=0;
    int bonus=0;
    int type=0;
    int cost=0;
    std::string* description;
};


#endif //GIOCO2_TOOL_H
