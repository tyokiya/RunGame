#pragma once
#include "DxLib.h"
#define GRAVITY 0.4f
#define JUMP 3.5f
#define JUMPMAXPEWER 15
#define PLYEFFECTCNT 10
#define PLAYER_RADIUS 10.0f

struct  CollisionCircle;
struct Obstacle;
struct Sucore;

//プレイヤー構造体
struct Player
{
	int	modelHandle;					//モデルハンドル
	VECTOR pos;							//プレイヤーの座標
	float obstacleDistance;				//ジャンプ時の障害物との距離
	bool jumpFlg;						//ジャンプフラグ
	float jumpCoefficient;				//ジャンプ力の係数
	bool jumpBtnPrevPress;				//1フレ前のジャンプボタン押下状態
	int jumpBtnPrevPressCnt;			//1フレ前のジャンプボタン押下状態のカウント
	bool displayFlg;					//生存フラグ
	bool pointFlg;						//得点を獲得したかのフラグ
	bool reviveFlg;						//復活フラグ
	int jumpSound;						//ジャンプ音
	int deatSound;						//死亡音
	int DamageEffect[PLYEFFECTCNT];				//ダメージエフェクト
	int effectCnt;						//エフェクトカウント
};

/// <summary>
/// プレヤーの初期化
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
void PlayerInit(Player* ply);

/// <summary>
/// プレヤーの更新
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
/// <param name="fps">フレームカウント</param>
/// <param name="collision">当たり判定の構造体ポインタ</param>
void PlayerUpdata(Player* ply, int fps, CollisionCircle* collision, Obstacle* obstacle, Sucore* sucore);

/// <summary>
/// プレヤーのジャンプ処理
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
/// <param name="collision">当たり判定の構造体ポインタ</param>
void PlayerJumpMove(Player* ply, int fps, CollisionCircle* collision);

/// <summary>
/// プレヤーの描画
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
void PlayerDraw(Player* ply);

/// <summary>
/// プレヤーの死亡時の動き
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
/// <param name="collision">当たり判定の構造体ポインタ</param>
void PlayerDeathMotion(Player* ply, int fps, CollisionCircle* collision);