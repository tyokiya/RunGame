#pragma once
#define IMG_MOVE_SPEED 10.0f
#define BARD_IMG_SIZE 75
//�w�i�摜�\����
struct BackGround
{
	int backImg;					//�w�i�摜�n���h��
	int roadImg;					//���摜�n���h��
	int cloudImg[2];				//�_�̉摜�n���h��
	int bardImg;					//���摜�n���h��
	float bardImgX, bardImgY;		//���摜�n���h�����W
	int resultBackImg;				//���U���g�w�i�摜�n���h��
	float cloudImgX, cloudImgY;		//�_�摜�̍��W
};

/// <summary>
/// �w�i�摜������
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
void BackGroundInit(BackGround* back);

/// <summary>
/// �w�i�摜�X�V
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
void BackGroundUpdate(BackGround* back);

/// <summary>
/// �w�i�摜�`��
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
void BackGroundDraw(BackGround* back);

/// <summary>
/// �Q�[���J�n�O�J�E���g�_�E��
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
/// <param name="starflg">�Q�[���J�n�t���O</param>
void CountDown(int fps,bool& starflg);