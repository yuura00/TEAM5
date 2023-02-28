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
	Data.title.sw[0][1] = 1;//replay
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

	//select character
	Data.sCharacter.SelectIconPos = VECTOR2(0, 69);
	Data.sCharacter.SelectSw = 0;
	Data.sCharacter.OffsetX = 0;
	Data.sCharacter.OffsetW = 640;
	Data.sCharacter.CharacterNum = 3;

	//select machine
	Data.sMachine.SelectIconPos = VECTOR2(0, 69);
	Data.sMachine.SelectSw = 0;
	Data.sMachine.OffsetX = 0;
	Data.sMachine.OffsetW = 640;
	Data.sMachine.machineNum = 3;

	//map
	Data.map.StageX = 600;
	Data.map.StageY = 6000;
	Data.map.BackGroundPos [0] = VECTOR2(Data.map.StageX, 0);
	Data.map.BackGroundPos[1] = VECTOR2(Data.map.StageX, Data.map.BackGroundPos[0].y - height +3);
	Data.map.BackGroundPos[2] = VECTOR2(Data.map.StageX, Data.map.BackGroundPos[1].y - height + 3);
	Data.map.BackGroundImgNum = 3;
	Data.map.ScrollSpeed = 100;
	Data.map.BossFazeY = -6000;
	Data.map.WorldY = 0;
	Data.map.BossFlag = false;
	Data.map.battleW = 720;

	//player
	Data.player[0].Color = COLOR(255, 255, 255);
	Data.player[0].NormalColor = COLOR(255,255,255);
	Data.player[0].DamageColor = COLOR(200, 100, 100);
	Data.player[0].Pos = VECTOR2(width / 2, height - 100);
	Data.player[0].CollisionOffSetY = 0;
	Data.player[0].LaunchVec = VECTOR2 (0, -1);
	Data.player[0].Hp = 500;
	Data.player[0].Speed = 200;
	Data.player[0].Damage = 150;
	Data.player[0].HalfSizeW = 96/2.0f;
	Data.player[0].HalfSizeH = 96/2.0f;
	Data.player[0].BcRadius = 96 / 2.0f-10;
	Data.player[0].LaunchCoolTime = 0.45f;
	Data.player[0].CurLaunchCoolTime = 0;
	Data.player[0].TriggerCooltime = 0;
	Data.player[0].InitTriggerCoolTime = Data.player[0].LaunchCoolTime;
	Data.player[0].InvincibleTime = 0.5f;
	Data.player[0].InvincibleRestTime = Data.player[0].InvincibleTime;
	Data.player[0].UltPoint = 0;
	Data.player[0].UltChargeSp = 1.0f;
	Data.player[0].MaxUltPoint = 100;
	Data.player[0].CurUltDeltaTime = 0;

	Data.player[1].Color = COLOR(255, 255, 255);
	Data.player[1].NormalColor = COLOR(255, 255, 255);
	Data.player[1].DamageColor = COLOR(200, 100, 100);
	Data.player[1].Pos = VECTOR2(width / 2, height - 100);
	Data.player[1].CollisionOffSetY = 5;
	Data.player[1].LaunchVec = VECTOR2(0, -1);
	Data.player[1].Hp = 300;
	Data.player[1].Speed = 300;
	Data.player[1].Damage = 100;
	Data.player[1].HalfSizeW = 96 / 2.0f;
	Data.player[1].HalfSizeH = 96 / 2.0f;
	Data.player[1].BcRadius = 96 / 2.0f-5;
	Data.player[1].LaunchCoolTime = 0.35f;
	Data.player[1].CurLaunchCoolTime = 0;
	Data.player[1].TriggerCooltime = 0;
	Data.player[1].InitTriggerCoolTime = Data.player[1].LaunchCoolTime;
	Data.player[1].InvincibleTime = 0.5f;
	Data.player[1].InvincibleRestTime = Data.player[1].InvincibleTime;
	Data.player[1].UltPoint = 0;
	Data.player[1].UltChargeSp = 1.0f;
	Data.player[1].MaxUltPoint = 100;
	Data.player[1].CurUltDeltaTime = 0;

	Data.player[2].Color = COLOR(255, 255, 255);
	Data.player[2].NormalColor = COLOR(255, 255, 255);
	Data.player[2].DamageColor = COLOR(200, 100, 100);
	Data.player[2].Pos = VECTOR2(width / 2, height - 100);
	Data.player[2].CollisionOffSetY = 12;
	Data.player[2].LaunchVec = VECTOR2(0, -1);
	Data.player[2].Hp = 100;
	Data.player[2].Speed = 450;
	Data.player[2].Damage = 50;
	Data.player[2].HalfSizeW = 96 / 2.0f;
	Data.player[2].HalfSizeH = 96 / 2.0f;
	Data.player[2].BcRadius = 96 / 2.0f - 10;
	Data.player[2].TriggerCooltime = 0;
	Data.player[2].LaunchCoolTime = 0.2f;
	Data.player[2].CurLaunchCoolTime = 0;
	Data.player[2].InitTriggerCoolTime = Data.player[2].LaunchCoolTime;
	Data.player[2].InvincibleTime = 0.5f;
	Data.player[2].InvincibleRestTime = Data.player[2].InvincibleTime;
	Data.player[2].UltPoint = 0;
	Data.player[2].UltChargeSp = 1.0f;
	Data.player[2].MaxUltPoint = 100;
	Data.player[2].CurUltDeltaTime = 0;

	Data.playerBullet.ImgSize = 0.5f;
	Data.playerBullet.TotalNum = 100;
	Data.playerBullet.CurNum = 0;
	Data.playerBullet.Damage = 100;
	Data.playerBullet.AdvSpeed = 400;
	Data.playerBullet.AngSpeed = 0;
	Data.playerBullet.BcRadius = 3.0f;
	Data.playerBullet.LaunchDistance = 35;

	//chara
	//khael
	Data.chara[0].Hp = 20; 
	Data.chara[0].Speed = 20; 
	Data.chara[0].Damage = 50;
	Data.chara[0].UltTime = 10.0f;
	//beryl
	Data.chara[1].Hp = 200;
	Data.chara[1].Speed = 0;
	Data.chara[1].Damage = 20;
	//harp
	Data.chara[2].Hp = 70;
	Data.chara[2].Speed = 70;
	Data.chara[2].Damage = 20;

	//enemy
	Data.enemy[0].EnemyType = 0;
	Data.enemy[0].Color = COLOR(255, 255, 255);
	Data.enemy[0].NormalColor = COLOR(255, 255, 255);
	Data.enemy[0].DamageColor = COLOR(200, 100, 100);
	Data.enemy[0].CollisionOffSetY = -10;
	Data.enemy[0].Pos = VECTOR2(640, -300);
	Data.enemy[0].InitPosY = -300;
	Data.enemy[0].Vec = VECTOR2(0, 0);
	Data.enemy[0].LaunchVec = VECTOR2(0, 1);
	Data.enemy[0].BcRadius = 35;
	Data.enemy[0].Hp = 350;
	Data.enemy[0].HalfSizeW = 50 / 2.0f;
	Data.enemy[0].HalfSizeH = 50 / 2.0f;
	Data.enemy[0].Speed = 200;
	Data.enemy[0].MovingTime = 0;
	Data.enemy[0].MovingCoolTime = 0;
	Data.enemy[0].CurMovingCoolTime = 0;
	Data.enemy[0].LaunchCoolTime = 0.5f;
	Data.enemy[0].CurLaunchCoolTime = 0;

	Data.enemy[1].EnemyType = 1;
	Data.enemy[1].Color = COLOR(255, 255, 255);
	Data.enemy[1].NormalColor = COLOR(255, 255, 255);
	Data.enemy[1].DamageColor = COLOR(200, 100, 100);
	Data.enemy[1].CollisionOffSetY = -20;
	Data.enemy[1].Pos = VECTOR2(width / 2, -300);
	Data.enemy[1].InitPosY = -300;
	Data.enemy[1].Vec = VECTOR2(0, 0);
	Data.enemy[1].LaunchVec = VECTOR2(0, 1);
	Data.enemy[1].BcRadius = 45;
	Data.enemy[1].Hp = 150;
	Data.enemy[1].HalfSizeW = 50 / 2.0f;
	Data.enemy[1].HalfSizeH = 50 / 2.0f;
	Data.enemy[1].Speed = 300;
	Data.enemy[1].MovingTime = 0;
	Data.enemy[1].MovingCoolTime = 2.0f;
	Data.enemy[1].CurMovingCoolTime = 0;
	Data.enemy[1].LaunchCoolTime = 0.3f;
	Data.enemy[1].CurLaunchCoolTime = 0;


	/*Data.enemy[2].Color = COLOR(255, 255, 255);
	Data.enemy[2].NormalColor = COLOR(255, 255, 255);
	Data.enemy[2].DamageColor = COLOR(200, 100, 100);
	Data.enemy[2].CollisionOffSetY = 0;
	Data.enemy[2].Pos = VECTOR2(width / 2+200, 100);
	Data.enemy[2].Vec = VECTOR2(0, 0);
	Data.enemy[2].LaunchVec = VECTOR2(0, 1);
	Data.enemy[2].BcRadius = 25;
	Data.enemy[2].Hp = 300;
	Data.enemy[2].HalfSizeW = 50 / 2.0f;
	Data.enemy[2].HalfSizeH = 50 / 2.0f;
	Data.enemy[2].Speed = 100;
	Data.enemy[2].MovingTime = 0;
	Data.enemy[2].MovingCoolTime = 0;
	Data.enemy[2].CurMovingCoolTime = 0;
	Data.enemy[2].LaunchCoolTime = 0.01f;
	Data.enemy[2].CurLaunchCoolTime = 0;
	*/

	Data.enemyBullet[0].EnemyNum = 0;
	Data.enemyBullet[0].ImgSize = 0.5f;
	Data.enemyBullet[0].TotalNum = 10;
	Data.enemyBullet[0].CurNum = 0;
	Data.enemyBullet[0].Damage = 20;
	Data.enemyBullet[0].AdvSpeed = 400;
	Data.enemyBullet[0].AngSpeed = 0;
	Data.enemyBullet[0].BcRadius = 3.0f;
	Data.enemyBullet[0].LaunchDistance = 35;

	Data.enemyBullet[1].EnemyNum = 1;
	Data.enemyBullet[1].ImgSize = 0.5f;
	Data.enemyBullet[1].TotalNum = 5;
	Data.enemyBullet[1].CurNum = 0;
	Data.enemyBullet[1].Damage = 10;
	Data.enemyBullet[1].AdvSpeed = 600;
	Data.enemyBullet[1].AngSpeed = 0;
	Data.enemyBullet[1].BcRadius = 3.0f;
	Data.enemyBullet[1].LaunchDistance = 35;

	//boss
	Data.boss.angle = 0;
	Data.boss.Color = COLOR(255, 255, 255);
	Data.boss.NormalColor = COLOR(255, 255, 255);
	Data.boss.DamageColor = COLOR(200, 100, 100);
	Data.boss.CollisionOffSetY = 0;
	Data.boss.Pos = VECTOR2(width / 2, -6000);
	Data.boss.Vec = VECTOR2(0, 0);
	Data.boss.LaunchVec = VECTOR2(0, 1);
	Data.boss.BcRadius = 192/2.0f;
	Data.boss.Hp = 5000;
	Data.boss.Speed = 50;
	Data.boss.MovingTime = 0;
	Data.boss.MovingCoolTime = 0;
	Data.boss.CurMovingCoolTime = 0;
	Data.boss.LaunchCoolTime = 0.2f;
	Data.boss.CurLaunchCoolTime = 0;

	Data.bossBullets.ImgSize = 1.0f;
	Data.bossBullets.TotalNum = 3;
	Data.bossBullets.CurNum = 0;
	Data.bossBullets.Damage =100;
	Data.bossBullets.AdvSpeed = 150;
	Data.bossBullets.AngSpeed = 0;
	Data.bossBullets.BcRadius = 36.0f;
	Data.bossBullets.LaunchDistance = 35;
}
void Container::Load_graphic()
{
	Data.title.TitleImg = loadImage("assets\\Title.png");
	Data.sStage.BackImg = loadImage("assets\\stageSelect_V3_b.png");
	Data.sStage.SelectIconImg = loadImage("assets\\Select_Icon_v2_a.png");
	Data.map.BackGroundStageNo3 = loadImage("assets\\loop_02.png");
	Data.map.SideImg = loadImage("assets\\UI_v2_a.png");
	Data.player[0].Img = loadImage("assets\\Player1.png");
	Data.player[1].Img = loadImage("assets\\Player2.png");
	Data.player[2].Img = loadImage("assets\\Player3.png");
	Data.player[0].UltImg = loadImage("assets\\ult_effect_01.png");
	Data.player[1].UltImg = Data.player[0].UltImg;
	Data.player[2].UltImg = Data.player[0].UltImg;
	Data.GameClearImg = loadImage("assets\\GameClear.png");
	Data.GameOverImg = loadImage("assets\\GameOver.png");
	
	Data.playerBullet.Img = loadImage("assets\\bullet_a_blue.png");
	Data.enemyBullet[0].Img = loadImage("assets\\bullet_a_red.png");
	Data.enemyBullet[1].Img= loadImage("assets\\bullet_b_yellow.png");
	Data.enemy[0].img = loadImage("assets\\Enemy1.png");
	Data.enemy[1].img = loadImage("assets\\Enemy2.png");
	//Data.enemy[2].img = loadImage("assets\\Enemy3.png");
	Data.sCharacter.GraphicImg = loadImage("assets\\CharacterSelect_V1.png");
	Data.sCharacter.SelectIconImg = Data.sStage.SelectIconImg;
	Data.sMachine.GraphicImg = loadImage("assets\\fighter_Select_v1.png");
	Data.sMachine.SelectIconImg= Data.sStage.SelectIconImg;
	Data.boss.img = loadImage("assets\\boss_01.png");
	Data.bossBullets.Img = loadImage("assets\\boss_bullet_a.png");
}

void Container::LoadSound()
{
	Data.CursorSound = loadSound("sounds\\CursorMove.wav");
	Data.DecisionSound= loadSound("sounds\\Decision.wav");
	Data.player[0].ShootSound = loadSound("sounds\\PlayerShoot.wav");
	Data.title.DecisionSound = Data.DecisionSound;
	Data.title.CursorMoveSound = Data.CursorSound;
	Data.sStage.CursorMoveSound = Data.CursorSound;
	Data.sStage.Decisionsound = Data.DecisionSound;
	Data.sCharacter.CursorMoveSound = Data.CursorSound;
	Data.sCharacter.DecisionSound = Data.DecisionSound;
	Data.sMachine.CursorMoveSound= Data.CursorSound;
	Data.sMachine.DecisionSound = Data.DecisionSound;
}
