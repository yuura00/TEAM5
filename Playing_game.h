#pragma once
#include "Scene.h"
#include"graphic.h"
#include"Game.h"
class Playing_game :
    public Scene
{
public:
    
    struct Data {
        float stageW;
        int enemyHp[Game::Enemy_num];
        float enemyPosY[Game::Enemy_num];
        int KillCnt;
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

