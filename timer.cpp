#include "DxLib.h"
#include "timer.h"	


void TimerInit(Timer* timer)
{
	//�������ԏ�����
	timer->timeLimit = TIMELIMIT;
	//�摜�ǂݍ���
	timer->timerImg = LoadGraph("img/backimg/timer.png", TRUE);
}

void TimerCountDown(Timer* timer,int fps)
{
	
	//1�b���ƂɃJ�E���g�_�E��
	if (fps % 60 == 0)
	{
		timer->timeLimit --;
	}
}

void TimerDraw(Timer* timer)
{
	SetFontSize(45);
	//�c�莞�ԕ\��(�c�莞��10�͐Ԃŕ\��)
	if (timer->timeLimit <= 10)
	{
		DrawFormatString(1100, 15, GetColor(255, 0, 0), "%d", timer->timeLimit);
	}
	else
	{
		DrawFormatString(1100, 15, GetColor(0, 0, 0), "%d", timer->timeLimit);
	}
	//���v�摜�\��
	DrawExtendGraph(1050, 15, 1050 + TIMER_IMG_SIZE, 15 + TIMER_IMG_SIZE, timer->timerImg, TRUE);
}