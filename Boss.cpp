#include "Boss.h"
#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"mathUtil.h"
#include<stdlib.h>
#include<time.h>
//#include"Boss_bullets.h"
#include"Player_bullets.h"
void Boss::Create()
{
	DBoss = GetGame()->GetContainer()->GetData().boss;
	//GetGame()->GetEBullets()->Create();
}

void Boss::Init()
{
	const Data& dBoss = GetGame()->GetContainer()->GetData().boss;
	DBoss.Pos = dBoss.Pos;
	DBoss.Hp = dBoss.Hp;
}

void Boss::Update()
{
	
	Move();
	Launch();
	Collision();
}

void Boss::Move()
{
	RandomMove();

		if (DBoss.Pos.x - DBoss.BcRadius <= GetGame()->GetMap()->GetStageX()) {
			DBoss.Pos.x = 600 + DBoss.BcRadius;
			DBoss.Vec.x = 1;
		}
		if (DBoss.Pos.x + DBoss.BcRadius >= (width - GetGame()->GetMap()->GetStageX())) {
			DBoss.Pos.x = 1320 - DBoss.BcRadius;
			DBoss.Vec.x = 0;
		}
		if (DBoss.Pos.y + DBoss.BcRadius >= height) {
			DBoss.Pos.y = height / 2;
			DBoss.Vec.y = 0;
		}
		if (DBoss.Pos.y - DBoss.BcRadius<= 0) {
			DBoss.Pos.y = DBoss.BcRadius;
			DBoss.Vec.y = 1;
		}
	
	

}

void Boss::RandomMove()
{
	srand((unsigned int)time(NULL));
	DBoss.Vec.x = rand() % 2;// 1:right 0:left
	DBoss.Vec.y = rand() % 2;// 1::down 0:up

	DBoss.Speed = 50 + rand() % 100;

	//x moving
	if (DBoss.Vec.x == 1 && DBoss.Pos.x + DBoss.BcRadius < (width - GetGame()->GetMap()->GetStageX())) {
		DBoss.Pos.x += DBoss.Speed * delta;
	}
	else if (DBoss.Vec.x == 0 && DBoss.Pos.x - DBoss.BcRadius > GetGame()->GetMap()->GetStageX()) {
		DBoss.Pos.x -= DBoss.Speed * delta;
	}

	//y moving
	if (DBoss.Vec.y == 1 && DBoss.Pos.y + DBoss.BcRadius < (height / 2)) {
		DBoss.Pos.y += DBoss.Speed * delta;
	}
	else if (DBoss.Vec.y == 0 && DBoss.Pos.y - DBoss.BcRadius> 0) {
		DBoss.Pos.y -= DBoss.Speed * delta;
	}
 }








void Boss::Launch()
{
	DBoss.CurLaunchCoolTime += delta;
	if (DBoss.CurLaunchCoolTime >= DBoss.LaunchCoolTime) {
		VECTOR2 playerPos = GetGame()->GetPlayer()->GetPos();
		DBoss.LaunchVec = normalize(VECTOR2(playerPos.x - DBoss.Pos.x, playerPos.y - DBoss.Pos.y));

		//GetGame()->GetEBullets()->Launch(DBoss.Pos, DBoss.LaunchVec);
		DBoss.CurLaunchCoolTime = 0;

	}
}

void Boss::Collision()
{
	//collision distance
	Bullets* bullets = GetGame()->GetPBullets();
	float distance = DBoss.BcRadius + bullets->GetBcRadius();
	float sqDistance = distance * distance;
	//Boss collision
	int curNum = bullets->GetCurNum();
	DBoss.Color = DBoss.NormalColor;
	for (int j = curNum - 1; j >= 0; j--) {
		VECTOR2 BossPos = DBoss.Pos;
		BossPos.y -= DBoss.CollisionOffSetY;
		VECTOR2 vec = BossPos - bullets->GetPos(j);
		if (vec.sqMag() < sqDistance) {
			DBoss.Hp -= bullets->GetDamage();
			DBoss.Color = DBoss.DamageColor;

			bullets->Kill(j);
			j = 0;
		}
	}

}

void Boss::Draw()
{
	rectMode(CENTER);
	angleMode(DEGREES);
	image(DBoss.img, DBoss.Pos.x, DBoss.Pos.y, DBoss.angle);
	fill(DBoss.Color.r, DBoss.Color.g, DBoss.Color.b, 125);
	circle(DBoss.Pos.x, DBoss.Pos.y, DBoss.BcRadius * 2);
	print(DBoss.Hp);

}

void Boss::SaveData()
{
	CheckError = true;
	DPauseGame = DBoss;
	
}

void Boss::SetData()
{
	if (CheckError == true) {
		DBoss = DPauseGame;
		CheckError = false;
	}
	else {
		print("ERROR");
	}
		
	
}


