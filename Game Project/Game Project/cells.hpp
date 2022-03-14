//
//  cells.hpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#ifndef cells_hpp
#define cells_hpp

#include <stdio.h>
#include "unit.hpp"
#include "building.hpp"
#include "player.hpp"

enum type_of_movement{
    ground,
    water,
    air
};

class Cell{
public:
    Cell(int production);
    ~Cell();
    void SetPlayer(Player* player);
    void AddUnit(Unit* unit);
    void AddBuilding(Building* building);
    int GetProduction();
    Player* GetPlayer();
    Unit* GetUnit();
    Building* GetBuilding();
private:
    type_of_movement who_can_move;
    const int production;
    /*Here should be a Host pointer, a unit pointer, and a building pointer. If they are not NULL, and you want to move there, then action function is called. which returns a boolean whether you are going to move to the cell or not*/
    Unit *unit_presence; //Should be unit pointer
    Building *building_presence; //Should be building pointer
    Player *player_owner; //Should be Host pointer
    
};

#endif /* cells_hpp */
