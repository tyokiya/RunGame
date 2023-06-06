#include "DxLib.h"
#include "result.h"
#include "player.h"
#include "background.h"
#include "sucore.h"

void ResultPlayerInit(Player* ply)
{
	//��]�l�̃Z�b�g
	MV1SetRotationXYZ(ply->modelHandle, VGet(0.0f, -90.0f * DX_PI_F / 180.0f, 0.0f));
}

void ResultDraw(BackGround* back, Sucore* sucore)
{
	int n1, n2, n3, n4;
	//�ꌅ������̐����Ƃ�
	n1 = sucore->nowScore % 10;
	n2 = sucore->nowScore % 100 / 10;
	n3 = sucore->nowScore % 1000 / 100;
	n4 = sucore->nowScore % 10000 / 1000;
	//0�����ɂȂ�Ȃ����߂̏���
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

	//�w�i�`��
	DrawExtendGraph(0, 0, 1200, 800, back->resultBackImg, true);
	//�X�R�A�\��
	//�ꌅ������̕`��
	DrawExtendGraph(300, 300, 640, 640, sucore->sucoreImgHandl[n4 + 60], TRUE);
	DrawExtendGraph(490, 300, 830, 640, sucore->sucoreImgHandl[n3 + 60], TRUE);
	DrawExtendGraph(680, 300, 1020, 640, sucore->sucoreImgHandl[n2 + 60], TRUE);
	DrawExtendGraph(870, 300, 1210, 640, sucore->sucoreImgHandl[n1 + 60], TRUE);
}