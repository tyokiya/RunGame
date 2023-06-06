#include"DxLib.h"
#include "collision.h"
#include "player.h"
#include "obstacle.h"
#include "sucore.h"

void CollisionCircleInit(CollisionCircle* circle,VECTOR setposition) 
{
	//座標のセット
	circle->pos = setposition;
	//フラグのしょきか
	circle->hitFlg = false;
}

void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient)
{
	circle->pos.y += jumpCoefficient;
}

void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveSpeed)
{
	circle->pos.z -= moveSpeed;
}

void CollisionCircleDraw(CollisionCircle* circle)
{
	DrawSphere3D(circle->pos, RADIUS, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore)
{
	//それぞれの座標の距離すべて半径より小さくなったらヒット判定
	if (plyCircle->pos.x + obstacleCircle->pos.x < (RADIUS * 2)
	 && plyCircle->pos.y + obstacleCircle->pos.y < (RADIUS * 2)
	 && plyCircle->pos.z + obstacleCircle->pos.z < (RADIUS * 2))
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