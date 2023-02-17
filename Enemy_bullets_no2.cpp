#include "Enemy_bullets_no2.h"
#include"Game.h"
#include"Container.h"
Enemy_bullets_no2::Enemy_bullets_no2(Game* game)
	:Bullets(game)
{

}

void Enemy_bullets_no2::Create()
{
	SetBulletData(GetGame()->GetContainer()->GetData().enemyBullet[1]);
}
