#include "Playing_game.h"
#include"graphic.h"
#include"input.h"
#include"window.h"
#include"Container.h"
#include"Player.h"
#include"Player_bullets.h"
#include"Enemy.h"
#include"Enemy_bullets.h"
#include"Boss_bullets.h"
void Playing_game::Create()
{
	DPlayingGame = GetGame()->GetContainer()->GetData().playingGame;
	
	GetGame()->GetPlayer()->Create();
	for (int i = 0; i < Game::Etype_num; i++) {
		GetGame()->GetEBullets(i)->Create();
	}
	
	for (int i = 0; i < Game::Enemy_num; i++) {
		GetGame()->GetEnemy(i)->Create();
	}
	
	


	GetGame()->GetBoss()->Create();
	GetGame()->GetMap()->Create();
	GetGame()->GetBBullets()->Create();
}


void Playing_game::Init()
{
	initDeltaTime();
	DPlayingGame.KillCnt = 0;
	GetGame()->GetMap()->Init();
	GetGame()->GetPlayer()->Init();

	for (int i = 0; i < Game::Enemy_num; i++) {
		GetGame()->GetEnemy(i)->Init(i);
	}

	GetGame()->GetBoss()->Init();


	GetGame()->GetPBullets()->Init();

	for (int i = 0; i < Game::Etype_num; i++) {
		GetGame()->GetEBullets(i)->Init();
	}
	GetGame()->GetBBullets()->Init();

}

void Playing_game::Update()
{
	setDeltaTime();

	GetGame()->GetMap()->Update();
	GetGame()->GetPlayer()->Update();
	
	
	for (int i = 0; i < Game::Enemy_num; i++) {
		DPlayingGame.enemyHp[i] = GetGame()->GetEnemy(i)->GetHp();
		DPlayingGame.enemyPosY[i] = GetGame()->GetEnemy(i)->GetPos().y;
		if (DPlayingGame.enemyHp[i] <= 0 || DPlayingGame.enemyPosY[i] > height + 300) {
			if (GetGame()->GetEnemy(i)->Life == true) {
				DPlayingGame.KillCnt++;
				GetGame()->GetEnemy(i)->Life = false;
			}
		}

		else {
			GetGame()->GetEnemy(i)->Update();
		}
	}
	if (GetGame()->GetMap()->GetBossFlag() == true && DPlayingGame.KillCnt == Game::Enemy_num) {
		GetGame()->GetBoss()->Update();
	}
	
	GetGame()->GetPBullets()->Update();
	
	for (int i = 0; i < Game::Etype_num; i++) {
		GetGame()->GetEBullets(i)->Update();
	}
	GetGame()->GetBBullets()->Update();
	
}

void Playing_game::Draw()
{
	clear();
	print(GetGame()->GetMap()->GetWorldY());
	//actor
	GetGame()->GetMap()->Draw();
	GetGame()->GetPlayer()->Draw();
	
	for (int i = 0; i < Game::Enemy_num; i++) {
		if (DPlayingGame.enemyHp[i] > 0 && DPlayingGame.enemyPosY[i] < height + 300) {
			GetGame()->GetEnemy(i)->Draw();
		}
	}
	//boss faze
	if (GetGame()->GetMap()->GetBossFlag() == true|| DPlayingGame.KillCnt == Game::Enemy_num) {
		GetGame()->GetBoss()->Draw();
	}
	//bullet
	GetGame()->GetPBullets()->Draw();

	for (int i = 0; i < Game::Etype_num; i++) {
		GetGame()->GetEBullets(i)->Draw();
	}
	GetGame()->GetBBullets()->Draw();

}



void Playing_game::NextScene()
{
	if (GetGame()->GetPlayer()->GetHp() <= 0 && GetGame()->GetCurState() != GetGame()->EPauseGame) {
		GetGame()->ChangeScene(GetGame()->EGameOver);
	}
	if (isTrigger(KEY_P) && GetGame()->GetCurState() != GetGame()->EPauseGame) {
		GetGame()->GetPlayer()->SaveData();
		GetGame()->GetMap()->SaveData();
		//‚ ‚Æ‚Å“G‚Æƒ{ƒX‚Ì•Û‘¶‚à’Ç‰Á‚·‚é
		
		GetGame()->ChangePause(GetGame()->EPauseGame);
	}
	if (GetGame()->GetBoss()->GetHp()<=0) {
		GetGame()->ChangeScene(GetGame()->EGameClear);
	}
}
