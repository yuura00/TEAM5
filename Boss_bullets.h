#pragma once
#include "Bullets.h"
class Boss_bullets :
    public Bullets
{
public:
    Boss_bullets(class Game* game):Bullets(game){}
    void Create();
};

