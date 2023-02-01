#include "Select_stage.h"
#include"Game.h"
#include"Container.h"
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
	rectMode(CORNER);
	image(DSStage.BackImg, 0, 0);
	image(DSStage.SelectIconImg, DSStage.SelectIconPos.x + DSStage.OffSetX, DSStage.SelectIconPos.y);

}

void Select_stage::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->ChangeScene(GetGame()->ESChara);
	}
	if (isTrigger(KEY_P)) {
		GetGame()->ChangeScene(GetGame()->ETitle);
	}
	
}

void Select_stage::Create()
{
	DSStage = GetGame()->GetContainer()->GetData().sStage;
}

void Select_stage::Update()
{
	if (isTrigger(KEY_A) && DSStage.SelectSw >= 1) {
		DSStage.SelectSw--;
	}
	if (isTrigger(KEY_D) && DSStage.SelectSw <= DSStage.StageNum-2){
		DSStage.SelectSw++;
	}
	DSStage.OffSetX = DSStage.OffSetW * DSStage.SelectSw;
	
}
