#pragma once
#include "DxLib.h"
#define RADIUS 10.0f

struct Player;
struct Obstacle;
struct Sucore;

struct  CollisionCircle
{
	VECTOR pos;						//�����蔻��~�̒��S���W
	bool hitFlg;					//�Փ˃t���O
};

/// <summary>
/// �����蔻��~�̍��W������
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
/// <param name="setposition">�Z�b�g������W</param>
void CollisionCircleInit(CollisionCircle* circle, VECTOR setposition);

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
/// ��Q���̓����蔻�苅�`��
/// </summary>
/// <param name="circle">�����蔻��\���̂̃|�C���^</param>
void CollisionCircleDraw(CollisionCircle* circle);

/// <summary>
/// �v���C���[�Ə�Q���̏Փ˔���
/// </summary>
/// <param name="plyCircle">�v���C���[�̓����蔻�蔻��\���̂̃|�C���^</param>
/// <param name="obstacleCircle">��Q���̓����蔻�蔻��\���̂̃|�C���^</param>
/// <param name="ply">�v���C���[�̍\���̂̃|�C���^</param>
/// <param name="obstacle">��Q���̍\���̂̃|�C���^</param>
/// <param name="sucore">���_�̍\���̂̃|�C���^</param>
void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore);