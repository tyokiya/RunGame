#include "DxLib.h"
#include "result.h"
#include "player.h"
#include "background.h"
#include "sucore.h"

void ResultPlayerInit(Player* ply)
{
	//回転値のセット
	MV1SetRotationXYZ(ply->modelHandle, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
}

void ResultUpdate(bool& flg, int fps)
{
	//スコアの点滅フラグを切り替え
	if (fps % 20 == 0)
	{
		if (flg == true)
		{
			flg = false;
		}
		else
		{
			flg = true;
		}
	}
}

void ResultDraw(BackGround* back, Sucore* sucore, bool flg)
{
	int n1, n2, n3, n4;
	//一桁当たりの数をとる
	n1 = sucore->nowScore % 10;
	n2 = sucore->nowScore % 100 / 10;
	n3 = sucore->nowScore % 1000 / 100;
	n4 = sucore->nowScore % 10000 / 1000;
	//0未満にならないための処理
	if (n1 < 0) {
		n1 = 0;
	}
	if (n2 < 0) {
		n2 = 0;
	}
	if (n3 < 0) {
		n3 = 0;
	}
	if (n4 < 0) {
		n4 = 0;
	}

	//背景描画
	DrawExtendGraph(0, 0, 1200, 800, back->resultBackImg, true);
	//スコア表示
	if (flg == true)
	{
		////一桁当たりの描画
		//DrawRotaGraph(300, 300, 1, 0, sucore->sucoreImgHandl[n4 + 60], TRUE,FALSE);
		//DrawRotaGraph(490, 300, 1, 0, sucore->sucoreImgHandl[n3 + 60], TRUE,FALSE);
		//DrawRotaGraph(680, 300, 1, 0, sucore->sucoreImgHandl[n2 + 60], TRUE,FALSE);
		//DrawRotaGraph(870, 300, 1, 0, sucore->sucoreImgHandl[n1 + 60], TRUE,FALSE);

		DrawExtendGraph(300, 300, 640, 640, sucore->sucoreImgHandl[n4 + 60], TRUE);
		DrawExtendGraph(490, 300, 830, 640, sucore->sucoreImgHandl[n3 + 60], TRUE);
		DrawExtendGraph(680, 300, 1020, 640, sucore->sucoreImgHandl[n2 + 60], TRUE);
		DrawExtendGraph(870, 300, 1210, 640, sucore->sucoreImgHandl[n1 + 60], TRUE);
	}
	
}