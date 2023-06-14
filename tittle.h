#pragma once

struct Obstacle;
struct Player;

struct TitlleMaterial
{
	int excellentImg;					//�G�N�Z�����g�̃e�L�X�g�C���[�W�n���h��
	int goodImg;						//�O�b�h�̃e�L�X�g�C���[�W�n���h��
	bool excellentFlg;					//�G�N�Z�����g�t���O
	bool goodFlg;						//�O�b�h�t���O
	int excellentFlgCounter;			//�G�N�Z�����g�t���O�J�E���^�[(����������fps��ۊ�)
	int goodFlgCounter;					//�O�b�h�t���O�J�E���^�[(����������fps��ۊ�)
	int jumpCounter;					//�W�����v�񐔂̃J�E���^�[
};

/// <summary>
/// �^�C�g��������
/// </summary>
/// <param name="material">�^�C�g���f�ލ\����</param>
void TittleInit(TitlleMaterial& material);

/// <summary>
/// �^�C�g����ʍX�V
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
/// <param name="obstacle">��Q���\���̂̃|�C���^</param>
/// <param name="fps">�t���[�����[�g�J�E���g</param>
void TittleUpdate(Player* ply, Obstacle* obstacle, int fps, TitlleMaterial& material);

void TittleEffectDraw(TitlleMaterial& material);

/// <summary>
/// �^�C�g���e�L�X�g�`��
/// </summary>
void TittleTextDraw(bool flg);