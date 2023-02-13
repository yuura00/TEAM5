#include "Game_clear.h"
#include"Game.h"
#include"Container.h"
#include"input.h"
Game_clear::Game_clear(Game* game)
	:Scene(game)
{

}

void Game_clear::Create()
{
	Img = GetGame()->GetContainer()->GetData().GameClearImg;
}

void Game_clear::Draw()
{
	clear();
	rectMode(CORNER);
	imageColor(255);
	image(Img, 0, 0, 0, 3.0f);
}

void Game_clear::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->ESStage);
	}
	
}
