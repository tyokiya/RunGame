#include "obstacle.h"
#include <stdlib.h>
#include <time.h>
#include "collision.h"

void ObstacleInit(Obstacle* obstacle, int modelHandl)
{
	//3Dモデル読み込み
	obstacle->modelHandle = modelHandl;
	//座標セット
	obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);
	//拡大率セット
	MV1SetScale(obstacle->modelHandle, VGet(0.4f, 0.4f, 0.4f));
	//フラグを立てる
	obstacle->displayFlg = true;
	//速度初期化
	obstacle->moveSpeed = OBSTACLE_DEFOMOVE_SPEED;
}

void ObstacleUpdate(Obstacle* obstacle, CollisionCircle* collision)
{
	//ランダム初期化
	srand((unsigned int)time(NULL));
	
	//障害物の再生成
	if (obstacle->displayFlg == false)
	{
		//距離をランダム生成
		//int num = (rand() % 5 + 1) * 100;
		//フラグを立てる
		obstacle->displayFlg = true;
		//座標のセット
		obstacle->pos = VGet(0.0f, 0.0f, OBSTACLE_INITIAL_POSZ);
		//当たり判定の座標セット
		CollisionCircleInit(collision, obstacle->pos);
		//速度のランダム生成
		obstacle->moveSpeed =((rand() % 40 + 1) + 10) / 10;
		//obstacle->moveSpeed = 
	}

	//1.8ずつプレイヤーに向かって移動
	if (obstacle->displayFlg == true)
	{
		//座標の増加
		obstacle->pos.z -= obstacle->moveSpeed;
		//障害物の座標設定
		MV1SetPosition(obstacle->modelHandle, obstacle->pos);
		//当たり判定の移動
		ObstacleCollisionCircleMove(collision, obstacle->moveSpeed);
	}

	//画面外にでた時点で表示フラグを下ろす
	if (obstacle->pos.z <= -20.0)
	{
		obstacle->displayFlg = false;
	}
}

void ObstacleDraw(Obstacle* obstacle)
{
	//描画(フラグが立っている場合のみ)
	if (obstacle->displayFlg == true)
	{
		MV1DrawModel(obstacle->modelHandle);
	}
}