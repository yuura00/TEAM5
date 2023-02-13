#include "Playing_game.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Game.h"
#include"Container.h"
#include"Player.h"
#include"Player_bullets.h"
#include"Enemy.h"
#include"Enemy_bullets.h"
void Playing_game::Create()
{
	DPlayingGame = GetGame()->GetContainer()->GetData().playingGame;
	
	GetGame()->GetPlayer()->Create();
	
	GetGame()->GetEnemy()->Create();
	
	GetGame()->GetMap()->Create();

}


void Playing_game::Init()
{
	initDeltaTime();

	GetGame()->GetMap()->Init();
	GetGame()->GetPlayer()->Init();
	
	GetGame()->GetEnemy()->Init();
	
	GetGame()->GetPBullets()->Init();
	GetGame()->GetEBullets()->Init();
}

void Playing_game::Update()
{
	setDeltaTime();

	GetGame()->GetMap()->Update();
	GetGame()->GetPlayer()->Update();
	
	GetGame()->GetEnemy()->Update();
	
	GetGame()->GetPBullets()->Update();
	GetGame()->GetEBullets()->Update();
}

void Playing_game::Draw()
{
	clear();
	print(delta);
	GetGame()->GetMap()->Draw();
	GetGame()->GetPlayer()->Draw();
	
	GetGame()->GetEnemy()->Draw();
	
	
	GetGame()->GetPBullets()->Draw();
	GetGame()->GetEBullets()->Draw();

}

void Playing_game::NextScene()
{
	if (isTrigger(KEY_P)&&GetGame()->GetCurState()!=GetGame()->EPauseGame) {
		GetGame()->GetPlayer()->SaveData();
		GetGame()->GetMap()->SaveData();
		
		GetGame()->ChangePause(GetGame()->EPauseGame);
	}
	if (isTrigger(KEY_Z)) {
		GetGame()->ChangeScene(GetGame()->EGameClear);
	}
}
