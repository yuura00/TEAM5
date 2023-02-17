#include "Enemy_no1.h"
#include"Container.h"
#include<time.h>
Enemy_no1::Enemy_no1(Game* game,int i)
	:Enemy(game)
{
	t=(unsigned int)time(NULL)+100*i;
	EnemyNo = i;
}
void Enemy_no1::Create()
{
	SetData(GetGame()->GetContainer()->GetData().enemy[0]);
}





