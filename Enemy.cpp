#include "Enemy.h"
#include"Game.h"
#include"Container.h"
#include"Map.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"mathUtil.h"
#include<stdlib.h>
#include<time.h>
#include"Enemy_bullets.h"
#include"Player_bullets.h"

Enemy::Enemy(Game* game)
	:Game_object(game)
{
	
}



void Enemy::SetData(const Data& data)
{
	
	DEnemy =data;
	
}

void Enemy::Create()
{
}

void Enemy::Init(int enemyNo)
{
	srand(t);
	DEnemy.Pos.x = (GetGame()->GetMap()->GetStageX() + DEnemy.HalfSizeW * 2) + (rand() % 720 - DEnemy.HalfSizeW);
	srand(t+1000);
	DEnemy.OffSetY= (GetGame()->GetMap()->GetStageY())/Game::Enemy_num;
	DEnemy.Pos.y =DEnemy.InitPosY;
	
	
}

void Enemy::Update()
{
	if (GetGame()->GetMap()->GetWorldY() < -DEnemy.OffSetY*EnemyNo) {
		Move();
	}
	
	if (DEnemy.Pos.y >= 0) {
		Launch();
		Collision();
	}
}

void Enemy::Move()
{

	DEnemy.Pos.y += DEnemy.Speed * delta;
		
	
	
	if (DEnemy.Pos.x - DEnemy.HalfSizeW <= GetGame()->GetMap()->GetStageX()) {
		DEnemy.Pos.x = 600 + DEnemy.HalfSizeW;
		DEnemy.Vec.x = 1;
	}
	if (DEnemy.Pos.x + DEnemy.HalfSizeW >= (width - GetGame()->GetMap()->GetStageX())) {
		DEnemy.Pos.x = 1320 - DEnemy.HalfSizeW;
		DEnemy.Vec.x = 0;
	}
	
	
	
	
}

void Enemy::RandomMove()
{
		srand((unsigned int)time(NULL));
		DEnemy.Vec.x = rand() % 2;// 1:right 0:left
		DEnemy.Vec.y = rand() % 2;// 1::down 0:up

		//x moving
		if (DEnemy.Vec.x == 1 && DEnemy.Pos.x + DEnemy.HalfSizeW < (width - GetGame()->GetMap()->GetStageX())) {
			DEnemy.Pos.x += DEnemy.Speed * delta;
		}
		else if (DEnemy.Vec.x == 0 && DEnemy.Pos.x - DEnemy.HalfSizeW > GetGame()->GetMap()->GetStageX()) {
			DEnemy.Pos.x -= DEnemy.Speed * delta;
		}

		//y moving
		if (DEnemy.Vec.y == 1 && DEnemy.Pos.y + DEnemy.HalfSizeH < (height / 2)) {
			DEnemy.Pos.y += DEnemy.Speed * delta;
		}
		else if (DEnemy.Vec.y == 0 && DEnemy.Pos.y - DEnemy.HalfSizeH > 0) {
			DEnemy.Pos.y -= DEnemy.Speed * delta;
		}

}

void Enemy::Launch()
{
	DEnemy.CurLaunchCoolTime += delta;
	if (DEnemy.CurLaunchCoolTime >= DEnemy.LaunchCoolTime) {
		VECTOR2 playerPos = GetGame()->GetPlayer()->GetPos();
		DEnemy.LaunchVec = normalize(VECTOR2(playerPos.x - DEnemy.Pos.x, playerPos.y - DEnemy.Pos.y));

		GetGame()->GetEBullets(DEnemy.EnemyType)->Launch(DEnemy.Pos, DEnemy.LaunchVec);
		DEnemy.CurLaunchCoolTime = 0;

	}
}

void Enemy::Collision()
{
	
	//collision distance
	Bullets* bullets = GetGame()->GetPBullets();
	float distance = DEnemy.BcRadius + bullets->GetBcRadius();
	float sqDistance = distance * distance;
	//enemy collision
	int curNum = bullets->GetCurNum();
	DEnemy.Color = DEnemy.NormalColor;
	for (int j = curNum - 1; j >= 0; j--) {
		VECTOR2 enemyPos = DEnemy.Pos;
		enemyPos.y -= DEnemy.CollisionOffSetY;
		VECTOR2 vec = enemyPos - bullets->GetPos(j);
		if (vec.sqMag() < sqDistance) {
			DEnemy.Hp -= bullets->GetDamage();
			DEnemy.Color = DEnemy.DamageColor;

			bullets->Kill(j);
			j = 0;
		}
	}
}

void Enemy::Draw()
{
	rectMode(CENTER);
	angleMode(DEGREES);
	image(DEnemy.img, DEnemy.Pos.x, DEnemy.Pos.y, DEnemy.angle);
	fill(DEnemy.Color.r, DEnemy.Color.g, DEnemy.Color.b, 125);
	circle(DEnemy.Pos.x, DEnemy.Pos.y+DEnemy.CollisionOffSetY, DEnemy.BcRadius * 2);
	//print(DEnemy.Hp);
	//print(DEnemy.Pos.y);
}

void Enemy::SaveData()
{
	CheckError = true;
	DPauseGame = DEnemy;
}

void Enemy::SetData()
{
	if (CheckError == true) {
		DEnemy = DPauseGame;
		CheckError = false;
	}
	else {
		print("ERROR");
	}
}





