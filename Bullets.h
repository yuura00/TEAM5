#pragma once
#include "Game_object.h"
#include"VECTOR2.h"
class Bullets :
    public Game_object
{
public:
    struct Data {
        int EnemyNum = 0;
        int Img = 0;
        float ImgSize = 0;
        int TotalNum;
        int CurNum = 0;
        float AdvSpeed = 0;
        float AngSpeed = 0;
        float LaunchDistance = 0;
        float BcRadius = 0;
        int Damage = 0;
    };
private:
    Data PBullet;
    struct Bullet
    {
        VECTOR2 Pos;
        VECTOR2 Vec;
        float Angle;
    };
    Bullet* PBullets = 0;
  
public:
    Bullets(class Game* game);
    virtual ~Bullets();
    virtual void Create();
    void Init();
    void Launch(const VECTOR2& pos, const VECTOR2& vec);
    void Update();
    void Draw();
    void Kill(int i);
    void SetBulletData(const Data& data);

    VECTOR2 GetPos(int i) { return PBullets[i].Pos; }
    int GetCurNum() { return PBullet.CurNum; }
    float GetBcRadius() { return PBullet.BcRadius; }
    int GetDamage() { return PBullet.Damage; }
    int GetEnemyNum() { return PBullet.EnemyNum; }
};

