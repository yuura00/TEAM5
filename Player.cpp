#include "Player.h"
#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Player_bullets.h"
#include"Enemy_bullets.h"
#include"Boss_bullets.h"
#include"sound.h"
Player::Player(Game* game)
	:Game_object(game)
{

}

Player::~Player()
{
}
void Player::SetData(const Data& data)
{
	DPlayer = data;
}
void Player::Create()
{
	
}

void Player::Init()
{
	const Data& p = GetGame()->GetContainer()->GetData().player[GetGame()->GetMachineNum()];
	int cHp = GetGame()->GetContainer()->GetData().chara[GetGame()->GetCharaNum()].Hp;
	int cSp = GetGame()->GetContainer()->GetData().chara[GetGame()->GetCharaNum()].Speed;
	int cDmg = GetGame()->GetContainer()->GetData().chara[GetGame()->GetCharaNum()].Damage;
	

	DPlayer.Pos =p.Pos;
	DPlayer.Hp = p.Hp+cHp;
	DPlayer.InitHp = p.Hp + cHp;
	DPlayer.Speed = p.Speed + cSp;
	DPlayer.Damage = p.Damage + cDmg;
	DPlayer.UltTime = GetGame()->GetContainer()->GetData().chara[GetGame()->GetCharaNum()].UltTime;
}

void Player::Update()
{
	if (isTrigger(KEY_C)) {
		DPlayer.Hp = 100;
	}
	Move();
	Launch();
	if (DPlayer.UltTimeFlag == false || GetGame()->GetCharaNum()!=2) {
		Collision();
	}
	DPlayer.CurUltDeltaTime += delta;
	if (DPlayer.UltChargeSp <= DPlayer.CurUltDeltaTime) {
		if (DPlayer.UltPoint < 100) {
			DPlayer.UltPoint++;
			DPlayer.CurUltDeltaTime = 0;
		}
	}
	if (DPlayer.UltPoint > 100) {
		DPlayer.UltPoint = 100;
	}
	if (DPlayer.UltPoint == 100&&isTrigger(KEY_R)) {
		DPlayer.UltFlag = true;
	}
	//beryl ult
	if (DPlayer.UltFlag == true) {
		CharaUlt(GetGame()->GetCharaNum());
		DPlayer.UltPoint = 0;
		DPlayer.UltTimeFlag = true;
		DPlayer.UltFlag = false;
	}
	if (DPlayer.UltTimeFlag == true) {
		DPlayer.UltTime-=delta;
		if (DPlayer.UltTime <= 0) {
			DPlayer.UltTime = GetGame()->GetContainer()->GetData().chara[GetGame()->GetCharaNum()].UltTime;
			DPlayer.UltTimeFlag = false;
		}
	}

	
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
	
	if (isPress(KEY_SPACE)&&DPlayer.TriggerCooltime<=0) {
		DPlayer.CurLaunchCoolTime += delta;
		if (DPlayer.CurLaunchCoolTime > DPlayer.LaunchCoolTime) {
			GetGame()->GetPBullets()->Launch(DPlayer.Pos, DPlayer.LaunchVec);
			DPlayer.CurLaunchCoolTime = 0;
			playSound(DPlayer.ShootSound);
		}
		DPlayer.TriggerCooltime = DPlayer.InitTriggerCoolTime;
	}
	else {
		DPlayer.CurLaunchCoolTime = DPlayer.LaunchCoolTime;
		DPlayer.TriggerCooltime -= delta;
	}
}

void Player::Collision()
{
	if (DPlayer.InvincibleRestTime > 0) {
		DPlayer.InvincibleRestTime -= delta;
	}
	else {
		//collision distance
		Boss_bullets* bossBullets = GetGame()->GetBBullets();
		float distance = DPlayer.BcRadius + bossBullets->GetBcRadius();
		float sqDistance = distance * distance;
		int curNum = bossBullets->GetCurNum();
		DPlayer.Color = DPlayer.NormalColor;
		for (int i = curNum - 1; i >= 0; i--) {
			VECTOR2 playerPos = DPlayer.Pos;
			playerPos.y -= DPlayer.CollisionOffSetY;
			VECTOR2 vec = playerPos - bossBullets->GetPos(i);
			if (vec.sqMag() < sqDistance) {
				DPlayer.Hp -= bossBullets->GetDamage();
				DPlayer.Color = DPlayer.DamageColor;
				DPlayer.InvincibleRestTime = DPlayer.InvincibleTime;
				bossBullets->Kill(i);
				i = 0;
			}
		}
		Bullets* bullets[Game::EType_num];
		for (int j = 0; j < Game::EType_num;j++) {
			
			bullets[j] = GetGame()->GetEBullets(j);
			distance = DPlayer.BcRadius + bullets[j]->GetBcRadius();
			sqDistance = distance * distance;
			//player collision
			int curNum = bullets[j]->GetCurNum();
			
			for (int i = curNum - 1; i >= 0; i--) {
				VECTOR2 playerPos = DPlayer.Pos;
				playerPos.y -= DPlayer.CollisionOffSetY;
				VECTOR2 vec = playerPos - bullets[j]->GetPos(i);
				if (vec.sqMag() < sqDistance) {
					DPlayer.Hp -= bullets[j]->GetDamage();
					DPlayer.Color = DPlayer.DamageColor;
					DPlayer.InvincibleRestTime = DPlayer.InvincibleTime;
					bullets[j]->Kill(i);
					i = 0;
				}
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
	if (DPlayer.UltTimeFlag == true) {
		image(DPlayer.UltImg, DPlayer.Pos.x, DPlayer.Pos.y);
	}
	//print(DPlayer.Hp);
	//print(DPlayer.LaunchCoolTime);
	//print(DPlayer.UltPoint);

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

void Player::CharaUlt(int i)
{
	switch (i) {
	case 0:
		//increse 30 damage 
		DPlayer.Damage += 30;
		break;
	case 1:
		//cure hp 30%
		DPlayer.Hp += (DPlayer.InitHp / 100) * 30;
		if (DPlayer.Hp > DPlayer.InitHp) {
			DPlayer.Hp = DPlayer.InitHp;
		}
		break;
	case 2:
		//avoid enemy attack
		
		break;
	}
}

