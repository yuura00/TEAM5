#include "Pause_game.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
void Pause_game::Create()
{

}

void Pause_game::Draw()
{
	clear();
	print("pause");
}

void Pause_game::NextScene()
{
	if (isTrigger(KEY_P)) {
		GetGame()->ChangeState(GetGame()->ESStage);
	}
	if (isTrigger(KEY_Z)) {
		GetGame()->ChangeState(GetGame()->EPlaying);
	}
}
