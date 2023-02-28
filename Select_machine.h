#pragma once
#include "Scene.h"
#include"graphic.h"
class Select_machine :
    public Scene
{
public:
    struct Data {
        int GraphicImg = 0;
        int CursorMoveSound;
        int DecisionSound;

        int SelectIconImg;
        VECTOR2 SelectIconPos;
        float OffsetX;
        float OffsetW;

        int SelectSw;
        int machineNum;
        float ExplainTextSize;
        char ExplainStrings_No1[100];
        char ExplainStrings_No2[100];
        char ExplainStrings_No3[100];
    };
    Select_machine(class Game* game);
    void Create();
    void Init();
    void Update();
    void Draw();
    void NextScene();

    int GetSelectMachineNum() { return DSMachine.SelectSw; }
private:
    Data DSMachine;
};

