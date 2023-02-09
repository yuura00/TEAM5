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
#include"Map.h"
#include"Player_bullets.h"
#include"Enemy_bullets.h"
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
		SAFE_DELETE(Scene[CurState]);
	}
	SAFE_DELETE(PContainer);
	SAFE_DELETE(PPlayer);
	for (int i = 0; i < Enemy_num; i++) {
		SAFE_DELETE(PEnemy[i]);
	}
	SAFE_DELETE(PMap);
	SAFE_DELETE(PBullets);
	SAFE_DELETE(PPBullets);
	SAFE_DELETE(PEBullets);
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
		if ((NextScene!=EPauseGame&&NextScene!=EPlaying)&&(CurState==EPlaying||CurState==EPauseGame)) {
			SAFE_DELETE(PPlayer);
			for (int i = 0; i < Enemy_num; i++) {
				SAFE_DELETE(PEnemy[i]);
			}
			SAFE_DELETE(PMap);
			SAFE_DELETE(PBullets);
			SAFE_DELETE(PPBullets);
			SAFE_DELETE(PEBullets);
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
		case ESStage:
			SAFE_DELETE(Scene[CurState]);
			Scene[ESStage] = new Select_stage(this);
		case ESChara:
			SAFE_DELETE(Scene[CurState]);
			Scene[ESChara] = new Select_character(this);
		case EPlaying:
			
			SAFE_DELETE(Scene[CurState]);
			if (PauseSw != true) {
				Scene[EPlaying] = new Playing_game(this);
				PPlayer = new Player(this);
				for (int i = 0; i < Enemy_num; i++) {
					PEnemy[i] = new Enemy(this);
				}
				
				PMap = new Map(this);
				PBullets = new Bullets(this);
				PPBullets = new Player_bullets(this);
				PEBullets = new Enemy_bullets(this);
			}
		case EPauseGame:
			
			Scene[EPauseGame] = new Pause_game(this);
			
	}
		

}

Enemy* Game::GetEnemy(int i)
{
	if (i == 0) {
		return PEnemy[EnemyNo1];
	}
	else if (i == 1) {
		return PEnemy[EnemyNo2];
	}
	else if (i == 2) {
		return PEnemy[EnemyNo3];
	}
	else{
		print("Error");
		return 0;
	}
}


