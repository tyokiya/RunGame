#include "DxLib.h"
#include "timer.h"	


void TimerInit(Timer* timer)
{
	//制限時間初期化
	timer->timeLimit = TIMELIMIT;
	//画像読み込み
	timer->timerImg = LoadGraph("img/backimg/timer.png", TRUE);
	//フラグ初期化
	timer->timeOverFlg = false;
	//カウント初期化
	timer->timeOverFrameCnt = 0;
}

void TimerCountDown(Timer* timer,int fps)
{
	
	//1秒ごとにカウントダウン
	if (fps % 60 == 0)
	{
		timer->timeLimit --;
	}
}

void TimerDraw(Timer* timer)
{
	SetFontSize(45);
	//残り時間表示(残り時間10は赤で表示)
	if (timer->timeLimit <= 10)
	{
		DrawFormatString(1100, 15, GetColor(255, 0, 0), "%d", timer->timeLimit);
	}
	else
	{
		DrawFormatString(1100, 15, GetColor(0, 0, 0), "%d", timer->timeLimit);
	}
	//時計画像表示
	DrawExtendGraph(1050, 15, 1050 + TIMER_IMG_SIZE, 15 + TIMER_IMG_SIZE, timer->timerImg, TRUE);
}