#include "DxLib.h"
#include "background.h"
#include <stdlib.h>
#include <time.h>

void BackGroundInit(BackGround* back)
{
	//背景設定
	back->backImg = LoadGraph("img/backImg/blue.jpg");
	back->resultBackImg = LoadGraph("img/backImg/resultBack.png");
	//道画像設定
	back->roadImg = LoadGraph("img/backImg/gras.jpg");
	//鳥画像設定
	back->bardImg = LoadGraph("img/backImg/bard.png");

	//雲画像設定
	for (int i = 0; i < 2; i++)
	{
		back->cloudImg[i] = LoadGraph("img/backImg/cloud.png");
	}

	//雲座標設定
	back->cloudImgX[0] = CLOUD_POS_X;
	back->cloudImgY[0] = CLOUD_POS_Y;
	back->cloudImgX[1] = 400;
	back->cloudImgY[1] = 100;
	//鳥の座標せってい
	back->bardImgX = 1200;
	back->bardImgY = 100;
	
}

void BackGroundUpdate(BackGround* back)
{
	srand((unsigned int)time(NULL));
	//鳥画像移動
	back->bardImgX -= BARD_MOVE_SPEED;
	for (int i = 0; i < 2; i++)
	{
		//雲の移動
		back->cloudImgX[i] -= CLOUD_MOVE_SPEED;
	}
	
	//画面外に出たら座標リセット
	for (int i = 0; i < 2; i++)
	{
		if (back->cloudImgX[i] + CLOUD_IMG_SIZEE_X < 0)
		{
			back->cloudImgX[i] = CLOUD_POS_X;
			back->cloudImgY[i] = rand() % 15 * 10;
		}
	}
	if (back->bardImgX + BARD_IMG_SIZE < 0)
	{
		back->bardImgX = rand() % 5 * 100 + 1300;
		back->bardImgY = rand() % 4 * 100;
	}
	

}

void BackGroundDraw(BackGround* back)
{
	DrawExtendGraph(0, 0, 1200, 800, back->backImg, true);
	DrawExtendGraph(0, 600, 1200, 800, back->roadImg, true);
	for (int i = 0; i < 2; i++)
	{
		DrawExtendGraph(back->cloudImgX[i], back->cloudImgY[i], back->cloudImgX[i] + CLOUD_IMG_SIZEE_X, back->cloudImgY[i] + CLOUD_IMG_SIZEE_Y, back->cloudImg[i], true);
	}
	DrawExtendGraph(back->bardImgX, back->bardImgY, back->bardImgX + BARD_IMG_SIZE, back->bardImgY + BARD_IMG_SIZE, back->bardImg, true);
}

void CountDown(int fps,bool& startflg)
{
	SetFontSize(200);
	if (fps < 60)
	{
		DrawFormatString(500, 300, GetColor(255, 0, 0), "3");
	}
	else if (fps < 120)
	{
		DrawFormatString(500, 300, GetColor(255, 0, 0), "2");
	}
	else if (fps < 180)
	{
		DrawFormatString(500, 300, GetColor(255, 0, 0), "1");
	}
	else if (fps < 200)
	{
		DrawFormatString(250, 200, GetColor(255, 0, 0), "スタート");
	}
	else
	{
		startflg = true;
	}
}