#include "DxLib.h"
#include "sucore.h"
#include "player.h"

void SucoreInit(Sucore* sucore)
{
	sucore->nowScore = 0;
	//�摜�̓ǂݍ���
	LoadDivGraph("img/sucore/number.png", 70, 10, 7, 337.7, 346.7, sucore->sucoreImgHandl);
	sucore->excellentImg = LoadGraph("img/backimg/excellent.png", TRUE);
	sucore->goodImg = LoadGraph("img/backimg/nice.png", TRUE);
	//�t���O������
	sucore->drawFlg = false;
	//�J�E���g������
	sucore->drawCnt = 0;
	//���ʉ��ݒ�
	sucore->sucoreSound = LoadSoundMem("sound/player/getSound.wav");
}	

void GetSucoreInit(Sucore* sucore)
{
	sucore->getScore = 0;
}

void SucoreAdd(Sucore* sucore, float distanceBornus)
{
	//�X�R�A�A�b�v�̊m�F
	if (distanceBornus <= 40.0f)
	{
		sucore->getScore = BORNUS_SUCORE;
	}
	else
	{
		sucore->getScore = NORMAL_SUCORE;
	}
	//���_�̉��Z
	sucore->nowScore += sucore->getScore;
	//�`��t���O�𗧂Ă�
	sucore->drawFlg = true;
	//���ʉ��Đ�
	PlaySoundMem(sucore->sucoreSound, DX_PLAYTYPE_BACK);
}

void GetSucoreDraw(Sucore* sucore)
{
	//�`��t���O�����Ă�����`��
  	if (sucore->drawFlg == true)
	{
		if (sucore->getScore == NORMAL_SUCORE)
		{
			//�X�R�A�摜�̕`��
			for (int i = 0; i < 3; i++)
			{
				DrawExtendGraph(160, 400 - (sucore->drawCnt * 10), 260, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[61], TRUE);
				DrawExtendGraph(210, 400 - (sucore->drawCnt * 10), 310, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
				DrawExtendGraph(260, 400 - (sucore->drawCnt * 10), 360, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
			}
			//�e�L�X�g�摜�`��
			DrawExtendGraph(400, 0, 800, 225, sucore->goodImg, TRUE);
		}
		else if (sucore->getScore == BORNUS_SUCORE)
		{
			//�X�R�A�摜�̕`��
			for (int i = 0; i < 3; i++)
			{
				DrawExtendGraph(160, 400 - (sucore->drawCnt * 10), 260, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[63], TRUE);
				DrawExtendGraph(210, 400 - (sucore->drawCnt * 10), 310, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
				DrawExtendGraph(260, 400 - (sucore->drawCnt * 10), 360, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
			}
			//�e�L�X�g�摜�`��
			DrawExtendGraph(400, 0, 800, 225, sucore->excellentImg, TRUE);
		}
		//�J�E���g�ǉ�
		sucore->drawCnt++;
	}
	
	if (sucore->drawCnt == 30)
	{
		//�`��t���O������
		sucore->drawFlg = false;
		//�J�E���g������
		sucore->drawCnt = 0;
		//�l���X�R�A�̏������@
		GetSucoreInit(sucore);
	}
}

void TotalSucoreDraw(Sucore* sucore)
{
	int n1, n2, n3, n4;
	//�ꌅ������̐����Ƃ�
	n1 = sucore->nowScore % 10;
	n2 = sucore->nowScore % 100 / 10;
	n3 = sucore->nowScore % 1000 / 100;
	n4 = sucore->nowScore % 10000 / 1000;
	//0�s���Ȃ����߂̏���
	if (n1 < 0){
		n1 = 0;}
	if (n2 < 0){
		n2 = 0;}
	if (n3 < 0){
		n3 = 0;}
	if (n4 < 0){
		n4 = 0;}

	//�ꌅ������̕`��
	DrawExtendGraph(10, 20, 50, 60, sucore->sucoreImgHandl[n4 + 60], TRUE);
	DrawExtendGraph(40, 20, 80, 60, sucore->sucoreImgHandl[n3 + 60], TRUE);
	DrawExtendGraph(70, 20, 110, 60, sucore->sucoreImgHandl[n2 + 60], TRUE);
	DrawExtendGraph(100, 20, 140, 60, sucore->sucoreImgHandl[n1 + 60], TRUE);
}

void SucoreDown(Sucore* sucore)
{
	//�X�R�A�̌��_
	if (sucore->nowScore > 1)
	{
		sucore->nowScore -= DOWN_SUCORE;
	}
	//0�����ɂȂ�Ȃ��悤�ɂ���
	if (sucore->nowScore < 0)
	{
		sucore->nowScore = 0;
	}
}