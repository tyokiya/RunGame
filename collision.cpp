#include"DxLib.h"
#include "collision.h"
#include "player.h"
#include "obstacle.h"
#include "sucore.h"
#include <math.h>

void CollisionCircleInit(CollisionCircle* circle, VECTOR setposition, float radius)
{
	//座標のセット
	circle->pos = setposition;
	//フラグのしょきか
	circle->hitFlg = false;
	//半径のセット
	circle->radius = radius;
}

void CollisionBeeCircleInit(CollisionCircle* circle, VECTOR setposition, float radius)
{
	//座標のセット
	circle->pos = setposition;
	//座標の微調整
	circle->pos.y += 10.0f;
	//フラグのしょきか
	circle->hitFlg = false;
	//半径のセット
	circle->radius = radius;
}

void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient)
{
	circle->pos.y += jumpCoefficient;
}

void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveSpeed)
{
	circle->pos.z -= moveSpeed;
}

void CollisionCircleDraw(CollisionCircle* circle,int radius)
{
	DrawSphere3D(circle->pos, radius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore)
{
	//三平方の定理で衝突判定
	if (sqrt(pow(obstacleCircle->pos.x - plyCircle->pos.x, 2)
		+ pow(obstacleCircle->pos.y - plyCircle->pos.y, 2)
		+ pow(obstacleCircle->pos.z - plyCircle->pos.z, 2))
		< plyCircle->radius + obstacleCircle->radius)
	{
		//生存フラグを下す
		ply->displayFlg = false;
		obstacle->displayFlg = false;
		//スコアの減点
		SucoreDow(sucore);
		//死亡サウンド再生
		PlaySoundMem(ply->deatSound, DX_PLAYTYPE_BACK);
	}
}

