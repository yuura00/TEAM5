#include "Enemy_bullets.h"
#include"Game.h"
#include"Container.h"
Enemy_bullets::Enemy_bullets(Game* game)
	:Bullets(game)
{
	
}

void Enemy_bullets::Create()
{
	SetBulletData(GetGame()->GetContainer()->GetData().enemyBullet[0]);
}
