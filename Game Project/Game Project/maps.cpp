//
//  maps.cpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#include "maps.hpp"

Map::Map(int number_of_cells)
    :number_of_cells(number_of_cells), initialized(true)
{
    this->Map::Initialize();
    
}

void Map::Initialize(){
    //????????
}

bool Map::IsInitialized(){
    return this->initialized;
}
