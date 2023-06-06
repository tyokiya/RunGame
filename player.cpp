#include"DxLib.h"
#include"player.h"
#include "collision.h"
#include"obstacle.h"
#include "sucore.h"

void PlayerInit(Player* ply)
{
	//3Dモデルの読み込み
	ply->modelHandle = MV1LoadModel("img/player/Character2.mv1");
	//3Dモデルの圧縮
	MV1SetScale(ply->modelHandle, VGet(0.1f, 0.1f, 0.1f));
	//座標のセット
	ply->pos = VGet(0.0f, 0.0f, 0.0f);
	//プレイヤーの回転値をセット(180度)
	MV1SetRotationXYZ(ply->modelHandle, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	//フラグ初期化
	ply->jumpFlg = false;
	ply->jumpBtnPrevPress = false;
	ply->displayFlg = true;
	ply->pointFlg = false;
	ply->reviveFlg = false;
	//値の初期化
	ply->jumpBtnPrevPressCnt = 0;
	ply->obstacleDistance = 0;

	//サウンド初期化
	ply->jumpSound = LoadSoundMem("sound/player/se_jump.wav");
	ply->deatSound = LoadSoundMem("sound/player/death.mp3");

	//エフェクト初期化
	LoadDivGraph("effect/pipo-mapeffect005.png", 10, 10, 1, 360, 360, ply->DamageEffect);
	//エフェクトカウント初期化
	ply->effectCnt = 0;
}

void PlayerUpdata(Player* ply, int fps,CollisionCircle* collision,Obstacle* obstacle, Sucore* sucore)
{
	//復活フラグ
	//ply->displayFlg = true;

	//プレイヤーの座標設定
	MV1SetPosition(ply->modelHandle, ply->pos);
	//キー読み込み
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ply->jumpFlg == false)
	{
		//フラグを立てる
		ply->jumpFlg = true;
		//ジャンプ係数を設定
		ply->jumpCoefficient = JUMP;
		//1フレ前の押下フラグを立てる
		ply->jumpBtnPrevPress = true;
		//ジャンプ時のプレイヤーと障害物の距離
		ply->obstacleDistance = obstacle->pos.z - ply->pos.z;
		//ジャンプ音再生
		PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
	}
	//長押しの確認
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ply->jumpBtnPrevPress == true && ply->jumpBtnPrevPressCnt < JUMPMAXPEWER)
	{
		//カウント増加
		ply->jumpBtnPrevPressCnt++;
	}
	else
	{
		//フラグを下す
		ply->jumpBtnPrevPress = false;
		//カウント初期化
		ply->jumpBtnPrevPressCnt = 0;
	}
	//ジャンプ処理
	if (ply->jumpFlg == true )
	{
		PlayerJumpMove(ply, fps,collision);
	}

	//障害物が通り過ぎたかを判定
	if (ply->jumpFlg == true && ply->pointFlg == false && obstacle->pos.z < ply->pos.z - 17.0f)
	{
		//スコアの追加処理
		SucoreAdd(sucore, ply->obstacleDistance);
		//スコアを獲得したらフラグを立てる
		ply->pointFlg = true;
	}

	//地面についたらフラグを下す
	if (ply->pos.y == 0.0f)
	{
		ply->jumpFlg = false;
		//ジャンプ係数を設定
		ply->jumpCoefficient = 0.0f;
		//ポイントフラグを下す
		ply->pointFlg = false;
	}
}

void PlayerJumpMove(Player* ply, int fps,CollisionCircle* collision)
{
	//座標移動
	ply->pos.y += ply->jumpCoefficient;
	//当たり判定の移動
	PlayerCollisionCircleMove(collision ,ply->jumpCoefficient);
	
	//地面にめり込んでいないかの確認
	if (ply->pos.y < 0.0f)
	{
		ply->pos.y = 0.0f;
	}
	//ジャンプ係数を下げる
	if (fps % 2 == 0 && ply->jumpBtnPrevPress == false)
	{
		ply->jumpCoefficient -= GRAVITY;
	}
}

void PlayerDraw(Player* ply)
{
	// プレイヤーの描画
	MV1DrawModel(ply->modelHandle);
	//if (ply->displayFlg == true)
	//DrawSphere3D(VGet(ply->pos.x,ply->pos.y + 10.0f,ply->pos.z), 10.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void PlayerDeathMotion(Player* ply, int fps)
{
	SetFontSize(200);
	VECTOR screenPos;
	if (ply->reviveFlg == false)
	{
		//移動
		ply->pos.y += 4.0f;
		ply->pos.z -= 0.9f;
		//プレイヤーの座標設定
		MV1SetPosition(ply->modelHandle, ply->pos);
		//プレイヤーモデルの画面座標を取得
		screenPos = ConvWorldPosToScreenPos(ply->pos);
		//エフェクト描画
		DrawGraph(screenPos.x - 100, screenPos.y - 200, ply->DamageEffect[ply->effectCnt], TRUE);
		//エフェクトカウント増加
		if (fps % 5 == 0 && ply->effectCnt != 10)
		{
			ply->effectCnt++;
		}
		//ミス描画
		DrawFormatString(400, 0, GetColor(255, 0, 0), "MISS");
	}
	else
	{
		//移動
		ply->pos.y -= 4.0f;
		//プレイヤーの座標設定
		MV1SetPosition(ply->modelHandle, ply->pos);
		//フラグをリセット
		if (ply->pos.y == 0)
		{
			ply->reviveFlg = false;
			ply->displayFlg = true;
		}
		//エフェクトカウントりっせと
		ply->effectCnt = 0;
	}
	//復活フラグを立てる
	if (ply->pos.z < -20)
	{
		ply->reviveFlg = true;
		//座標リセット
		ply->pos = VGet(0.0f, 300.0f, 0.0f);
	}
}