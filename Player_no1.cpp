#include "Player_no1.h"
#include"Game.h"
#include"Container.h"
#include"Player_bullets.h"
Player_no1::Player_no1(Game* game)
	:Player(game)
{

}
void Player_no1::Create()
{
	SetData(GetGame()->GetContainer()->GetData().player[0]);
	
}
