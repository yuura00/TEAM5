#pragma once
#include "Bullets.h"
class Enemy_bullets :
    public Bullets
{
public:
    int ENum;

    Enemy_bullets(class Game* game);
    void Create();
    
};