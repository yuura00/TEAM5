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
		EnemyNo4,
		EnemyNo5,
		EnemyNo6,
		EnemyNo7,
		EnemyNo8,
		Enemyno9,
		EnemyNo10,
		EnemyNo11,
		EnemyNo12,
		EnemyNo13,
		EnemyNo14,
		EnemyNo15,
		EnemyNo16,
		EnemyNo17,
		EnemyNo18,
		EnemyNo19,
		EnemyNo20,
		EnemyNo21,
		EnemyNo22,
		EnemyNo23,
		EnemyNo24,
		EnemyNo25,
		EnemyNo26,
		EnemyNo27,
		EnemyNo28,
		Enemyno29,
		EnemyNo30,
		EnemyNo31,
		EnemyNo32,
		EnemyNo33,
		EnemyNo34,
		EnemyNo35,
		EnemyNo36,
		EnemyNo37,
		EnemyNo38,
		EnemyNo39,
		EnemyNo40,
		Enemy_num,
	};
	enum State {
		ETitle,
		ESStage,ESChara,
		ESMachine,
		EPlaying,
		EPauseGame,
		EGameClear,
		EGameOver,
		State_num

	};
	enum Type_machine {
		Goliath,
		Gleipnir,
		Hameln,
		MType_num
	};
	enum Type_enemy {
		TypeNo1,
		Typeno2,
		EType_num
	};
	bool PauseSw=false;
	State NextScene=ETitle;
	State CurState=ETitle;
	
	struct SelectInfo {
		int MachineNum = 0;
		int CharaNum=0;
	};
	
private:
	SelectInfo SI;
	class Scene* Scene[State_num];
	
	
	class Player* PPlayer;
	class Enemy* PEnemy[Enemy_num];
	class Boss* PBoss;
	class Map* PMap;
	class Bullets* PBullet;
	class Player_bullets* PPBullet;
	class Bullets* PEBullet[EType_num];
	class Boss_bullets* PBBullet;
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void ChangeScene(State scene);
	void ChangePause(State state);
	void CreateScene(State i);
	

	int GetCurState() { return CurState; }
	class Player* GetPlayer() { return PPlayer; }
	class Enemy* GetEnemy(int enemyNo) { return PEnemy[enemyNo]; }
	void EnemyDataMove(int enemyNo,int& killCnt);
	void DeleteEnemy(int enemyNo);
	class Boss* GetBoss() { return PBoss; }
	class Map* GetMap() { return PMap; }
	class Bullets* GetBullets() { return PBullet; }
	class Player_bullets* GetPBullets() { return PPBullet; }
	class Bullets* GetEBullets(int i) { return PEBullet[i]; }
	class Boss_bullets* GetBBullets() { return PBBullet; }
	int GetMachineNum() { return SI.MachineNum; }
	int GetCharaNum() { return SI.CharaNum; }
	void SetMachineNum(int i) { SI.MachineNum = i; }
	void SetCharaNum(int i) { SI.CharaNum = i; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	


};

