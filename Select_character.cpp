#include "Select_character.h"

Select_character::Select_character(Game* game)
	:Scene(game)
{

}

void Select_character::Create()
{

}

void Select_character::Init()
{

}

void Select_character::Draw()
{
	clear();
	rectMode(CORNER);
	print("Select character");
}

void Select_character::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->EPlaying);
	}
	if (isTrigger(KEY_P)) {
		GetGame()->ChangeScene(GetGame()->ESStage);
	}
}
