#pragma once
#include "Scene.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
class Select_character :
    public Scene
{
public:
    Select_character(class Game* game);
    void Init();
    void Draw();
    void NextScene();
private:
    int Select_characterImg = 0;

};

