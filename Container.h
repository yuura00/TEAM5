#pragma once
#include "Game_object.h"
#include"Title.h"
#include"Player.h"
class Container 
{
private:
    struct ALL_DATA {
        Title::Data title;
        Player::Data player;
    };
    ALL_DATA Data;

    
    void Set_data();
    void Load_graphic();
public:
    Container();
    void Load();
    const ALL_DATA GetData() { return Data; }
};
