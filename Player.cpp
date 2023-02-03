#include "Player.h"

#include"Game.h"
#include"Container.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
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
	if (isTrigger(KEY_SPACE)) {

	}
}

void Player::Collision()
{
}

void Player::Draw()
{
	rectMode(CENTER);
	fill(255);
	rect(DPlayer.Pos.x, DPlayer.Pos.y, DPlayer.HalfSizeW*2, DPlayer.HalfSizeH*2);
}
