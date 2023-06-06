#include "DxLib.h"
#include "background.h"
#include <stdlib.h>
#include <time.h>

void BackGroundInit(BackGround* back)
{
	//背景設定
	back->backImg = LoadGraph("img/backImg/sky.jpg");
	back->resultBackImg = LoadGraph("img/backImg/resultBack.png");
	//道画像設定
	back->roadImg = LoadGraph("img/backImg/gras.jpg");
	//鳥画像設定
	back->bardImg = LoadGraph("img/backImg/bard.png");

	//鳥の座標せってい
	back->bardImgX = 1200;
	back->bardImgY = 100;
}

void BackGroundUpdate(BackGround* back)
{
	srand((unsigned int)time(NULL));
	//鳥画像移動
	back->bardImgX -= IMG_MOVE_SPEED;
	
	//画面外に出たら座標リセット
	if (back->bardImgX + BARD_IMG_SIZE < 0)
	{
		back->bardImgX = 1300;
		back->bardImgY = rand() % 4 * 100;
	}
}

void BackGroundDraw(BackGround* back)
{
	DrawExtendGraph(0, 0, 1200, 800, back->backImg, true);
	DrawExtendGraph(0, 600, 1200, 800, back->roadImg, true);
	DrawExtendGraph(back->bardImgX, back->bardImgY, back->bardImgX + BARD_IMG_SIZE, back->bardImgY+ BARD_IMG_SIZE, back->bardImg, true);
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