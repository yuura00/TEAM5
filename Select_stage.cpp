#include "Select_stage.h"
#include"Game.h"
#include"graphic.h"
#include"input.h"
Select_stage::Select_stage(class Game* game)
	:Scene(game)
{

}

void Select_stage::Init()
{
}

void Select_stage::Draw()
{
	clear();
	fill(255);
	print("SELECT STAGE");


}

void Select_stage::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->ESChara);
	}
	
}
