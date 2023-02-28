#include "Player_no2.h"
#include"Game.h"
#include"Container.h"
#include"Player_bullets.h"
void Player_no2::Create()
{
	SetData(GetGame()->GetContainer()->GetData().player[1]);

}
