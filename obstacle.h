#pragma once
#include "DxLib.h"
#define OBSTACLE_DEFOMOVE_SPEED 1.8
#define OBSTACLE_BEE_SPEED 1.5
#define OBSTACLE_INITIAL_POSX 0.0f
#define OBSTACLE_INITIAL_POSY 0.0f
#define OBSTACLE_INITIAL_POSZ 200.0f
#define OBSTACLE_BEE_POSY 65.0f
#define OBSTACLE_RADIUS 10.0f
#define OBSTACLE_BEE_RADIUS 8.0f

struct  CollisionCircle;

//障害物の構造体
struct Obstacle
{
	int	modelHandle;		//モデルハンドル
	VECTOR pos;				//障害物の座標
	bool displayFlg;		//表示フラグ
	float moveSpeed;		//移動速度
};

/// <summary>
/// 障害物の初期化
/// </summary>
/// <param name="obstacle">障害物の構造体ポインタ</param>
/// <param name="modelHandl">読み込ませる画像ハンドル</param>
void ObstacleInit(Obstacle* obstacle,int modelHandl);

/// <summary>
/// はち障害物の初期化
/// </summary>
/// <param name="obstacle">障害物の構造体ポインタ</param>
/// <param name="modelHandl">読み込ませる画像ハンドル</param>
void ObstacleBeeInit(Obstacle* obstacle, int modelHandl);

/// <summary>
/// 障害物の情報更新
/// </summary>
/// <param name="obstacle">障害物の構造体ポインタ</param>
/// <param name="collision">当たり判定の構造体ポインタ</param>
void ObstacleUpdate(Obstacle* obstacle, CollisionCircle* collision);

/// <summary>
/// はち障害物の情報更新
/// </summary>
/// <param name="obstacle">障害物の構造体ポインタ</param>
/// <param name="collision">当たり判定の構造体ポインタ</param>
void ObstacleBeeUpdate(Obstacle* obstacle, CollisionCircle* collision);

/// <summary>
/// 障害物の描画
/// </summary>
/// <param name="obstacle">障害物の構造体ポインタ</param>
void ObstacleDraw(Obstacle* obstacle);

/// <summary>
/// すべて障害物のフラグをおろす　
/// </summary>
/// <param name="obstacle">いわ障害物の構造体ポインタ</param>
/// <param name="obsracle_bee">ハチ障害物の構造体ポインタ</param>
void AllObstacleFlgReset(Obstacle* obstacle, Obstacle* obsracle_bee);

