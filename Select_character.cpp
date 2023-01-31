#include "Select_character.h"

Select_character::Select_character(Game* game)
	:Scene(game)
{

}

void Select_character::Init()
{

}

void Select_character::Draw()
{
	clear();
	fill(255);
	print("SELECT CHARA");

}

void Select_character::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->EPStage);
	}
}
