#include"Game.h"
#include"Container.h"
#include "Title.h"
#include"graphic.h"
#include"input.h"
#include"sound.h"
Title::Title(Game* game)
	:Scene(game)
{

}
void Title::Init()
{
	DTitle.cl = 0;
	DTitle.rw = 0;
	DTitle.Filter = DTitle.DFilter;
}

void Title::Draw()
{

	clear();

	rectMode(CORNER);
	image(DTitle.TitleImg, DTitle.ImgPos.x, DTitle.ImgPos.y, 0, DTitle.ImgSize);
	fill(DTitle.rectColor.r, DTitle.rectColor.g, DTitle.rectColor.b, DTitle.Filter);
	rect(DTitle.SignalRectPos.x + DTitle.Dx, DTitle.SignalRectPos.y + DTitle.Dy, DTitle.RectW + DTitle.Ws, DTitle.RectH);


}

void Title::NextScene()
{
	//start
	if (isTrigger(KEY_SPACE)&&DTitle.sw[DTitle.cl][DTitle.rw]==0) {
		playSound(DTitle.DecisionSound);
		GetGame()->ChangeScene(GetGame()->ESStage);
		
	}

	//quit
	if (isTrigger(KEY_SPACE) && DTitle.sw[DTitle.cl][DTitle.rw] == 5) {
		playSound(DTitle.DecisionSound);
		GetGame()->Shutdown();
		
	}

}

void Title::Create()
{
	DTitle = GetGame()->GetContainer()->GetData().title;
}

void Title::Update()
{
	//select rect operation
	if (DTitle.Filter > DTitle.MinFilter && DTitle.Filter <= DTitle.DFilter) {
		DTitle.Filter -= DTitle.MinFilter;
	}
	else {
		DTitle.Filter = DTitle.DFilter;
	}
	
	if (isTrigger(KEY_S) && DTitle.rw < 2) {
		DTitle.rw++;
		playSound(DTitle.CursorMoveSound);
	}
	if (isTrigger(KEY_W) && DTitle.rw > 0) {
		DTitle.rw--;
		playSound(DTitle.CursorMoveSound);
	}
	if (isTrigger(KEY_D) && DTitle.cl!= 1){
		DTitle.cl = 1;
		playSound(DTitle.CursorMoveSound);
	}
	if (isTrigger(KEY_A)&&DTitle.cl!=0) {
		DTitle.cl = 0;
		playSound(DTitle.CursorMoveSound);
	}
	if (DTitle.sw[DTitle.cl][DTitle.rw] == 0) {
		DTitle.Dx = 0;
		DTitle.Dy = 0;
		DTitle.Ws = 0;
	}
	else if (DTitle.sw[DTitle.cl][DTitle.rw] == 1) {
		DTitle.Dx = 0;
		DTitle.Dy = 255;
		DTitle.Ws = 0;

	}
	else if (DTitle.sw[DTitle.cl][DTitle.rw] == 2) {
		DTitle.Dx = 0;
		DTitle.Dy = 530;
		DTitle.Ws = 0;
	}
	else if (DTitle.sw[DTitle.cl][DTitle.rw] == 3) {
		DTitle.Dx = 830;
		DTitle.Dy = 0;
		DTitle.Ws = 130;
	}
	else if (DTitle.sw[DTitle.cl][DTitle.rw] == 4) {
		DTitle.Dx = 830;
		DTitle.Dy = 255;
		DTitle.Ws = 130;
	}
	else if (DTitle.sw[DTitle.cl][DTitle.rw] == 5) {
		DTitle.Dx = 830;
		DTitle.Dy = 530;
		DTitle.Ws = 130;
	}

}
