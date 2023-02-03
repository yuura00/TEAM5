#pragma once
#include "Scene.h"
#include"graphic.h"
class Playing_game :
    public Scene
{
public:
    struct Data {
        int BackGroundStageNo1;
        int BackGroundStageNo2;
        int BackGroundStageNo3;

        VECTOR2 BackGroundPos;
        VECTOR2 NextBackGroundPos;
        float ScrollSpeed;
        
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

