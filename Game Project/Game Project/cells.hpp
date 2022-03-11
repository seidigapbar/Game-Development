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

enum type_of_movement{
    ground,
    water,
    air
};

class Cell{
public:
    Cell(int production);
    ~Cell();
    void* GetHost();
    void SetHost(void* host);
    void AddUnit(void* unit);
    void AddBuilding(void* building);
    int GetProduction();
    Unit* GetUnit();
    void* GetBuilding();
private:
    type_of_movement who_can_move;
    const int production;
    /*Here should be a Host pointer, a unit pointer, and a building pointer. If they are not NULL, and you want to move there, then action function is called. which returns a boolean whether you are going to move to the cell or not*/
    Unit *unit_presence; //Should be unit pointer
    void *building_presence; //Should be building pointer
    void *host; //Should be Host pointer
    
};

#endif /* cells_hpp */
