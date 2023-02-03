#pragma once
#include"Game_object.h"
#include"graphic.h"
class Player :
    public Game_object
{
public:
    struct Data {
        int img = 0;
        float angle = 0;

        VECTOR2 Pos;
        VECTOR2 Vec;
        float Speed;
        float HalfSizeW;
        float HalfSizeH;
        int Hp;


    };

private:
    Data DPlayer;
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
    
    VECTOR2 GetPos() { return DPlayer.Pos; }
    int GetHp() { return DPlayer.Hp; }
    
};

