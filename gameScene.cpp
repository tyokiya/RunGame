#include"DxLib.h"
#include "gameScene.h"
#include "player.h"
#include "sucore.h"
#include "timer.h"
#include "obstacle.h"
#include "collision.h"

void ReSutartInit(Player& ply, Sucore& sucore, Timer& timer, Obstacle& obstacle_Bee, CollisionCircle& collision)
{
	//プレイヤーの初期化
	ply.displayFlg = true;
	ply.jumpFlg = false;
	ply.jumpBtnPrevPress = false;
	ply.pointFlg = false;
	ply.reviveFlg = false;
	ply.jumpBtnPrevPressCnt = 0;
	ply.obstacleDistance = 0;
	ply.pos = VGet(0.0f, 0.0f, 0.0f);
	MV1SetRotationXYZ(ply.modelHandle, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	//スコア初期化
	sucore.nowScore = 0;
	sucore.drawFlg = false;
	sucore.drawCnt = 0;
	//タイマー初期化
	timer.timeLimit = TIMELIMIT;
	timer.timeOverFlg = false;
	timer.timeOverFrameCnt = 0;
	//障害物ハチの初期化
	obstacle_Bee.pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_BEE_POSY, OBSTACLE_INITIAL_POSZ);
	MV1SetPosition(obstacle_Bee.modelHandle, obstacle_Bee.pos);
	obstacle_Bee.displayFlg = true;
	//座標のセット
	collision.pos = obstacle_Bee.pos;
	//座標の微調整
	collision.pos.y += 10.0f;
	//フラグのしょきか
	collision.hitFlg = false;
}