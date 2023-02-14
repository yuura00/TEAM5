#pragma once
#include "Scene.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
class Select_character :
    public Scene
{
public:
    struct Data {
        int GraphicImg=0;
        int CursorMoveSound;
        int DecisionSound;
        
        int SelectIconImg=0;
        VECTOR2 SelectIconPos;
        float OffsetX;
        float OffsetW;

        int SelectSw;
        int CharacterNum;
        float ExplainTextSize;
        char ExplainStrings_No1[100];
        char ExplainStrings_No2[100];
        char ExplainStrings_No3[100];
    };
    Select_character(class Game* game);
    void Create();
    void Init();
    void Update();
    void Draw();
    void NextScene();
private:
    int Select_characterImg = 0;
    Data DSChara;
};

