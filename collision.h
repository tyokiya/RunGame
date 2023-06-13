#pragma once
#include "DxLib.h"

struct Player;
struct Obstacle;
struct Sucore;

struct  CollisionCircle
{
	VECTOR pos;						//�����蔻��~�̒��S���W
	bool hitFlg;					//�Փ˃t���O
	float radius;					//�����蔻��̔��a
};

/// <summary>
/// �����蔻��~�̍��W������
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
/// <param name="setposition">�Z�b�g������W</param>
/// <param name="radius">�Z�b�g���锼�a</param>
void CollisionCircleInit(CollisionCircle* circle, VECTOR setposition,float radius);

/// <summary>
/// �͂��̓����蔻��~�̍��W������
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
/// <param name="setposition">�Z�b�g������W</param>
/// <param name="radius">�Z�b�g���锼�a</param>
void CollisionBeeCircleInit(CollisionCircle* circle, VECTOR setposition, float radius);

/// <summary>
/// �v���C���[�̓����蔻����W�ړ�
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
/// <param name="setposition">���W�̈ړ�����</param>
void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient);

/// <summary>
/// ��Q���̓����蔻��ړ�
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
/// <param name="setposition">���W�̈ړ�����</param>
void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveDistance);

/// <summary>
/// ��Q���̓����蔻�苅�`��(�e�X�g�p)
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
void CollisionCircleDraw(CollisionCircle* circle, int radius);

/// <summary>
/// �v���C���[�Ə�Q���̏Փ˔���
/// </summary>
/// <param name="plyCircle">�v���C���[�̓����蔻�蔻��\���̂̃|�C���^</param>
/// <param name="obstacleCircle">��Q���̓����蔻�蔻��\���̂̃|�C���^</param>
/// <param name="ply">�v���C���[�̍\���̂̃|�C���^</param>
/// <param name="obstacle">��Q���̍\���̂̃|�C���^</param>
/// <param name="sucore">���_�̍\���̂̃|�C���^</param>
void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore);