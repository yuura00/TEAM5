#include "Select_machine.h"
#include"Game.h"
#include"Container.h"
#include"sound.h"
Select_machine::Select_machine(Game* game)
	:Scene(game)
{

}

void Select_machine::Create()
{
	DSMachine = GetGame()->GetContainer()->GetData().sMachine;
}

void Select_machine::Init()
{

}

void Select_machine::Update()
{
	if (isTrigger(KEY_A) && DSMachine.SelectSw > 0) {
		DSMachine.SelectSw--;
		playSound(DSMachine.CursorMoveSound);
	}
	if (isTrigger(KEY_D) && DSMachine.SelectSw < DSMachine.machineNum - 1) {
		DSMachine.SelectSw++;
		playSound(DSMachine.CursorMoveSound);
	}
	if (DSMachine.SelectSw == 0) {
		DSMachine.OffsetX = 0;
	}
	if (DSMachine.SelectSw == 1) {
		DSMachine.OffsetX = DSMachine.OffsetW;
	}
	if (DSMachine.SelectSw == 2) {
		DSMachine.OffsetX = DSMachine.OffsetW * 2;
	}
}
void Select_machine::Draw()
{
	clear();
	rectMode(CORNER);
	image(DSMachine.GraphicImg, 0, 0);
	image(DSMachine.SelectIconImg, DSMachine.SelectIconPos.x + DSMachine.OffsetX, DSMachine.SelectIconPos.y);

}

void Select_machine::NextScene()
{
	if (isTrigger(KEY_SPACE)) {
		playSound(DSMachine.DecisionSound);
		GetGame()->SetMachineNum(DSMachine.SelectSw); 
		GetGame()->ChangeScene(GetGame()->EPlaying);
	}
	if (isTrigger(KEY_P)) {
		playSound(DSMachine.DecisionSound);
		GetGame()->ChangeScene(GetGame()->ESChara);
	}
}
