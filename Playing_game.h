#pragma once
#include "Scene.h"
class Playing_game :
    public Scene
{
public:
    struct Data {
        int BackGroundStageNo1;
        int BackGroundStageNo2;
        int BackGroundStageNo3;


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

