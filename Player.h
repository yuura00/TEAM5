#pragma once
#include"Game_object.h"
#include"graphic.h"
class Player :
    public Game_object
{
public:
    bool CheckError = false;
    struct Data {
        int Img = 0;
        float Angle = 0;
        int ShootSound = 0;

        COLOR Color;
        COLOR NormalColor;
        COLOR DamageColor;

        VECTOR2 Pos;
        VECTOR2 LaunchVec;
        float CollisionOffSetY;
        float Speed;
        float HalfSizeW;
        float HalfSizeH;
        float BcRadius;
        int Hp;
        float LaunchCoolTime;
        float CurLaunchCoolTime;
        float InvincibleRestTime;
        float InvincibleTime;
        
    };

private:
    Data DPlayer;
    Data DPauseGame;

public:
    Player(class Game* game);
    ~Player();
    void Create();
    void Init();
    void Update();
    void Move();
    void Launch();
    void Collision();
    void Draw();
    void SaveData();
    void SetData();
    
    VECTOR2 GetPos() { return DPlayer.Pos; }
    int GetHp() { return DPlayer.Hp; }
    
};

