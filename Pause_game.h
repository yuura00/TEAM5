#pragma once
#include "Scene.h"
class Pause_game :
    public Scene
{
public:

    Pause_game(class Game* game) :Scene(game) {}
    void Create();
    void Draw();
    void NextScene();
};

