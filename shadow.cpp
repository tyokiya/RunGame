#include "DxLib.h"
#include "shadow.h"

void ShadowInit(Shadow* shadow)
{
	//�摜�ǂݍ���
	shadow->img[0] = LoadGraph("img/shadow/shadow1.png");
	shadow->img[1] = LoadGraph("img/shadow/shadow2.png");
	//�`����W�Z�b�g
	shadow->x = 140;
	shadow->y = 740;
}

void ShadowDraw(Shadow* shadow, bool jumpFlg)
{
	if (jumpFlg == false)
	{
		DrawExtendGraph(shadow->x, shadow->y, shadow->x + SHADOW_SIZE_X, shadow->y + SHADOW_SIZE_Y, shadow->img[0], TRUE);
	}
	else
	{
		DrawExtendGraph(shadow->x, shadow->y, shadow->x + SHADOW_SIZE_X, shadow->y + SHADOW_SIZE_Y, shadow->img[1], TRUE);
	}
}