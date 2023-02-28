#pragma once
#include"Game_object.h"
#include"graphic.h"
#include"Game.h"
class Enemy :
    public Game_object
{
public:
    bool CheckError = false;
    int t;
    int EnemyNo;
    int KillCnt=0;
    bool Life=true;
  
    struct Data {
        int EnemyType;
        int img = 0;
        float angle = 0;
        
        COLOR Color;
        COLOR NormalColor;
        COLOR DamageColor;
        VECTOR2 Pos;
        float InitPosY;
        float OffSetY;
        VECTOR2 Vec;
        VECTOR2 LaunchVec;
        float Speed;
        float HalfSizeW;
        float HalfSizeH;
        int Hp;
        bool BattleFlag=false;
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
    Data DEnemy;
    Data DPauseGame;
    
public:
    Enemy(class Game* game);
    
    void SetData(const Data& data);
    virtual void Create();
    void Init(int enemyNo);
    void Update();
    virtual void Move();
    void RandomMove();
    virtual void Launch();
    void Collision();
    void Draw();
    void SaveData();
    void SetData();
   


    VECTOR2 GetPos() { return DEnemy.Pos; }
    int GetHp() { return DEnemy.Hp; }
   
};

