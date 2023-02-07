#include "Bullets.h"
#include"window.h"
#include"graphic.h"
#include"input.h"
#include"Game.h"
#include"Container.h"
void Bullets::SetBulletData(const Data& data)
{
	PBullet = data;
	PBullets = new Bullet[PBullet.TotalNum];

}
Bullets::Bullets(Game* game)
	:Game_object(game)
{
}

Bullets::~Bullets()
{
	SAFE_DELETE_ARRAY(PBullets);
}


void Bullets::Init()
{
	PBullet.CurNum = 0;
}

void Bullets::Launch(const VECTOR2& pos, const VECTOR2& vec)
{
	if (PBullet.CurNum < PBullet.TotalNum) {
		int i = PBullet.CurNum;
		PBullets[i].Pos = pos + vec * PBullet.LaunchDistance;
		PBullets[i].Vec = vec;
		PBullets[i].Angle = 0;
		PBullet.CurNum++;
	}
}

void Bullets::Update()
{
	for (int i = PBullet.CurNum - 1; i >= 0; i--) {
		//move
		PBullets[i].Pos += PBullets[i].Vec * (PBullet.AdvSpeed * delta);
		PBullets[i].Angle += PBullet.AngSpeed;
		//ウィンドウの外に出たら
		if (PBullets[i].Pos.y < -PBullet.BcRadius ||
			PBullets[i].Pos.y > height +PBullet.BcRadius ||
			PBullets[i].Pos.x < -PBullet.BcRadius ||
			PBullets[i].Pos.x > width + PBullet.BcRadius
			) {
			Kill(i);
		}
	}
}

void Bullets::Draw()
{
	rectMode(CENTER);
	fill(255,0,0);
	for (int i = 0; i < PBullet.CurNum; i++) {
		circle(PBullets[i].Pos.x, PBullets[i].Pos.y, PBullet.BcRadius*2);
 	}
	print( PBullet.CurNum);
}

void Bullets::Kill(int i)
{//生きてる弾を死んだたまに上書き
	PBullet.CurNum--;
	PBullets[i] = PBullets[PBullet.CurNum];
}

