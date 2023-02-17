#include "Game.h"
#include"framework.h"
#include"graphic.h"
#include"window.h"
#include"input.h"
#include"Title.h"
#include"Select_stage.h"
#include"Select_character.h"
#include"Playing_game.h"
#include"Pause_game.h"
#include"Container.h"
#include"Player.h"
#include"Enemy_no1.h"
#include"Enemy_no2.h"
#include"Map.h"
#include"Player_bullets.h"
#include"Enemy_bullets.h"
#include"Enemy_bullets_no2.h"
#include"Boss_bullets.h"
#include"Game_clear.h"
#include"Game_over.h"


bool Game::Initialize()
{
	window(1920, 1080,full);
	//container
	PContainer = new Container;

	
	//scene create
	Scene[CurState] = new Title(this);
	
	
	//material
	
	CurState = ETitle;
	return true;
}

void Game::RunLoop()
{
	GetContainer()->Load();
	Scene[CurState]->Create();
	
	while (notQuit)
	{
		ProcessInput();
		UpdateGame();
		GenerateOutput();
	}
}

void Game::Shutdown()
{
	for (int i = 0; i < State_num; i++) {
		SAFE_DELETE(Scene[i]);
	}
	SAFE_DELETE(PContainer);
	SAFE_DELETE(PPlayer);
	for (int i = 0; i < Enemy_num; i++) {
		SAFE_DELETE(PEnemy[i]);
	}
	
	SAFE_DELETE(PBoss);

	SAFE_DELETE(PMap);
	SAFE_DELETE(PBullet);
	SAFE_DELETE(PPBullet);
	SAFE_DELETE(PEBullet[0]);
	SAFE_DELETE(PEBullet[1]);

	
	closeWindow();

}

void Game::ProcessInput()
{

}

void Game::UpdateGame()
{
	Scene[CurState]->Proc();
	if (CurState != NextScene) {
		CreateScene(NextScene);
		if ((NextScene ==EGameClear|| NextScene ==EGameOver) ){
			SAFE_DELETE(PPlayer);
			
			for (int i = 0; i < Enemy_num; i++) {
				SAFE_DELETE(PEnemy[i]);
			}
		
			
			SAFE_DELETE(PBoss);
			SAFE_DELETE(PMap);
			SAFE_DELETE(PBullet);
			SAFE_DELETE(PPBullet);
			SAFE_DELETE(PEBullet[0]);
			SAFE_DELETE(PEBullet[1]);


		}
		CurState = NextScene;
		
		if (PauseSw != true) {
			Scene[CurState]->Create();
  			Scene[CurState]->Init();
		}
		PauseSw = false;
	}
}

void Game::GenerateOutput()
{
	
}

void Game::ChangeScene(State nextScene)
{
	NextScene = nextScene;
}

//init Ç»ÇµêÿÇËë÷Ç¶
void Game::ChangePause(State state)
{
	NextScene = state;
	PauseSw = true;
}

void Game::CreateScene(State i)
{
	switch (i) {
		case ETitle:
			SAFE_DELETE(Scene[CurState]);
			Scene[ETitle] = new Title(this);
			break;
		case ESStage:
			SAFE_DELETE(Scene[CurState]);
			Scene[ESStage] = new Select_stage(this);
			break;
		case ESChara:
			SAFE_DELETE(Scene[CurState]);
			Scene[ESChara] = new Select_character(this);
			break;
		case EPlaying:
			
			SAFE_DELETE(Scene[CurState]);
			if (PauseSw != true) {
				Scene[EPlaying] = new Playing_game(this);
				PPlayer = new Player(this);
				for (int i = 0; i < Enemy_num; i++) {
					if (i % 4 == 0) {
						PEnemy[i] = new Enemy_no2(this, i);
					}
					else {
						PEnemy[i] = new Enemy_no1(this, i);
					}
				}
				PBoss = new Boss(this);
				PMap = new Map(this);
				PBullet = new Bullets(this);
				PPBullet = new Player_bullets(this);

				PEBullet[0] = new Enemy_bullets(this);
				PEBullet[1] = new Enemy_bullets_no2(this);
				PBBullet = new Boss_bullets(this);
			}
			break;
		case EPauseGame:
			
			Scene[EPauseGame] = new Pause_game(this);
			break;
		case EGameClear:
			SAFE_DELETE(Scene[CurState]);
			Scene[EGameClear] = new Game_clear(this);
			break;
		case EGameOver:
			
			SAFE_DELETE(Scene[CurState]);
			Scene[EGameOver] = new Game_over(this);
			break;
	}
		

}

void Game::EnemyDataMove(int enemyNo,int& killCnt)
{
	
	int no = 0;
	for (int i = enemyNo; i < Enemy_num - 1-killCnt; i++) {
		PEnemy[i] = PEnemy[i + 1];
		PEnemy[i]->EnemyNo = i;
		no = i + 1;
	}
	killCnt++;
	SAFE_DELETE(PEnemy[no]);
}

void Game::DeleteEnemy(int enemyNo)
{
	SAFE_DELETE(PEnemy[enemyNo]); 
}






