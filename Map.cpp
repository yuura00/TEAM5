#include "Map.h"
#include"window.h"
#include"Game.h"
#include"Container.h"
void Map::Create()
{
	DMap = GetGame()->GetContainer()->GetData().map;
}

void Map::Init()
{
	DMap= GetGame()->GetContainer()->GetData().map;
}

void Map::Update()
{
	float sp = DMap.ScrollSpeed * delta;
	for (int i = 0; i < DMap.BackGroundImgNum; i++) {
		DMap.BackGroundPos[i].y += sp;
	}
	
	if (DMap.BackGroundPos[0].y > height) {
		DMap.BackGroundPos[0].y = DMap.BackGroundPos[2].y-height+3;
	}
	if (DMap.BackGroundPos[1].y > height) {
		DMap.BackGroundPos[1].y = DMap.BackGroundPos[0].y - height+3;
	}
	if (DMap.BackGroundPos[2].y > height) {
		DMap.BackGroundPos[2].y = DMap.BackGroundPos[1].y - height+3;
	}

}

void Map::Draw()
{
	rectMode(CORNER);
	for (int i = 0; i < DMap.BackGroundImgNum; i++) {
		image(DMap.BackGroundStageNo1, DMap.BackGroundPos[i].x, DMap.BackGroundPos[i].y);
	}
	
}


void Map::SetData()
{
	if (CheckError == true) {
		DMap = DPauseGame;
		CheckError = false;
	}
	else {
		print("ERROR");
	}
	
}

void Map::SaveData()
{
	CheckError = true;
	DPauseGame = DMap;
}

