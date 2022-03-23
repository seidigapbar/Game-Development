//
//  player.hpp
//  Game Project
//
//  Created by Sanzhar Seidigapbar on 11.03.2022.
//

#ifndef player_hpp
#define player_hpp

#include <stdio.h>
#include <string>

class Player{
public:
    Player();
    ~Player();
private:
    static uint8_t number_of_players;
    u_int64_t gold;
    const int ID;
};

#endif /* player_hpp */
