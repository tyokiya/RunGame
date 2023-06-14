#include "DxLib.h"
#include "background.h"
#include <stdlib.h>
#include <time.h>

void BackGroundInit(BackGround* back)
{
	//�w�i�ݒ�
	back->backImg = LoadGraph("img/backImg/blue.jpg");
	back->resultBackImg = LoadGraph("img/backImg/resultBack.png");
	//���摜�ݒ�
	back->roadImg = LoadGraph("img/backImg/gras.jpg");
	//���摜�ݒ�
	back->bardImg = LoadGraph("img/backImg/bard.png");

	//�_�摜�ݒ�
	back->cloudImg = LoadGraph("img/backImg/cloud.png");
	//�_���W�ݒ�
	back->cloudImgX = CLOUD_POS_X;
	back->cloudImgY = CLOUD_POS_Y;

	//���̍��W�����Ă�
	back->bardImgX = 1200;
	back->bardImgY = 100;
}

void BackGroundUpdate(BackGround* back)
{
	srand((unsigned int)time(NULL));
	//���摜�ړ�
	back->bardImgX -= IMG_MOVE_SPEED;
	
	//��ʊO�ɏo������W���Z�b�g
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
		DrawFormatString(250, 200, GetColor(255, 0, 0), "�X�^�[�g");
	}
	else
	{
		startflg = true;
	}
}