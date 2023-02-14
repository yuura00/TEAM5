#pragma once
#include"Game_object.h"
#include"graphic.h"
#include"Game.h"
class Enemy :
    public Game_object
{
public:
    bool CheckError = false;
    int KillCnt = 0;
    struct TypeData {
        int Hp;
        float BcRadius;
        float Speed;
        int img = 0;
        float LaunchCoolTime;
    };
    struct Data {
        int EnemyType;
        
        int img = 0;
        float angle = 180;
        
        COLOR Color;
        COLOR NormalColor;
        COLOR DamageColor;
        VECTOR2 Pos;
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
    Data DEnemy[Game::Enemy_num];
    Data DPauseGame[Game::Enemy_num];
    TypeData TData[Game::Etype_num];
public:
    Enemy(class Game* game);
    ~Enemy();
    void SetEnemyData(const Data& data);
    void Create();
    void Init();
    void Update();
    virtual void Move();
    void RandomMove();
    virtual void Launch();
    void Collision();
    void Draw();
    void SaveData();
    void SetData();
    void Kill(int no);


    VECTOR2 GetPos(int enemyNo) { return DEnemy[enemyNo].Pos; }
    int GetHp(int enemyNo) { return DEnemy[enemyNo].Hp; }
    int GetKill() { return KillCnt; }
};

