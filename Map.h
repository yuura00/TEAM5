#pragma once
#include "Game_object.h"
#include"graphic.h"
class Map :
    public Game_object
{
public:
    struct Data {
        int BackGroundStageNo1;
        int BackGroundStageNo2;
        int BackGroundStageNo3;

        VECTOR2 BackGroundPos[3];
        int BackGroundImgNum;
        float ScrollSpeed;

    };
    Map(class Game* game):Game_object(game){}
    void Create();
    void Init();
    void Update();
    void Draw();
private:
    Data DMap;
};

