#pragma once

class Game
{
private:
	class Container* PContainer=0;
public:
	class Container* GetContainer() { return PContainer; }
public:
	
	enum Type_enemy {
		EnemyNo1,
		EnemyNo2,
		EnemyNo3,
		Enemy_num,
	};
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
	
	int TypeNum;
	
private:
	class Scene* Scene[State_num];
	
	
	class Player* PPlayer;
	class Enemy* PEnemy[Enemy_num];
	class Map* PMap;
	class Bullets* PBullets;
	class Player_bullets* PPBullets;
	class Enemy_bullets* PEBullets;
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void ChangeScene(State scene);
	void ChangePause(State state);
	void CreateScene(State i);
	
	int GetCurState() { return CurState; }
	class Player* GetPlayer() { return PPlayer; }
	class Enemy* GetEnemy(int i);
	class Map* GetMap() { return PMap; }
	class Bullets* GetBullets() { return PBullets; }
	class Player_bullets* GetPBullets() { return PPBullets; }
	class Enemy_bullets* GetEBullets() { return PEBullets; }
	
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	


};

