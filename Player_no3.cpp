#include "Player_no3.h"
#include"Game.h"
#include"Container.h"
#include"Player_bullets.h"
void Player_no3::Create()
{
	SetData(GetGame()->GetContainer()->GetData().player[2]);

}
