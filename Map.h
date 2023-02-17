#pragma once
#include "Game_object.h"
#include"graphic.h"
class Map :
    public Game_object
{
public:
    bool CheckError = false;
    struct Data {
        
        int BackGroundStageNo1;
        int BackGroundStageNo2;
        int BackGroundStageNo3;
        int SideImg;

        VECTOR2 BackGroundPos[3];
        int BackGroundImgNum;
        float ScrollSpeed;
        float StageX;
        float StageY;
        float battleW;
        float WorldY;
        float BossFazeY;

        bool BossFlag = false;
    };
    Map(class Game* game):Game_object(game){}
    void Create();
    void Init();
    void Update();
    void Draw();
    void SetData();
    void SaveData();
    //getter
    float GetStageX() { return DMap.StageX; }
    float GetStageY() { return DMap.StageY; }
    float GetWorldY() { return DMap.WorldY; }
    
    bool GetBossFlag() { return DMap.BossFlag; }
private:
    Data DMap;
    Data DPauseGame;
};

