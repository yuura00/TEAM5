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
	SAFE_DELETE(PEnemy);
	SAFE_DELETE(PBoss);

	SAFE_DELETE(PMap);
	SAFE_DELETE(PBullet);
	SAFE_DELETE(PPBullet);
	SAFE_DELETE(PEBullet);
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
			SAFE_DELETE(PEnemy);
			SAFE_DELETE(PBoss);
			SAFE_DELETE(PMap);
			SAFE_DELETE(PBullet);
			SAFE_DELETE(PPBullet);
			SAFE_DELETE(PEBullet);
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
				PEnemy = new Enemy(this);
				PBoss = new Boss(this);
				PMap = new Map(this);
				PBullet = new Bullets(this);
				PPBullet = new Player_bullets(this);
				PEBullet= new Enemy_bullets(this);
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




