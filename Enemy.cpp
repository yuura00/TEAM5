#include "Enemy.h"
#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include<stdlib.h>
#include<time.h>

Enemy::Enemy(Game* game)
	:Game_object(game)
{

}

Enemy::~Enemy()
{
}
void Enemy::Create()
{
	DEnemy = GetGame()->GetContainer()->GetData().enemy;
	//GetGame()->GetPBullets()->Create();
}

void Enemy::Init()
{
	const Data& dEnemy = GetGame()->GetContainer()->GetData().enemy;
	DEnemy.Pos = dEnemy.Pos;
	DEnemy.Hp = dEnemy.Hp;

}

void Enemy::Update()
{

	Move();
	Launch();
	Collision();
}

void Enemy::Move()
{
	
	
	RandomMove();
		
	if (DEnemy.Pos.x - DEnemy.HalfSizeW <= 600) {
		DEnemy.Pos.x = 600 + DEnemy.HalfSizeW;
		DEnemy.Vec.x = 1;
	}
	if (DEnemy.Pos.x + DEnemy.HalfSizeW >= 1320) {
		DEnemy.Pos.x = 1320 - DEnemy.HalfSizeW;
		DEnemy.Vec.x = 0;
	}
	if (DEnemy.Pos.y + DEnemy.HalfSizeH >= height) {
		DEnemy.Pos.y = height / 2;
		DEnemy.Vec.y = 0;
	}
	if (DEnemy.Pos.y - DEnemy.HalfSizeH <= 0) {
		DEnemy.Pos.y = DEnemy.HalfSizeH;
		DEnemy.Vec.y = 1;
	}
}

void Enemy::RandomMove()
{
	srand((unsigned int)time(NULL));
	DEnemy.Vec.x = rand() % 2;// 1:right 0:left
	DEnemy.Vec.y = rand() % 2;// 1::down 0:up
	//DEnemy.MovingTime = rand() / (float)RAND_MAX;
	DEnemy.Speed = 200 + rand() % 100;
	
	//x moving
	if (DEnemy.Vec.x == 1 && DEnemy.Pos.x + DEnemy.HalfSizeW < width - 600) {
		DEnemy.Pos.x += DEnemy.Speed * delta;
	}
	else if (DEnemy.Vec.x == 0 && DEnemy.Pos.x - DEnemy.HalfSizeW > 600) {
		DEnemy.Pos.x -= DEnemy.Speed * delta;
	}

	//y moving
	if (DEnemy.Vec.y == 1 && DEnemy.Pos.y + DEnemy.HalfSizeH < height / 2) {
		DEnemy.Pos.y += DEnemy.Speed * delta;
	}
	else if (DEnemy.Vec.y == 0 && DEnemy.Pos.y - DEnemy.HalfSizeH > 0) {
		DEnemy.Pos.y -= DEnemy.Speed * delta;
	}

	
	
		
		

	
	
}

void Enemy::Launch()
{

	if (isPress(KEY_SPACE)) {
		DEnemy.CurLaunchCoolTime += delta;
		if (DEnemy.CurLaunchCoolTime > DEnemy.LaunchCoolTime) {
			//GetGame()->GetPBullets()->Launch(DEnemy.Pos, DEnemy.Vec);
			DEnemy.CurLaunchCoolTime = 0;
		}
	}
	else {
		DEnemy.CurLaunchCoolTime = DEnemy.LaunchCoolTime;
	}
}

void Enemy::Collision()
{
}

void Enemy::Draw()
{
	rectMode(CENTER);
	fill(255,0,0);
	rect(DEnemy.Pos.x, DEnemy.Pos.y, DEnemy.HalfSizeW, DEnemy.HalfSizeH);
	//image(DEnemy.img, DEnemy.Pos.x, DEnemy.Pos.y);

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

