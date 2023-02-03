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
bool Game::Initialize()
{
	window(1920, 1080,full);
	//container
	PContainer = new Container;

	
	//scene create
	Scenes[ETitle] = new Title(this);
	Scenes[ESStage] = new Select_stage(this);
	Scenes[ESChara] = new Select_character(this);
	Scenes[EPlaying] = new Playing_game(this);
	Scenes[EPauseGame] = new Pause_game(this);
	
	//material
	PPlayer = new Player(this);
	PMap = new Map(this);
	CurState = ETitle;
	return true;
}

void Game::RunLoop()
{
	GetContainer()->Load();
	for (int i = 0; i < State_num; i++) {
		Scenes[i]->Create();

	}
	PPlayer->Create();
	PMap->Create();
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
		SAFE_DELETE(Scenes[i]);
	}
	SAFE_DELETE(PContainer);
	SAFE_DELETE(PPlayer)
	closeWindow();

}

void Game::ProcessInput()
{

}

void Game::UpdateGame()
{
	Scenes[CurState]->Proc();
}

void Game::GenerateOutput()
{
	
}

void Game::ChangeScene(State scene)
{
	CurState = scene;
	Scenes[CurState]->Init();
}

void Game::ChangeState(State state)
{
	CurState = state;
}

