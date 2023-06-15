#pragma once
#define BARD_MOVE_SPEED 10.0f
#define CLOUD_MOVE_SPEED 5.0f
#define BUSH_MOVE_SPEED 6.6f
#define BARD_IMG_SIZE 75
#define BUSH_IMG_SIGE 250
#define	CLOUD_IMG_SIZEE_X 384
#define	CLOUD_IMG_SIZEE_Y 216
#define CLOUD_POS_X 1400
#define CLOUD_POS_Y 150
//�w�i�摜�\����
struct BackGround
{
	int backImg;					//�w�i�摜�n���h��
	int roadImg;					//���摜�n���h��
	int bushImg;					//���摜�n���h��
	int cloudImg[2];				//�_�̉摜�n���h��
	int bardImg;					//���摜�n���h��
	float bardImgX, bardImgY;		//���摜�n���h�����W
	int resultBackImg;				//���U���g�w�i�摜�n���h��
	float cloudImgX[2], cloudImgY[2];		//�_�摜�̍��W
	float bushImgX, bushImgY;		//���摜���W
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