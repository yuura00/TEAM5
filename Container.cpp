#include "Container.h"
#include"graphic.h"
#include"sound.h"
Container::Container()
{
}

void Container::Load()
{
	Set_data();
	Load_graphic();
	LoadSound();
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
	Data.map.StageX = 600;
	Data.map.BackGroundPos [0] = VECTOR2(Data.map.StageX, 0);
	Data.map.BackGroundPos[1] = VECTOR2(Data.map.StageX, Data.map.BackGroundPos[0].y - height +3);
	Data.map.BackGroundPos[2] = VECTOR2(Data.map.StageX, Data.map.BackGroundPos[1].y - height + 3);
	Data.map.BackGroundImgNum = 3;
	Data.map.ScrollSpeed = 100;

	//player
	Data.player.Color = COLOR(255,255,255);
	Data.player.NormalColor = COLOR(255,255,255);
	Data.player.DamageColor = COLOR(200, 100, 100);
	Data.player.Pos = VECTOR2(width / 2, height - 100);
	Data.player.CollisionOffSetY = 10;
	Data.player.LaunchVec = VECTOR2 (0, -1);
	Data.player.Hp = 100;
	Data.player.HalfSizeW = 96/2.0f;
	Data.player.HalfSizeH = 96/2.0f;
	Data.player.BcRadius = 96 / 2.0f-15;
	Data.player.Speed = 300;
	Data.player.LaunchCoolTime = 0.3f;
	Data.player.CurLaunchCoolTime = 0;
	Data.player.InvincibleTime = 0.5f;
	Data.player.InvincibleRestTime = Data.player.InvincibleTime;

	Data.playerBullet.ImgSize = 0.5f;
	Data.playerBullet.TotalNum = 1000;
	Data.playerBullet.CurNum = 0;
	Data.playerBullet.Damage = 100;
	Data.playerBullet.AdvSpeed = 300;
	Data.playerBullet.AngSpeed = 0;
	Data.playerBullet.BcRadius = 3.0f;
	Data.playerBullet.LaunchDistance = 35;

	//enemy
	Data.enemyType[0].Hp = 100;
	Data.enemyType[0].BcRadius = 25;
	Data.enemyType[0].Speed = 10;
	Data.enemyType[0].LaunchCoolTime = 0.3f;
	
	Data.enemyType[1].Hp = 300;
	Data.enemyType[1].BcRadius = 25;
	Data.enemyType[1].Speed = 10;
	Data.enemyType[1].LaunchCoolTime = 0.3f;

	Data.enemy[0].EnemyType = 0;
	Data.enemy[0].Color = COLOR(255, 255, 255);
	Data.enemy[0].NormalColor = COLOR(255, 255, 255);
	Data.enemy[0].DamageColor = COLOR(200, 100, 100);
	Data.enemy[0].CollisionOffSetY = 0;
	Data.enemy[0].Pos = VECTOR2(width / 2, 100);
	Data.enemy[0].Vec = VECTOR2(0, 0);
	Data.enemy[0].LaunchVec = VECTOR2(0, 1);
	Data.enemy[0].BcRadius = 25;
	Data.enemy[0].Hp = 100;
	Data.enemy[0].HalfSizeW = 50 / 2.0f;
	Data.enemy[0].HalfSizeH = 50 / 2.0f;
	Data.enemy[0].Speed = 10;
	Data.enemy[0].MovingTime = 0;
	Data.enemy[0].MovingCoolTime = 0;
	Data.enemy[0].CurMovingCoolTime = 0;
	Data.enemy[0].LaunchCoolTime = 0.3f;
	Data.enemy[0].CurLaunchCoolTime = 0;

	Data.enemy[1].EnemyType = 0;
	Data.enemy[1].Color = COLOR(255, 255, 255);
	Data.enemy[1].NormalColor = COLOR(255, 255, 255);
	Data.enemy[1].DamageColor = COLOR(200, 100, 100);
	Data.enemy[1].CollisionOffSetY = 0;
	Data.enemy[1].Pos = VECTOR2(width / 2+100, 100);
	Data.enemy[1].Vec = VECTOR2(0, 0);
	Data.enemy[1].LaunchVec = VECTOR2(0, 1);
	Data.enemy[1].BcRadius = 25;
	Data.enemy[1].Hp = 100;
	Data.enemy[1].HalfSizeW = 50 / 2.0f;
	Data.enemy[1].HalfSizeH = 50 / 2.0f;
	Data.enemy[1].Speed = 50;
	Data.enemy[1].MovingTime = 0;
	Data.enemy[1].MovingCoolTime = 0;
	Data.enemy[1].CurMovingCoolTime = 0;
	Data.enemy[1].LaunchCoolTime = 0.3f;
	Data.enemy[1].CurLaunchCoolTime = 0;

	Data.enemy[2].EnemyType = 1;
	Data.enemy[2].Color = COLOR(255, 255, 255);
	Data.enemy[2].NormalColor = COLOR(255, 255, 255);
	Data.enemy[2].DamageColor = COLOR(200, 100, 100);
	Data.enemy[2].CollisionOffSetY = 0;
	Data.enemy[2].Pos = VECTOR2(width / 2+200, 100);
	Data.enemy[2].Vec = VECTOR2(0, 0);
	Data.enemy[2].LaunchVec = VECTOR2(0, 1);
	Data.enemy[2].BcRadius = 25;
	Data.enemy[2].Hp = 100;
	Data.enemy[2].HalfSizeW = 50 / 2.0f;
	Data.enemy[2].HalfSizeH = 50 / 2.0f;
	Data.enemy[2].Speed = 100;
	Data.enemy[2].MovingTime = 0;
	Data.enemy[2].MovingCoolTime = 0;
	Data.enemy[2].CurMovingCoolTime = 0;
	Data.enemy[2].LaunchCoolTime = 0.3f;
	Data.enemy[2].CurLaunchCoolTime = 0;

	Data.enemyBullet.ImgSize = 0.5f;
	Data.enemyBullet.TotalNum = 50;
	Data.enemyBullet.CurNum = 0;
	Data.enemyBullet.Damage = 10;
	Data.enemyBullet.AdvSpeed = 300;
	Data.enemyBullet.AngSpeed = 0;
	Data.enemyBullet.BcRadius = 3.0f;
	Data.enemyBullet.LaunchDistance = 35;

}
void Container::Load_graphic()
{
	Data.title.TitleImg = loadImage("assets\\Title.png");
	Data.sStage.BackImg = loadImage("assets\\stageSelect_V3_b.png");
	Data.sStage.SelectIconImg = loadImage("assets\\Select_Icon_v2_a.png");
	Data.map.BackGroundStageNo1 = loadImage("assets\\loop_02.png");
	Data.player.Img = loadImage("assets\\Player3.png");
	Data.GameClearImg = loadImage("assets\\GameClear.png");
	Data.GameOverImg = loadImage("assets\\GameOver.png");
	
	Data.playerBullet.Img = loadImage("assets\\bullet_a_blue.png");
	Data.enemyBullet.Img = loadImage("assets\\bullet_a_red.png");
	Data.enemyType[0].img = loadImage("assets\\Enemy1.png");
	Data.enemyType[1].img = loadImage("assets\\Enemy2.png");
}

void Container::LoadSound()
{
	Data.CursorSound = loadSound("sounds\\CursorMove.wav");
	Data.DecisionSound= loadSound("sounds\\Decision.wav");
	Data.player.ShootSound = loadSound("sounds\\PlayerShoot.wav");
	Data.title.DecisionSound = Data.DecisionSound;
	Data.title.CursorMoveSound = Data.CursorSound;
	Data.sStage.CursorMoveSound = Data.CursorSound;
	Data.sStage.Decisionsound = Data.DecisionSound;
}
