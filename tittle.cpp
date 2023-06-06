#include "DxLib.h"
#include "tittle.h"
#include "player.h"
#include "obstacle.h"


void TittleUpdate(Player* ply, Obstacle* obstacle,int fps)
{
	//プレイヤーの座標設定
	MV1SetPosition(ply->modelHandle, ply->pos);
	//障害物座標の増加
	obstacle->pos.z -= obstacle->moveSpeed;
	//障害物の座標設定
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);
	//自動ジャンプ処理
	if (obstacle->pos.z < ply->pos.z + 30 && ply->jumpFlg == false)
	{
		ply->jumpFlg = true;
		//ジャンプ係数を設定
		ply->jumpCoefficient = JUMP;
		//ジャンプ音再生
		PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
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
		if (fps % 2 == 0)
		{
			ply->jumpCoefficient -= GRAVITY;
		}
	}
	//障害物座標初期化
	if (obstacle->pos.z <= -20.0)
	{
		//速度のランダム生成
		obstacle->moveSpeed = ((rand() % 40 + 1) + 10) / 10;
		obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
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
	DrawString(310, 350, "ギリギリで避けろ", GetColor(100, 0, 255));
}