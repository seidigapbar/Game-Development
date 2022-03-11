//
//  unit.cpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#include "unit.hpp"

Unit::Unit(int health_capacity)
    :health_capacity(health_capacity)
{
    
}

int Unit::GetHealth()
{
    return this->current_health;
}

Cell* Unit::GetPosition()
{
    return this->position;
}
