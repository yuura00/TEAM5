#include "Container.h"
#include"graphic.h"
Container::Container()
{
}

void Container::Load()
{
	Set_data();
	Load_graphic();
}

void Container::Set_data()
{
	//Title data
	Data.title.ImgPos = VECTOR2(0, 0);
	Data.title.ImgSize = 3.0f;
	Data.title.DFilter = 170;
	Data.title.Filter = Data.title.DFilter;
	Data.title.MinFilter = 4;
	Data.title.rectColor = COLOR(255, 255, 255);
	Data.title.SignalRectPos = VECTOR2(260, 280);
	Data.title.RectW = 500;
	Data.title.RectH = 150;
	Data.title.Dx = 0;
	Data.title.Dy = 0;
	Data.title.Ws = 0;

	Data.title.sw[0][0] = 0;//start
	Data.title.sw[0][1] = 1;
	Data.title.sw[0][2] = 2;//score
	Data.title.sw[1][0] = 3;//practice
	Data.title.sw[1][1] = 4;//option
	Data.title.sw[1][2] = 5;//quit

	//select stage data
	
	Data.sStage.SelectIconPos = VECTOR2(0,69);
	Data.sStage.OffSetX = 0;
	
	Data.sStage.SelectSw = 0;
	Data.sStage.StageNum = 3;
	Data.sStage.OffSetW = 654;
}

void Container::Load_graphic()
{
	Data.title.TitleImg = loadImage("assets\\Title.png");
	Data.sStage.BackImg = loadImage("assets\\StageSelect_v2.png");
	Data.sStage.SelectIconImg = loadImage("assets\\Select_Icon.png");
}
