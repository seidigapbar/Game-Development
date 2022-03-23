//
//  building.hpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#ifndef building_hpp
#define building_hpp

#include "player.hpp"
#include <stdio.h>

class Building{
public:
    Building();
    ~Building();
    Player* GetPlayer();
private:
    const int health_capacity; //Maybe not applicable?
    const int building_price;
    Player* player_owner;
};

#endif /* building_hpp */
