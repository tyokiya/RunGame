#pragma once
#define SHADOW_ANIMETION_COUNT 2		//�e�摜�A�j���[�V������
#define SHADOW_SIZE_X 250				//�e�摜�T�C�Yx
#define SHADOW_SIZE_Y 100				//�e�摜�T�C�Yy

struct Shadow
{
	float x, y;			//���W
	int img[SHADOW_ANIMETION_COUNT];			//�摜�n���h��
};

/// <summary>
/// �e�摜������
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
void ShadowInit(Shadow* shadow);

/// <summary>
/// �e�摜�`��
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
/// <param name="jumpFlg">�v���C���[�̃W�����v�t���O</param>
void ShadowDraw(Shadow* shadow, bool jumpFlg);
