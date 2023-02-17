#include "Boss_bullets.h"
#include"Game.h"
#include"Container.h"
void Boss_bullets::Create()
{
	SetBulletData(GetGame()->GetContainer()->GetData().bossBullets);
}
