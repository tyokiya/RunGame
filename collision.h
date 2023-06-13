#pragma once
#include "DxLib.h"

struct Player;
struct Obstacle;
struct Sucore;

struct  CollisionCircle
{
	VECTOR pos;						//当たり判定円の中心座標
	bool hitFlg;					//衝突フラグ
	float radius;					//当たり判定の半径
};

/// <summary>
/// 当たり判定円の座標初期化
/// </summary>
/// <param name="circle">当たり判定構造体のポインタ</param>
/// <param name="setposition">セットする座標</param>
/// <param name="radius">セットする半径</param>
void CollisionCircleInit(CollisionCircle* circle, VECTOR setposition,float radius);

/// <summary>
/// はちの当たり判定円の座標初期化
/// </summary>
/// <param name="circle">当たり判定構造体のポインタ</param>
/// <param name="setposition">セットする座標</param>
/// <param name="radius">セットする半径</param>
void CollisionBeeCircleInit(CollisionCircle* circle, VECTOR setposition, float radius);

/// <summary>
/// プレイヤーの当たり判定座標移動
/// </summary>
/// <param name="circle">当たり判定構造体のポインタ</param>
/// <param name="setposition">座標の移動距離</param>
void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient);

/// <summary>
/// 障害物の当たり判定移動
/// </summary>
/// <param name="circle">当たり判定構造体のポインタ</param>
/// <param name="setposition">座標の移動距離</param>
void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveDistance);

/// <summary>
/// 障害物の当たり判定球描画(テスト用)
/// </summary>
/// <param name="circle">当たり判定構造体のポインタ</param>
void CollisionCircleDraw(CollisionCircle* circle, int radius);

/// <summary>
/// プレイヤーと障害物の衝突判定
/// </summary>
/// <param name="plyCircle">プレイヤーの当たり判定判定構造体のポインタ</param>
/// <param name="obstacleCircle">障害物の当たり判定判定構造体のポインタ</param>
/// <param name="ply">プレイヤーの構造体のポインタ</param>
/// <param name="obstacle">障害物の構造体のポインタ</param>
/// <param name="sucore">得点の構造体のポインタ</param>
void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore);