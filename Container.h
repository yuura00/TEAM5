#pragma once
#include "Game_object.h"
#include"Title.h"
#include"Select_stage.h"
#include"Select_character.h"
#include"Select_machine.h"
#include"Player.h"
#include"Playing_game.h"
#include"Map.h"
#include"Bullets.h"
#include"Enemy.h"
#include"Boss.h"
#include"Game.h"

class Container 
{
private:
    struct CharaStatus {
        int Hp;
        float Speed;
        int Damage;
        float UltTime;
    };
    struct ALL_DATA {
        Title::Data title;
        Select_stage::Data sStage;
        Select_character::Data sCharacter;
        Select_machine::Data sMachine;
        Playing_game::Data playingGame;

        Player::Data player[Game::MType_num];
        Enemy::Data enemy[Game::EType_num];
        Boss::Data boss;
        
        Bullets::Data playerBullet;
        Bullets::Data enemyBullet[2];
        Bullets::Data bossBullets;
        
        Map::Data map;

        CharaStatus chara[3];
        int CursorSound;
        int DecisionSound;
        int GameClearImg;
        int GameOverImg;
    };
    ALL_DATA Data;
    
    
    void Set_data();
    void Load_graphic();
    void LoadSound();
public:
    Container();
    void Load();
    const ALL_DATA GetData() { return Data; }
    
};

