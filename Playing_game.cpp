#include "Playing_game.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
#include"Container.h"
void Playing_game::Create()
{
	DPlayingGame = GetGame()->GetContainer()->GetData().playingGame;
}

void Playing_game::Init()
{
}

void Playing_game::Update()
{
}

void Playing_game::Draw()
{
	clear();
	rectMode(CENTER);
	image(DPlayingGame.BackGroundStageNo1, width / 2, height / 2);
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
