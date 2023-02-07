#pragma once
#include"Game_object.h"
#include"graphic.h"
class Enemy :
    public Game_object
{
public:
    bool CheckError = false;
    struct Data {
        int img = 0;
        float angle = 0;

        VECTOR2 Pos;
        VECTOR2 Vec;
        VECTOR2 LaunchVec;
        float Speed;
        float HalfSizeW;
        float HalfSizeH;
        int Hp;
        float LaunchCoolTime;
        float CurLaunchCoolTime;
        float MovingCoolTime;
        float CurMovingCoolTime;
        float MovingTime;
        int RandomIndex;
    };

private:
    Data DEnemy;
    Data DPauseGame;

public:
    Enemy(class Game* game);
    ~Enemy();
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
    void Kill();


    VECTOR2 GetPos() { return DEnemy.Pos; }
    int GetHp() { return DEnemy.Hp; }

};

