#pragma once
#include "Enemy.h"
class Enemy_no1 :
    public Enemy
{
public:
    Enemy_no1(class Game* game):Enemy(game){}
    void Move();
    void Launch();
private:



};

