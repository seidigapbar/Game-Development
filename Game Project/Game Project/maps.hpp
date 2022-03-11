//
//  maps.hpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#ifndef maps_hpp
#define maps_hpp

#include <stdio.h>

class Map{
public:
    Map(int number_of_cells);
    ~Map();
    void Initialize();
    bool IsInitialized();
private:
    bool initialized;
    int number_of_cells;
};

#endif /* maps_hpp */
