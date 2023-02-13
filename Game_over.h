#pragma once
#include "Scene.h"
class Game_over :
    public Scene
{
public:
    Game_over(class Game* game);
    void Create();
    void Draw();
    void NextScene();
    int Img;
};

