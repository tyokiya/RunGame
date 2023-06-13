#pragma once
#include "DxLib.h"
#define GRAVITY 0.4f
#define JUMP 3.5f
#define JUMPMAXPEWER 15
#define PLYEFFECTCNT 10
#define PLAYER_RADIUS 10.0f

struct  CollisionCircle;
struct Obstacle;
struct Sucore;

//�v���C���[�\����
struct Player
{
	int	modelHandle;					//���f���n���h��
	VECTOR pos;							//�v���C���[�̍��W
	float obstacleDistance;				//�W�����v���̏�Q���Ƃ̋���
	bool jumpFlg;						//�W�����v�t���O
	float jumpCoefficient;				//�W�����v�͂̌W��
	bool jumpBtnPrevPress;				//1�t���O�̃W�����v�{�^���������
	int jumpBtnPrevPressCnt;			//1�t���O�̃W�����v�{�^��������Ԃ̃J�E���g
	bool displayFlg;					//�����t���O
	bool pointFlg;						//���_���l���������̃t���O
	bool reviveFlg;						//�����t���O
	int jumpSound;						//�W�����v��
	int deatSound;						//���S��
	int DamageEffect[PLYEFFECTCNT];				//�_���[�W�G�t�F�N�g
	int effectCnt;						//�G�t�F�N�g�J�E���g
};

/// <summary>
/// �v�����[�̏�����
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
void PlayerInit(Player* ply);

/// <summary>
/// �v�����[�̍X�V
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
/// <param name="fps">�t���[���J�E���g</param>
/// <param name="collision">�����蔻��̍\���̃|�C���^</param>
void PlayerUpdata(Player* ply, int fps, CollisionCircle* collision, Obstacle* obstacle, Sucore* sucore);

/// <summary>
/// �v�����[�̃W�����v����
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
/// <param name="collision">�����蔻��̍\���̃|�C���^</param>
void PlayerJumpMove(Player* ply, int fps, CollisionCircle* collision);

/// <summary>
/// �v�����[�̕`��
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
void PlayerDraw(Player* ply);

/// <summary>
/// �v�����[�̎��S���̓���
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
/// <param name="collision">�����蔻��̍\���̃|�C���^</param>
void PlayerDeathMotion(Player* ply, int fps, CollisionCircle* collision);