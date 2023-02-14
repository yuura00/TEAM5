#include "Game_over.h"
#include"Game.h"
#include"Container.h"
#include"input.h"
Game_over::Game_over(Game* game)
	:Scene(game)
{

}

void Game_over::Create()
{
	Img = GetGame()->GetContainer()->GetData().GameOverImg;
}

void Game_over::Draw()
{
	clear();
	rectMode(CORNER);
	imageColor(255);
	image(Img, 0, 0, 0, 3.0f);
}

void Game_over::NextScene()
{
	if (isTrigger(KEY_Z)) {
		GetGame()->ChangeScene(GetGame()->ESStage);
	}
	
}
