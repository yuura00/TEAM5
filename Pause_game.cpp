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
}

void Pause_game::NextScene()
{
	if (isTrigger(KEY_P)) {
		GetGame()->ChangeScene(GetGame()->ESStage);
	}
	if (isTrigger(KEY_Z)) {
		GetGame()->GetPlayer()->SetData();
		GetGame()->GetMap()->SetData();
		GetGame()->ChangeState(GetGame()->EPlaying);
		setDeltaTime();
	}
}