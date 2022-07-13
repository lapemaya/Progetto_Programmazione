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
    virtual void ChooseRarityFirst();
    virtual  void ChooseRaritySecond();

    int getRarity() const {
        return Rarity;
    }
    void setRarity(int Rarity) {
        Tool::Rarity = Rarity;
    }
    int getPosx() const {
        return Posx;
    }
    void setPosx(int Posx) {
        Tool::Posx = Posx;
    }
    int getPosy() const {
        return Posy;
    }
    void setPosy(int Posy) {
        Tool::Posy = Posy;
    }
    int getBonus() const {
        return Bonus;
    }
    void setBonus(int Bonus) {
        Tool::Bonus = Bonus;
    }
    int getType() const {
        return Type;
    }
    void setType(int Type) {
        Tool::Type = Type;
    }
    int getCost() const {
        return Cost;
    }
    void setCost(int Cost) {
        Tool::Cost = Cost;
    }
    std::string *getDescription() const {
        return description;
    }
    void setDescription(std::string *description) {
        Tool::description = description;
    }
protected:
    int Rarity=0;
    int Posx=0;
    int Posy=0;
    int Bonus=0;
    int Type=0;
    int Cost=0;
    std::string* description;
};


#endif //GIOCO2_TOOL_H
