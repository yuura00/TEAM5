#include "Enemy.h"
#include"Game.h"
#include"Container.h"
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

Enemy::~Enemy()
{
}
void Enemy::SetEnemyData(const Data& data)
{

}
void Enemy::Create()
{
	for (int i = 0; i < Game::Etype_num; i++) {
		TData[i] = GetGame()->GetContainer()->GetData().enemyType[i];
	}
	for (int i = 0; i < Game::Enemy_num; i++) {
		DEnemy[i] = GetGame()->GetContainer()->GetData().enemy[i];
		DEnemy[i].img = TData[DEnemy[i].EnemyType].img;
		DEnemy[i].Hp = TData[DEnemy[i].EnemyType].Hp;
		DEnemy[i].Speed = TData[DEnemy[i].EnemyType].Speed;
		DEnemy[i].LaunchCoolTime = TData[DEnemy[i].EnemyType].LaunchCoolTime;
		DEnemy[i].BcRadius = TData[DEnemy[i].EnemyType].BcRadius;
	}
	
	GetGame()->GetEBullets()->Create();
}

void Enemy::Init()
{
	for (int i = 0; i < Game::Enemy_num; i++) {
		const Data& dEnemy = GetGame()->GetContainer()->GetData().enemy[i];
		DEnemy[i].Pos = dEnemy.Pos;
		DEnemy[i].Hp = dEnemy.Hp;
	}
	KillCnt = 0;

}

void Enemy::Update()
{
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		if (DEnemy[i].Hp <= 0) {
			Kill(i);
		}
	}
	Move();
	Launch();
	Collision();
}

void Enemy::Move()
{
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		RandomMove();

		if (DEnemy[i].Pos.x - DEnemy[i].HalfSizeW <= GetGame()->GetMap()->GetStageX()) {
			DEnemy[i].Pos.x = 600 + DEnemy[i].HalfSizeW;
			DEnemy[i].Vec.x = 1;
		}
		if (DEnemy[i].Pos.x + DEnemy[i].HalfSizeW >= (width- GetGame()->GetMap()->GetStageX())) {
			DEnemy[i].Pos.x = 1320 - DEnemy[i].HalfSizeW;
			DEnemy[i].Vec.x = 0;
		}
		if (DEnemy[i].Pos.y + DEnemy[i].HalfSizeH >= height) {
			DEnemy[i].Pos.y = height / 2;
			DEnemy[i].Vec.y = 0;
		}
		if (DEnemy[i].Pos.y - DEnemy[i].HalfSizeH <= 0) {
			DEnemy[i].Pos.y = DEnemy[i].HalfSizeH;
			DEnemy[i].Vec.y = 1;
		}
	}
	
}

void Enemy::RandomMove()
{
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		srand((unsigned int)time(NULL)+1000*i);
		DEnemy[i].Vec.x = rand() % 2;// 1:right 0:left
		DEnemy[i].Vec.y = rand() % 2;// 1::down 0:up

		DEnemy[i].Speed =50+rand() % 100;

		//x moving
		if (DEnemy[i].Vec.x == 1 && DEnemy[i].Pos.x + DEnemy[i].HalfSizeW < (width - GetGame()->GetMap()->GetStageX())) {
			DEnemy[i].Pos.x += DEnemy[i].Speed * delta;
		}
		else if (DEnemy[i].Vec.x == 0 && DEnemy[i].Pos.x - DEnemy[i].HalfSizeW > GetGame()->GetMap()->GetStageX()) {
			DEnemy[i].Pos.x -= DEnemy[i].Speed * delta;
		}

		//y moving
		if (DEnemy[i].Vec.y == 1 && DEnemy[i].Pos.y + DEnemy[i].HalfSizeH < (height / 2)) {
			DEnemy[i].Pos.y += DEnemy[i].Speed * delta;
		}
		else if (DEnemy[i].Vec.y == 0 && DEnemy[i].Pos.y - DEnemy[i].HalfSizeH > 0) {
			DEnemy[i].Pos.y -= DEnemy[i].Speed * delta;
		}

	}
	
		
		

	
	
}

void Enemy::Launch()
{
	
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {

		DEnemy[i].CurLaunchCoolTime += delta;
		if (DEnemy[i].CurLaunchCoolTime >= DEnemy[i].LaunchCoolTime) {
			VECTOR2 playerPos = GetGame()->GetPlayer()->GetPos();
			DEnemy[i].LaunchVec= normalize(VECTOR2(playerPos.x - DEnemy[i].Pos.x, playerPos.y - DEnemy[i].Pos.y));

 			GetGame()->GetEBullets()->Launch(DEnemy[i].Pos, DEnemy[i].LaunchVec);
			DEnemy[i].CurLaunchCoolTime = 0;

		}
	}
}

void Enemy::Collision()
{
	
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		//collision distance
		Bullets* bullets = GetGame()->GetPBullets();
		float distance = DEnemy[i].BcRadius + bullets->GetBcRadius();
		float sqDistance = distance * distance;
		//enemy collision
		int curNum = bullets->GetCurNum();
		DEnemy[i].Color = DEnemy[i].NormalColor;
		for (int j = curNum - 1; j >= 0; j--) {
			VECTOR2 enemyPos = DEnemy[i].Pos;
			enemyPos.y -= DEnemy[i].CollisionOffSetY;
			VECTOR2 vec = enemyPos - bullets->GetPos(j);
			if (vec.sqMag() < sqDistance) {
				DEnemy[i].Hp -= bullets->GetDamage();
				DEnemy[i].Color = DEnemy[i].DamageColor;

				bullets->Kill(j);
				j = 0;
			}
		}
	}
	
	

}

void Enemy::Draw()
{
	
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		rectMode(CENTER);
		angleMode(DEGREES);
		image(DEnemy[i].img, DEnemy[i].Pos.x, DEnemy[i].Pos.y,DEnemy[i].angle);
		fill(DEnemy[i].Color.r, DEnemy[i].Color.g, DEnemy[i].Color.b,125);
		circle(DEnemy[i].Pos.x, DEnemy[i].Pos.y, DEnemy[i].BcRadius*2);
		print(DEnemy[i].Hp);
		print(KillCnt);
	}
	
}

void Enemy::SaveData()
{
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		CheckError = true;
		DPauseGame[i] = DEnemy[i];
	}
}

void Enemy::SetData()
{
	for (int i = 0; i < Game::Enemy_num-KillCnt; i++) {
		if (CheckError == true) {
			DEnemy[i] = DPauseGame[i];
			CheckError = false;
		}
		else {
			print("ERROR");
		}
	}
}

void Enemy::Kill(int no)
{
	if (no == Game::Enemy_num-1) {
		KillCnt++;
	}
	
	else {
		for (int i = no; i < Game::Enemy_num - (1+KillCnt); i++) {
			DEnemy[i] = DEnemy[i + 1];
			
		}
		KillCnt++;
	}
	
	
}

