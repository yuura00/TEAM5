#pragma once
#include "Scene.h"
#include"graphic.h"
class Select_stage :
    public Scene
{
public:
    struct Data {
        int BackImg = 0;
        int SelectIconImg = 0;
        int CursorMoveSound = 0;
        int Decisionsound = 0;

        VECTOR2 SelectIconPos;
        float OffSetW;
        float OffSetX;


        int SelectSw = 0;
        int StageNum;
    };

    Select_stage(class Game* game);
    
    void Init();
    void Create();
    void Update();
    void Draw();
    void NextScene();
private:
    Data DSStage;

};

