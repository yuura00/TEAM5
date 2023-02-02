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
	

private:
	class Scene* Scenes[State_num];
	State CurState;
	
public:
	bool Initialize();
	void RunLoop();
	void Shutdown();
	void ChangeScene(State scene);
	void ChangeState(State state);
	
	State GetCurState() { return CurState; }

private:
	void ProcessInput();
	void UpdateGame();
	void GenerateOutput();
	


};

