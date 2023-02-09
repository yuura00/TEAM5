#pragma once
#include "Bullets.h"
class Player_bullets :
    public Bullets
{
public:
    Player_bullets(class Game* game);
    void Create();
};

