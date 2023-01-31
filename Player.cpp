#include "Player.h"

#include"Game.h"
#include"Container.h"
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
}

void Player::Launch()
{
}

void Player::Collision()
{
}

void Player::Draw()
{
}
