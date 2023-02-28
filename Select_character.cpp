#include "Select_character.h"
#include"Game.h"
#include"Container.h"
#include"sound.h"
Select_character::Select_character(Game* game)
	:Scene(game)
{

}

void Select_character::Create()
{
	DSChara = GetGame()->GetContainer()->GetData().sCharacter;
}

void Select_character::Init()
{

}

void Select_character::Update()
{
	if (isTrigger(KEY_A) && DSChara.SelectSw > 0) {
		DSChara.SelectSw--;
		playSound(DSChara.CursorMoveSound);
	}
	if (isTrigger(KEY_D) && DSChara.SelectSw < DSChara.CharacterNum-1) {
		DSChara.SelectSw++;
		playSound(DSChara.CursorMoveSound);
	}
	if (DSChara.SelectSw == 0) {
		DSChara.OffsetX = 0;
	}
	if (DSChara.SelectSw == 1) {
		DSChara.OffsetX = DSChara.OffsetW;
	}
	if (DSChara.SelectSw == 2) {
		DSChara.OffsetX = DSChara.OffsetW*2;
	}
}
void Select_character::Draw()
{
	clear();
	rectMode(CORNER);
	image(DSChara.GraphicImg, 0, 0);
	image(DSChara.SelectIconImg, DSChara.SelectIconPos.x+DSChara.OffsetX, DSChara.SelectIconPos.y);

}

void Select_character::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		GetGame()->SetCharaNum(DSChara.SelectSw);
		playSound(DSChara.DecisionSound);
		GetGame()->ChangeScene(GetGame()->ESMachine);
	}
	if (isTrigger(KEY_P)) {
		playSound(DSChara.DecisionSound);
		GetGame()->ChangeScene(GetGame()->ESStage);
	}
}
