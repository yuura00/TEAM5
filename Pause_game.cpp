#include "Pause_game.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Game.h"
#include"Player.h"
#include"Map.h"
void Pause_game::Create()
{
	
}

void Pause_game::Draw()
{
	clear();
	
	GetGame()->GetMap()->Draw();
	GetGame()->GetPlayer()->Draw();
	rectMode(CORNER);
	fill(0, 0, 0, 170);
	rect(0, 0, width, height);
}

void Pause_game::NextScene()
{
	if (isTrigger(KEY_P)) {
		GetGame()->ChangeScene(GetGame()->EGameOver);
	}
	if (isTrigger(KEY_Z)) {
		GetGame()->GetPlayer()->SetData();
		GetGame()->GetMap()->SetData();
		GetGame()->ChangePause(GetGame()->EPlaying);
		setDeltaTime();
	}
}
