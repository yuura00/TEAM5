#include "Play_game.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
Play_game::Play_game(Game* game)
	:Scene(game)
{
	Play_gameImg = loadImage("assets\\ConceptArt.png");
	
}

void Play_game::Init()
{

}

void Play_game::Update()
{
	
}

void Play_game::Draw()
{
	clear();
	rectMode(CORNER);
	image(Play_gameImg, 0, 0, 0);
	

}

void Play_game::ChangeState()
{
	if (isTrigger(KEY_ESCAPE)&&CurState!=EPause) {
		CurState = EPause;
	}
	if (isTrigger(KEY_SPACE) && CurState == EPause) {
		CurState = EPlaying;
	}
	
}

void Play_game::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->ETitle);
	}
	
}
