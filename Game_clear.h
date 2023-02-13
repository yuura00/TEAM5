#pragma once
#include "Scene.h"
class Game_clear :
    public Scene
{
public:
    Game_clear(class Game* game);
    void Create();
    void Draw();
    int Img;

    void NextScene();
};

