//
//  unit.hpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#ifndef unit_hpp
#define unit_hpp

#include <stdio.h>
#include "cells.hpp"

class Unit{
public:
    Unit(int health_capacity);
    ~Unit();
    /* Should check out how better it is to make virtual functions. I mean GetHealth and GetPosition probably would not require an overriding, but we will see.*/
    virtual int GetHealth();
    virtual int Move(Cell *cell);
    virtual Cell* GetPosition();
    virtual void Die();
private:
    const int health_capacity;
    int current_health;
    type_of_movement movement;
    Cell *position;
};

#endif /* unit_hpp */
