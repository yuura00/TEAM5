#include"Game.h"
#include "Game_object.h"

Game_object::Game_object(Game* game)
{
	PGame = game;
}

Game_object::~Game_object()
{
	PGame = nullptr;
}
