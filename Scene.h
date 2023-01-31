#pragma once
#include"Game_object.h"
class Scene:
	public Game_object
{
public:
	Scene(class Game* game):Game_object(game){}
    virtual void Create();
    virtual void Init();
    virtual void Proc();
private:
    virtual void Update();
    virtual void Draw();
    virtual void NextScene();
};

