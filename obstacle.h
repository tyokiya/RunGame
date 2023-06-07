#pragma once
#include "DxLib.h"
#define OBSTACLE_DEFOMOVE_SPEED 1.8
#define OBSTACLE_BEE_SPEED 1.5
#define OBSTACLE_INITIAL_POSX 0.0f
#define OBSTACLE_INITIAL_POSY 0.0f
#define OBSTACLE_INITIAL_POSZ 200.0f
#define OBSTACLE_BEE_POSY 65.0f
#define OBSTACLE_RADIUS 10.0f
#define OBSTACLE_BEE_RADIUS 8.0f

struct  CollisionCircle;

//��Q���̍\����
struct Obstacle
{
	int	modelHandle;		//���f���n���h��
	VECTOR pos;				//��Q���̍��W
	bool displayFlg;		//�\���t���O
	float moveSpeed;		//�ړ����x
};

/// <summary>
/// ��Q���̏�����
/// </summary>
/// <param name="obstacle">��Q���̍\���̃|�C���^</param>
/// <param name="modelHandl">�ǂݍ��܂���摜�n���h��</param>
void ObstacleInit(Obstacle* obstacle,int modelHandl);

/// <summary>
/// �͂���Q���̏�����
/// </summary>
/// <param name="obstacle">��Q���̍\���̃|�C���^</param>
/// <param name="modelHandl">�ǂݍ��܂���摜�n���h��</param>
void ObstacleBeeInit(Obstacle* obstacle, int modelHandl);

/// <summary>
/// ��Q���̏��X�V
/// </summary>
/// <param name="obstacle">��Q���̍\���̃|�C���^</param>
/// <param name="collision">�����蔻��̍\���̃|�C���^</param>
void ObstacleUpdate(Obstacle* obstacle, CollisionCircle* collision);

/// <summary>
/// �͂���Q���̏��X�V
/// </summary>
/// <param name="obstacle">��Q���̍\���̃|�C���^</param>
/// <param name="collision">�����蔻��̍\���̃|�C���^</param>
void ObstacleBeeUpdate(Obstacle* obstacle, CollisionCircle* collision);

/// <summary>
/// ��Q���̕`��
/// </summary>
/// <param name="obstacle">��Q���̍\���̃|�C���^</param>
void ObstacleDraw(Obstacle* obstacle);


