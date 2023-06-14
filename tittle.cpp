#include "DxLib.h"
#include "tittle.h"
#include "player.h"
#include "obstacle.h"


void TittleInit(TitlleMaterial& material)
{
	//フラグ初期化
	material.excellentFlg = false;
	material.goodFlg = false;
	//画像読み込み
	material.excellentImg = LoadGraph("img/backimg/excellent.png", TRUE);
	material.goodImg = LoadGraph("img/backimg/nice.png", TRUE);
	//カウンター初期化
	material.excellentFlgCounter = 0;
	material.goodFlgCounter = 0;
	material.jumpCounter = 3;
}

void TittleUpdate(Player* ply, Obstacle* obstacle,int fps, TitlleMaterial& material)
{
	//プレイヤーの座標設定
	MV1SetPosition(ply->modelHandle, ply->pos);
	//障害物座標の増加
	obstacle->pos.z -= obstacle->moveSpeed;
	//障害物の座標設定
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);

	//自動ジャンプ処理(3回に1回エクセレント)
	if (material.jumpCounter % 3 == 0)
	{
		if (obstacle->pos.z < ply->pos.z + 30 && ply->jumpFlg == false)
		{
			ply->jumpFlg = true;
			//ジャンプ係数を設定
			ply->jumpCoefficient = JUMP;
			//ジャンプ音再生
			PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
			//エフェクトのフラグを立てる
			material.excellentFlg = true;
			//カウンターにfpsを保持
			material.excellentFlgCounter = fps;
			material.jumpCounter++;
		}
	}
	else
	{
		if(obstacle->pos.z < ply->pos.z + 45 && ply->jumpFlg == false)
		{
			ply->jumpFlg = true;
			//ジャンプ係数を設定
			ply->jumpCoefficient = JUMP;
			//ジャンプ音再生
			PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
			//エフェクトフラグを立てる
			material.goodFlg = true;
			//カウンターにfpsを保持
			material.goodFlgCounter = fps;
			material.jumpCounter++;
		}
	}

	//ジャンプ処理
	if (ply->jumpFlg == true)
	{
		//座標移動
		ply->pos.y += ply->jumpCoefficient;
		//地面にめり込んでいないかの確認
		if (ply->pos.y < 0.0f)
		{
			ply->pos.y = 0.0f;
			ply->jumpFlg = false;
		}
		//ジャンプ係数を下げる
		if (fps % 4 == 0)
		{
			ply->jumpCoefficient -= GRAVITY;
		}
	}
	//障害物座標初期化
	if (obstacle->pos.z <= -20.0)
	{
		obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
	}

	//カウンターが1秒分経過したらフラグとカウンター初期化
	if (material.excellentFlgCounter + 60 == fps)
	{
		material.excellentFlg = false;
		material.excellentFlgCounter = 0;
	}
	if (material.goodFlgCounter + 60 == fps)
	{
		material.goodFlg = false;
		material.goodFlgCounter = 0;
	}
	
}

void TittleEffectDraw(TitlleMaterial& material)
{
	//立ってるフラグに応じて判定を描画
	if (material.excellentFlg == true)
	{
		DrawExtendGraph(400, 125, 800, 350, material.excellentImg, TRUE);
	}
	if (material.goodFlg == true)
	{
		DrawExtendGraph(400, 125, 800, 350, material.goodImg, TRUE);
	}
}

void TittleTextDraw(bool flg)
{
	//タイトル画面のテキスト描画
	SetFontSize(100);
	if (flg == true)
	{
		DrawString(210, 50, "spaceでスタート", GetColor(255, 0, 0));
	}
	SetFontSize(55);
	DrawString(310, 350, "ギリギリで避けろ", GetColor(0, 0, 255));
}