#pragma once
#include "Bullets.h"
class Enemy_bullets :
    public Bullets
{
public:
    Enemy_bullets(class Game* game);
    void Create();
    
};