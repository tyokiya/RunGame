#include "DxLib.h"
#include "tittle.h"
#include "player.h"
#include "obstacle.h"


void TittleInit(TitlleMaterial& material)
{
	//�t���O������
	material.excellentFlg = false;
	material.goodFlg = false;
	//�摜�ǂݍ���
	material.excellentImg = LoadGraph("img/backimg/excellent.png", TRUE);
	material.goodImg = LoadGraph("img/backimg/nice.png", TRUE);
	//�J�E���^�[������
	material.excellentFlgCounter = 0;
	material.goodFlgCounter = 0;
	material.jumpCounter = 3;
}

void TittleUpdate(Player* ply, Obstacle* obstacle,int fps, TitlleMaterial& material)
{
	//�v���C���[�̍��W�ݒ�
	MV1SetPosition(ply->modelHandle, ply->pos);
	//��Q�����W�̑���
	obstacle->pos.z -= obstacle->moveSpeed;
	//��Q���̍��W�ݒ�
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);

	//�����W�����v����(3���1��G�N�Z�����g)
	if (material.jumpCounter % 3 == 0)
	{
		if (obstacle->pos.z < ply->pos.z + 30 && ply->jumpFlg == false)
		{
			ply->jumpFlg = true;
			//�W�����v�W����ݒ�
			ply->jumpCoefficient = JUMP;
			//�W�����v���Đ�
			PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
			//�G�t�F�N�g�̃t���O�𗧂Ă�
			material.excellentFlg = true;
			//�J�E���^�[��fps��ێ�
			material.excellentFlgCounter = fps;
			material.jumpCounter++;
		}
	}
	else
	{
		if(obstacle->pos.z < ply->pos.z + 45 && ply->jumpFlg == false)
		{
			ply->jumpFlg = true;
			//�W�����v�W����ݒ�
			ply->jumpCoefficient = JUMP;
			//�W�����v���Đ�
			PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
			//�G�t�F�N�g�t���O�𗧂Ă�
			material.goodFlg = true;
			//�J�E���^�[��fps��ێ�
			material.goodFlgCounter = fps;
			material.jumpCounter++;
		}
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
		if (fps % 4 == 0)
		{
			ply->jumpCoefficient -= GRAVITY;
		}
	}
	//��Q�����W������
	if (obstacle->pos.z <= -20.0)
	{
		obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
	}

	//�J�E���^�[��1�b���o�߂�����t���O�ƃJ�E���^�[������
	if (material.excellentFlgCounter + 60 == fps)
	{
		material.excellentFlg = false;
		material.excellentFlgCounter = 0;
	}
	if (material.goodFlgCounter + 60 == fps)
	{
		material.goodFlg = false;
		material.goodFlgCounter = 0;
	}
	
}

void TittleEffectDraw(TitlleMaterial& material)
{
	//�����Ă�t���O�ɉ����Ĕ����`��
	if (material.excellentFlg == true)
	{
		DrawExtendGraph(400, 125, 800, 350, material.excellentImg, TRUE);
	}
	if (material.goodFlg == true)
	{
		DrawExtendGraph(400, 125, 800, 350, material.goodImg, TRUE);
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
	DrawString(310, 350, "�M���M���Ŕ�����", GetColor(0, 0, 255));
}