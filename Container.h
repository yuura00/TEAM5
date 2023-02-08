#pragma once
#include "Game_object.h"
#include"Title.h"
#include"Select_stage.h"
#include"Player.h"
#include"Playing_game.h"
#include"Map.h"
#include"Bullets.h"
#include"Enemy.h"
#include"Game.h"
class Container 
{
private:
    struct ALL_DATA {
        Title::Data title;
        Select_stage::Data sStage;
        Playing_game::Data playingGame;

        Player::Data player;
        Enemy::Data enemy[3];
        Bullets::Data playerBullet;
        Bullets::Data enemyBullet;
        
        Map::Data map;
    };
    ALL_DATA Data;

    
    void Set_data();
    void Load_graphic();
public:
    Container();
    void Load();
    const ALL_DATA GetData() { return Data; }
};

