#include "Enemy_no2.h"
#include"Container.h"
#include<time.h>
#include"window.h"
#include"Game.h"
#include"Map.h"
Enemy_no2::Enemy_no2(Game* game, int i)
	:Enemy(game)
{
	t = (unsigned int)time(NULL) + 100 * i;
	EnemyNo = i;
}
void Enemy_no2::Create()
{
	SetData(GetGame()->GetContainer()->GetData().enemy[1]);
}
void Move() {
	
}




