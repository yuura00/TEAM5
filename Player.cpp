#include "Player.h"
#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Player_bullets.h"
Player::Player(Game* game)
	:Game_object(game)
{

}

Player::~Player()
{
}
void Player::Create()
{
	DPlayer = GetGame()->GetContainer()->GetData().player;
	GetGame()->GetPBullets()->Create();
}

void Player::Init()
{
	const Data& dplayer = GetGame()->GetContainer()->GetData().player;
	DPlayer.Pos =dplayer.Pos;
	DPlayer.Hp = dplayer.Hp;
	
}

void Player::Update()
{
	
	Move();
	Launch();
	Collision();
}

void Player::Move()
{
	if (isPress(KEY_A) && DPlayer.Pos.x - DPlayer.HalfSizeW > 600) {
		DPlayer.Pos.x -= DPlayer.Speed*delta;
	}
	if (isPress(KEY_D) && DPlayer.Pos.x + DPlayer.HalfSizeW < 1320) {
		DPlayer.Pos.x += DPlayer.Speed*delta;
	}
	if (isPress(KEY_S) && DPlayer.Pos.y + DPlayer.HalfSizeH < height) {
		DPlayer.Pos.y += DPlayer.Speed*delta;
	}
	if (isPress(KEY_W) && DPlayer.Pos.y - DPlayer.HalfSizeH > 0) {
		DPlayer.Pos.y -= DPlayer.Speed*delta;
	}
	if (DPlayer.Pos.x - DPlayer.HalfSizeW < 600)DPlayer.Pos.x = 600 + DPlayer.HalfSizeW;
	if(DPlayer.Pos.x + DPlayer.HalfSizeW > 1320)DPlayer.Pos.x = 1320 - DPlayer.HalfSizeW;
	if (DPlayer.Pos.y + DPlayer.HalfSizeH > height)DPlayer.Pos.y = height - DPlayer.HalfSizeH;
	if (DPlayer.Pos.y - DPlayer.HalfSizeH < 0)DPlayer.Pos.y = DPlayer.HalfSizeH;

}

void Player::Launch()
{

	if (isPress(KEY_SPACE)) {
		DPlayer.CurLaunchCoolTime += delta;
		if (DPlayer.CurLaunchCoolTime > DPlayer.LaunchCoolTime) {
			GetGame()->GetPBullets()->Launch(DPlayer.Pos, DPlayer.LaunchVec);
			DPlayer.CurLaunchCoolTime = 0;
		}
	}
	else {
		DPlayer.CurLaunchCoolTime = DPlayer.LaunchCoolTime;
	}
}

void Player::Collision()
{
}

void Player::Draw()
{
	rectMode(CENTER);
	fill(255);
	
	image(DPlayer.img,DPlayer.Pos.x, DPlayer.Pos.y);
	fill(125, 125, 125, 100);
	rect(DPlayer.Pos.x, DPlayer.Pos.y, 90,60);
}

void Player::SaveData()
{
	CheckError = true;
	DPauseGame = DPlayer;
}

void Player::SetData()
{
	if (CheckError == true) {
		DPlayer = DPauseGame;
		CheckError = false;
	}
	else {
		print("ERROR");
	}
}

