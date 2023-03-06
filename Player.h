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
        int UltImg = 0;
        float Angle = 0;
        int ShootSound = 0;

        COLOR Color;
        COLOR NormalColor;
        COLOR DamageColor;

        VECTOR2 Pos;
        VECTOR2 LaunchVec;
        float CollisionOffSetY;
        int Hp;
        int InitHp;
        float Speed;
        int Damage;
        float HalfSizeW;
        float HalfSizeH;
        float BcRadius;
        float InitTriggerCoolTime;
        float TriggerCooltime;
        float LaunchCoolTime;
        float CurLaunchCoolTime;
        float InvincibleRestTime;
        float InvincibleTime;
        float UltPoint;
        float UltChargeSp;
        float CurUltDeltaTime;
        float MaxUltPoint;
        float UltTime;
        bool UltFlag = false;
        bool UltTimeFlag = false;
    };

private:
    Data DPlayer;
    Data DPauseGame;

public:
    Player(class Game* game);
    ~Player();
    void SetData(const Data& data);
    virtual void Create();
    void Init();
    void Update();
    void Move();
    void Launch();
    void Collision();
    void Draw();
    void SaveData();
    void SetData();
    void CharaUlt(int i);
    
    VECTOR2 GetPos() { return DPlayer.Pos; }
    int GetHp() { return DPlayer.Hp; }
    int GetDmg() { return DPlayer.Damage;}
    int GetUltP() { return DPlayer.UltPoint; }
    void AddUltP(int i) { DPlayer.UltPoint += i; }
    bool GetUltFlag() { return DPlayer.UltFlag; }

};

