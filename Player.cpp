#include "Player.h"
#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Player_bullets.h"
#include"Enemy_bullets.h"
#include"sound.h"
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
	DPlayer.UltPoint += delta;
}

void Player::Move()
{
	if (isPress(KEY_A) && DPlayer.Pos.x - DPlayer.HalfSizeW > GetGame()->GetMap()->GetStageX()) {
		DPlayer.Pos.x -= DPlayer.Speed*delta;
	}
	if (isPress(KEY_D) && DPlayer.Pos.x + DPlayer.HalfSizeW < (width- GetGame()->GetMap()->GetStageX())) {
		DPlayer.Pos.x += DPlayer.Speed*delta;
	}
	if (isPress(KEY_S) && DPlayer.Pos.y + DPlayer.HalfSizeH < height) {
		DPlayer.Pos.y += DPlayer.Speed*delta;
	}
	if (isPress(KEY_W) && DPlayer.Pos.y - DPlayer.HalfSizeH > 0) {
		DPlayer.Pos.y -= DPlayer.Speed*delta;
	}
	if (DPlayer.Pos.x - DPlayer.HalfSizeW < GetGame()->GetMap()->GetStageX())DPlayer.Pos.x = GetGame()->GetMap()->GetStageX() + DPlayer.HalfSizeW;
	if(DPlayer.Pos.x + DPlayer.HalfSizeW > (width- GetGame()->GetMap()->GetStageX()))DPlayer.Pos.x = (width- GetGame()->GetMap()->GetStageX()) - DPlayer.HalfSizeW;
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
			playSound(DPlayer.ShootSound);
		}
	}
	else {
		DPlayer.CurLaunchCoolTime = DPlayer.LaunchCoolTime;
	}
}

void Player::Collision()
{
	if (DPlayer.InvincibleRestTime > 0) {
		DPlayer.InvincibleRestTime -= delta;
	}
	else {
		//collision distance
		Bullets* bullets = GetGame()->GetEBullets();
		float distance = DPlayer.BcRadius+ bullets->GetBcRadius();
		float sqDistance = distance * distance;
		//player collision
		int curNum = bullets->GetCurNum();
		DPlayer.Color = DPlayer.NormalColor;
		for (int i = curNum - 1; i >= 0; i--) {
			VECTOR2 playerPos = DPlayer.Pos;
			playerPos.y -= DPlayer.CollisionOffSetY;
			VECTOR2 vec = playerPos - bullets->GetPos(i);
			if (vec.sqMag() < sqDistance) {
				DPlayer.Hp -= bullets->GetDamage();
				DPlayer.Color = DPlayer.DamageColor;
				DPlayer.InvincibleRestTime = DPlayer.InvincibleTime;
				bullets->Kill(i);
				i = 0;
			}
		}
	}
}

void Player::Draw()
{
	rectMode(CENTER);
	
	imageColor(DPlayer.Color);
	image(DPlayer.Img,DPlayer.Pos.x, DPlayer.Pos.y);
	fill(125, 125, 125, 100);
	circle(DPlayer.Pos.x, DPlayer.Pos.y+DPlayer.CollisionOffSetY, DPlayer.BcRadius*2);
	fill(255);
	print(DPlayer.Hp);
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

