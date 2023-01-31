#pragma once
class Game_object
{
private:
	class Game* PGame = nullptr;
public:
	Game_object(class Game* game);
	virtual ~Game_object();
	class Game* GetGame() { return PGame; }
};

