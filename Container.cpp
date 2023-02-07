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

	Data.sStage.SelectIconPos = VECTOR2(0, 69);
	Data.sStage.OffSetX = 0;

	Data.sStage.SelectSw = 0;
	Data.sStage.StageNum = 3;
	Data.sStage.OffSetW = 640;

	//map
	Data.map.BackGroundPos [0] = VECTOR2(600, 0);
	Data.map.BackGroundPos[1] = VECTOR2(600, Data.map.BackGroundPos[0].y - height +3);
	Data.map.BackGroundPos[2] = VECTOR2(600, Data.map.BackGroundPos[1].y - height + 3);
	Data.map.BackGroundImgNum = 3;
	Data.map.ScrollSpeed = 100;

	//player
	Data.player.Pos = VECTOR2(width / 2, height - 100);
	Data.player.LaunchVec = VECTOR2 (0, -1);
	Data.player.Hp = 100;
	Data.player.HalfSizeW = 75/2.0f;
	Data.player.HalfSizeH = 75/2.0f;
	Data.player.Speed = 300;
	Data.player.LaunchCoolTime = 0.1f;
	Data.player.CurLaunchCoolTime = 0;

	Data.playerBullet.TotalNum = 50;
	Data.playerBullet.CurNum = 0;
	Data.playerBullet.AdvSpeed = 300;
	Data.playerBullet.AngSpeed = 0;
	Data.playerBullet.BcRadius = 3;
	Data.playerBullet.LaunchDistance = 35;

	//enemy
	Data.enemy.Pos = VECTOR2(width / 2, 100);
	Data.enemy.Vec = VECTOR2(0, 0);
	Data.enemy.LaunchVec = VECTOR2(0,1);
	Data.enemy.Hp = 100;
	Data.enemy.HalfSizeW = 50 / 2.0f;
	Data.enemy.HalfSizeH = 50 / 2.0f;
	Data.enemy.Speed = 100;
	Data.enemy.MovingTime = 0;
	Data.enemy.MovingCoolTime = 0;
	Data.enemy.CurMovingCoolTime = 0;
	Data.enemy.LaunchCoolTime = 0.3f;
	Data.enemy.CurLaunchCoolTime = 0;
}
void Container::Load_graphic()
{
	Data.title.TitleImg = loadImage("assets\\Title.png");
	Data.sStage.BackImg = loadImage("assets\\stageSelect_v3_a.png");
	Data.sStage.SelectIconImg = loadImage("assets\\Select_Icon_v2_a.png");
	Data.map.BackGroundStageNo1 = loadImage("assets\\loop_material.png");
	Data.player.img = loadImage("assets\\Player3.png");
}
