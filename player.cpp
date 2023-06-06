#include"DxLib.h"
#include"player.h"
#include "collision.h"
#include"obstacle.h"
#include "sucore.h"

void PlayerInit(Player* ply)
{
	//3D���f���̓ǂݍ���
	ply->modelHandle = MV1LoadModel("img/player/Character2.mv1");
	//3D���f���̈��k
	MV1SetScale(ply->modelHandle, VGet(0.1f, 0.1f, 0.1f));
	//���W�̃Z�b�g
	ply->pos = VGet(0.0f, 0.0f, 0.0f);
	//�v���C���[�̉�]�l���Z�b�g(180�x)
	MV1SetRotationXYZ(ply->modelHandle, VGet(0.0f, 180.0f * DX_PI_F / 180.0f, 0.0f));
	//�t���O������
	ply->jumpFlg = false;
	ply->jumpBtnPrevPress = false;
	ply->displayFlg = true;
	ply->pointFlg = false;
	ply->reviveFlg = false;
	//�l�̏�����
	ply->jumpBtnPrevPressCnt = 0;
	ply->obstacleDistance = 0;

	//�T�E���h������
	ply->jumpSound = LoadSoundMem("sound/player/se_jump.wav");
	ply->deatSound = LoadSoundMem("sound/player/death.mp3");

	//�G�t�F�N�g������
	LoadDivGraph("effect/pipo-mapeffect005.png", 10, 10, 1, 360, 360, ply->DamageEffect);
	//�G�t�F�N�g�J�E���g������
	ply->effectCnt = 0;
}

void PlayerUpdata(Player* ply, int fps,CollisionCircle* collision,Obstacle* obstacle, Sucore* sucore)
{
	//�����t���O
	//ply->displayFlg = true;

	//�v���C���[�̍��W�ݒ�
	MV1SetPosition(ply->modelHandle, ply->pos);
	//�L�[�ǂݍ���
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ply->jumpFlg == false)
	{
		//�t���O�𗧂Ă�
		ply->jumpFlg = true;
		//�W�����v�W����ݒ�
		ply->jumpCoefficient = JUMP;
		//1�t���O�̉����t���O�𗧂Ă�
		ply->jumpBtnPrevPress = true;
		//�W�����v���̃v���C���[�Ə�Q���̋���
		ply->obstacleDistance = obstacle->pos.z - ply->pos.z;
		//�W�����v���Đ�
		PlaySoundMem(ply->jumpSound, DX_PLAYTYPE_BACK);
	}
	//�������̊m�F
	if (CheckHitKey(KEY_INPUT_SPACE) == 1 && ply->jumpBtnPrevPress == true && ply->jumpBtnPrevPressCnt < JUMPMAXPEWER)
	{
		//�J�E���g����
		ply->jumpBtnPrevPressCnt++;
	}
	else
	{
		//�t���O������
		ply->jumpBtnPrevPress = false;
		//�J�E���g������
		ply->jumpBtnPrevPressCnt = 0;
	}
	//�W�����v����
	if (ply->jumpFlg == true )
	{
		PlayerJumpMove(ply, fps,collision);
	}

	//��Q�����ʂ�߂������𔻒�
	if (ply->jumpFlg == true && ply->pointFlg == false && obstacle->pos.z < ply->pos.z - 17.0f)
	{
		//�X�R�A�̒ǉ�����
		SucoreAdd(sucore, ply->obstacleDistance);
		//�X�R�A���l��������t���O�𗧂Ă�
		ply->pointFlg = true;
	}

	//�n�ʂɂ�����t���O������
	if (ply->pos.y == 0.0f)
	{
		ply->jumpFlg = false;
		//�W�����v�W����ݒ�
		ply->jumpCoefficient = 0.0f;
		//�|�C���g�t���O������
		ply->pointFlg = false;
	}
}

void PlayerJumpMove(Player* ply, int fps,CollisionCircle* collision)
{
	//���W�ړ�
	ply->pos.y += ply->jumpCoefficient;
	//�����蔻��̈ړ�
	PlayerCollisionCircleMove(collision ,ply->jumpCoefficient);
	
	//�n�ʂɂ߂荞��ł��Ȃ����̊m�F
	if (ply->pos.y < 0.0f)
	{
		ply->pos.y = 0.0f;
	}
	//�W�����v�W����������
	if (fps % 2 == 0 && ply->jumpBtnPrevPress == false)
	{
		ply->jumpCoefficient -= GRAVITY;
	}
}

void PlayerDraw(Player* ply)
{
	// �v���C���[�̕`��
	MV1DrawModel(ply->modelHandle);
	//if (ply->displayFlg == true)
	//DrawSphere3D(VGet(ply->pos.x,ply->pos.y + 10.0f,ply->pos.z), 10.0f, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void PlayerDeathMotion(Player* ply, int fps)
{
	SetFontSize(200);
	VECTOR screenPos;
	if (ply->reviveFlg == false)
	{
		//�ړ�
		ply->pos.y += 4.0f;
		ply->pos.z -= 0.9f;
		//�v���C���[�̍��W�ݒ�
		MV1SetPosition(ply->modelHandle, ply->pos);
		//�v���C���[���f���̉�ʍ��W���擾
		screenPos = ConvWorldPosToScreenPos(ply->pos);
		//�G�t�F�N�g�`��
		DrawGraph(screenPos.x - 100, screenPos.y - 200, ply->DamageEffect[ply->effectCnt], TRUE);
		//�G�t�F�N�g�J�E���g����
		if (fps % 5 == 0 && ply->effectCnt != 10)
		{
			ply->effectCnt++;
		}
		//�~�X�`��
		DrawFormatString(400, 0, GetColor(255, 0, 0), "MISS");
	}
	else
	{
		//�ړ�
		ply->pos.y -= 4.0f;
		//�v���C���[�̍��W�ݒ�
		MV1SetPosition(ply->modelHandle, ply->pos);
		//�t���O�����Z�b�g
		if (ply->pos.y == 0)
		{
			ply->reviveFlg = false;
			ply->displayFlg = true;
		}
		//�G�t�F�N�g�J�E���g�������
		ply->effectCnt = 0;
	}
	//�����t���O�𗧂Ă�
	if (ply->pos.z < -20)
	{
		ply->reviveFlg = true;
		//���W���Z�b�g
		ply->pos = VGet(0.0f, 300.0f, 0.0f);
	}
}