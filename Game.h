#pragma once

class Game
{

private:
	class Container* PContainer=0;
public:
	class Container* GetContainer() { return PContainer; }
public:
	
	enum Enemy_name {
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
		EGameClear,
		EGameOver,
		State_num

	};
	enum Type_enemy {
		TypeNo1,
		Typeno2,
		Etype_num
	};
	bool PauseSw=false;
	State NextScene=ETitle;
	State CurState=ETitle;
	
	
	
private:
	class Scene* Scene[State_num];
	
	
	class Player* PPlayer;
	class Enemy* PEnemy;
	class Boss* PBoss;
	class Map* PMap;
	class Bullets* PBullet;
	class Player_bullets* PPBullet;
	class Enemy_bullets* PEBullet;
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
	class Boss* GetBoss() { return PBoss; }
	class Map* GetMap() { return PMap; }
	class Bullets* GetBullets() { return PBullet; }
	class Player_bullets* GetPBullets() { return PPBullet; }
	class Enemy_bullets* GetEBullets() { return PEBullet; }
	
private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	


};

