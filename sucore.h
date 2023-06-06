#pragma once
#define NORMAL_SUCORE 100			//�ʏ�̓��_
#define BORNUS_SUCORE 300			//�{�[�i�X���̓��_
#define SUCORE_IMG_NUM 70			//���_�C���[�W�̔z��
#define DOWN_SUCORE 150				//���_����_��

//���_�\����
struct Sucore
{
	int nowScore;				//���_
	int getScore;				//1�t���[���̊ԂɊl���������_
	int sucoreImgHandl[SUCORE_IMG_NUM];	//���_�̃C���[�W�n���h��
	bool drawFlg;						//�`��t���O
	int drawCnt;						//�`�掞�Ԃ̃J�E���g
	int sucoreSound;					//�l���T�E���h
	int excellentImg;					//�G�N�Z�����g�̃e�L�X�g�C���[�W�n���h��
	int goodImg;						//�O�b�h�̃e�L�X�g�C���[�W�n���h��
};

/// <summary>
/// �X�R�A������
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
void SucoreInit(Sucore* sucore);

/// <summary>
/// �l���X�R�A������
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
void GetSucoreInit(Sucore* sucore);

/// <summary>
/// �X�R�A����
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
/// <param name="distanceBornus">�����{�[�i�X</param>
void SucoreAdd(Sucore* sucore, float distanceBornus);

/// <summary>
/// �l���X�R�A�`��
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
void GetSucoreDraw(Sucore* sucore);

/// <summary>
/// �g�[�^���X�R�A�`��
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
void TotalSucoreDraw(Sucore* sucore);

/// <summary>
/// �X�R�A�̌��_
/// </summary>
/// <param name="sucore">���_����\���̂̃|�C���^</param>
void SucoreDow(Sucore* sucore);

