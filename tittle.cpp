#include "DxLib.h"
#include "tittle.h"
#include "player.h"
#include "obstacle.h"


void TittleUpdate(Player* ply, Obstacle* obstacle,int fps)
{
	//�v���C���[�̍��W�ݒ�
	MV1SetPosition(ply->modelHandle, ply->pos);
	//��Q�����W�̑���
	obstacle->pos.z -= obstacle->moveSpeed;
	//��Q���̍��W�ݒ�
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);
	//�����W�����v����
	if (obstacle->pos.z < ply->pos.z + 30 && ply->jumpFlg == false)
	{
		ply->jumpFlg = true;
		//�W�����v�W����ݒ�
		ply->jumpCoefficient = JUMP;
		//�W�����v���Đ�
		PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
	}
	//�W�����v����
	if (ply->jumpFlg == true)
	{
		//���W�ړ�
		ply->pos.y += ply->jumpCoefficient;
		//�n�ʂɂ߂荞��ł��Ȃ����̊m�F
		if (ply->pos.y < 0.0f)
		{
			ply->pos.y = 0.0f;
			ply->jumpFlg = false;
		}
		//�W�����v�W����������
		if (fps % 2 == 0)
		{
			ply->jumpCoefficient -= GRAVITY;
		}
	}
	//��Q�����W������
	if (obstacle->pos.z <= -20.0)
	{
		//���x�̃����_������
		obstacle->moveSpeed = ((rand() % 40 + 1) + 10) / 10;
		obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
	}
}

void TittleTextDraw(bool flg)
{
	//�^�C�g����ʂ̃e�L�X�g�`��
	SetFontSize(100);
	if (flg == true)
	{
		DrawString(210, 50, "space�ŃX�^�[�g", GetColor(255, 0, 0));
	}
	SetFontSize(55);
	DrawString(310, 350, "�M���M���Ŕ�����", GetColor(100, 0, 255));
}