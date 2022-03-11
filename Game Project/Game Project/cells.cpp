//
//  cells.cpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#include "cells.hpp"

Cell::Cell(int production)
    :production(production)
{
    
}

void* Cell::GetHost(){
    return this->host;
}

void Cell::SetHost(void* host){
    this->host = host;
}

int Cell::GetProduction(){
    return this->production;
}

void Cell::AddUnit(void* unit){
    //if (unit.type_of_movement is in who_can_move)
    //else perror("Cannot move here!");
    if (this->unit_presence != NULL)
    {
        //Do something like unit_presence.Action();
    }
    if (this->building_presence != NULL)
    {
        //Do something like  building_presence.Action();
    }
    this->unit_presence = unit;
    
}

void Cell::AddBuilding(void* building){
    if (this->unit_presence != NULL)
    {
        //Check if the unit friendly, something like
        //unit_presence.IsFriendly() then possible
    }
    if (this->building_presence != NULL)
    {
        perror("There is already building there!\n");
        return;
    }
    this->building_presence = building;
}

Unit* Cell::GetUnit(){
    return this->unit_presence;
}

void* Cell::GetBuilding()
{
    return this->building_presence;
}
