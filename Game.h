#pragma once

class Game
{
private:
	class Container* PContainer=0;
public:
	class Container* GetContainer() { return PContainer; }
public:
	enum State {
		ETitle,
		ESStage,ESChara,
		EPlaying,
		EPauseGame,
		//EGameClear,
		//EGameOver,
		State_num

	};
	bool PauseSw;
	State NextScene=ETitle;
	State CurState=ETitle;

private:
	class Scene* Scene[State_num];
	
	
	class Player* PPlayer;
	class Enemy* PEnemy;
	class Map* PMap;
	class Bullets* PBullets;
	class Player_bullets* PPBullets;
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void ChangeScene(State scene);
	void ChangePause(State state);
	void CreateScene(State i);
	
	int GetCurState() { return CurState; }
	class Player* GetPlayer() { return PPlayer; }
	class Enemy* GetEnemy() { return PEnemy; }
	class Map* GetMap() { return PMap; }
	class Bullets* GetBullets() { return PBullets; }
	class Player_bullets* GetPBullets() { return PPBullets; }
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	


};

