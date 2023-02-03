#include "Playing_game.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Game.h"
#include"Container.h"
#include"Player.h"
void Playing_game::Create()
{
	DPlayingGame = GetGame()->GetContainer()->GetData().playingGame;
}


void Playing_game::Init()
{
	initDeltaTime();

	GetGame()->GetMap()->Init();
	GetGame()->GetPlayer()->Init();
	
}

void Playing_game::Update()
{
	setDeltaTime();

	GetGame()->GetMap()->Update();
	GetGame()->GetPlayer()->Update();

}

void Playing_game::Draw()
{
	clear();
	
	GetGame()->GetMap()->Draw();
	GetGame()->GetPlayer()->Draw();
}

void Playing_game::NextScene()
{
	if (isTrigger(KEY_P)&&GetGame()->GetCurState()!=GetGame()->EPauseGame) {
		GetGame()->ChangeState(GetGame()->EPauseGame);
	}
	if (isTrigger(KEY_Z)) {
		GetGame()->ChangeState(GetGame()->ESStage);
	}
}
