#pragma once

struct Player;
struct Obstacle;
struct Sucore;
struct CollisionCircle;
struct Timer;

//ゲームシーン列挙体
enum GameScene
{
	TitleScene,	//タイトル
	PlayScene,	//プレイ
	ResultScene	//リザルト
};

//再スタート時の必要な要素の初期化
void ReSutartInit(Player& ply, Sucore& sucore, Timer& timer, Obstacle& obstacle_Bee, CollisionCircle& collision);
