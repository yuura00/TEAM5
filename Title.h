#pragma once
#include "Scene.h"
#include"graphic.h"
class Title :
    public Scene
{
public:
    struct Data {
        VECTOR2 ImgPos;
        float ImgSize;
        int TitleImg;

        //select signal
        int sw[2][3];
        int rw=0;
        int cl=0;
        float Filter;
        float DFilter;
        float MinFilter;

        COLOR rectColor;
        VECTOR2 SignalRectPos;
        float RectW;
        float RectH;
        float Dy=0;
        float Dx=0;
        float Ws=0;
        
    };
    Title(class Game* game);
    void Create();
    void Init();
    void Update();
    void Draw();
    void NextScene();
private:
    Data DTitle;

};

