#pragma once
#include "Scene.h"
class Select_stage :
    public Scene
{
public:
    Select_stage(class Game* game);
    void Init();
    void Draw();
    void NextScene();

};

