#pragma once
#include "Scene.h"
#include"graphic.h"
class Playing_game :
    public Scene
{
public:
    struct Data {

    };
    Playing_game(class Game* game):Scene(game){}
    void Create();
    void Init();
    void Update();
    
    void Draw();
private:
    Data DPlayingGame;
    
    void NextScene();
};

