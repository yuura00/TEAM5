#include "Player_bullets.h"
#include"Game.h"
#include"Container.h"
Player_bullets::Player_bullets(Game* game)
	:Bullets(game)
{
}

void Player_bullets::Create()
{
	SetBulletData(GetGame()->GetContainer()->GetData().playerBullet);
}
