#pragma once
#include"Game_object.h"
#include"graphic.h"
#include"Game.h"
class Boss :
    public Game_object
{
public:
    bool CheckError = false;
   
    struct Data {
        int BossType;

        int img = 0;
        float angle = 180;

        COLOR Color;
        COLOR NormalColor;
        COLOR DamageColor;
        VECTOR2 Pos;
        VECTOR2 Vec;
        VECTOR2 LaunchVec;
        float Speed;
        int Hp;
        float BcRadius;
        float CollisionOffSetY;
        float LaunchCoolTime;
        float CurLaunchCoolTime;
        float MovingCoolTime;
        float CurMovingCoolTime;
        float MovingTime;
        int RandomIndex;
    };

private:
    Data DBoss;
    Data DPauseGame;
    
public:
    Boss(class Game* game):Game_object(game){}
    
    void Create();
    void Init();
    void Update();
    void Move();
    void RandomMove();
    void Launch();
    void Collision();
    void Draw();
    void SaveData();
    void SetData();
    void Kill(int no);


    VECTOR2 GetPos() { return DBoss.Pos; }
    int GetHp() { return DBoss.Hp; }
    
};

