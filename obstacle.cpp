#include "obstacle.h"
#include <stdlib.h>
#include <time.h>
#include "collision.h"

void ObstacleInit(Obstacle* obstacle, int modelHandl)
{
	//3D���f���ǂݍ���
	obstacle->modelHandle = modelHandl;
	//���W�Z�b�g
	obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_INITIAL_POSY, OBSTACLE_INITIAL_POSZ);
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);
	//�g�嗦�Z�b�g
	MV1SetScale(obstacle->modelHandle, VGet(0.4f, 0.4f, 0.4f));
	//�t���O�𗧂Ă�
	obstacle->displayFlg = true;
	//���x������
	obstacle->moveSpeed = OBSTACLE_DEFOMOVE_SPEED;
}

void ObstacleBeeInit(Obstacle* obstacle, int modelHandl)
{
	//3D���f���ǂݍ���
	obstacle->modelHandle = modelHandl;
	//���W�Z�b�g
	obstacle->pos = VGet(OBSTACLE_INITIAL_POSX, OBSTACLE_BEE_POSY, OBSTACLE_INITIAL_POSZ);
	MV1SetPosition(obstacle->modelHandle, obstacle->pos);
	//�g�嗦�Z�b�g
	MV1SetScale(obstacle->modelHandle, VGet(0.1f, 0.1f, 0.1f));
	//�t���O�𗧂Ă�
	obstacle->displayFlg = true;
	//���x������
	obstacle->moveSpeed = OBSTACLE_BEE_SPEED;
}

void ObstacleUpdate(Obstacle* obstacle, CollisionCircle* collision)
{
	//�����_��������
	srand((unsigned int)time(NULL));
	
	//��Q���̍Đ���
	if (obstacle->displayFlg == false)
	{
		//�����������_������
		//int num = (rand() % 5 + 1) * 100;
		//�t���O�𗧂Ă�
		obstacle->displayFlg = true;
		//���W�̃Z�b�g
		obstacle->pos = VGet(0.0f, 0.0f, OBSTACLE_INITIAL_POSZ);
		//�����蔻��̍��W�Z�b�g
		CollisionCircleInit(collision, obstacle->pos);
		//���x�̃����_������
		obstacle->moveSpeed =((rand() % 40 + 1) + 10) / 10;
		//obstacle->moveSpeed = 
	}

	//�v���C���[�Ɍ������Ĉړ�
	if (obstacle->displayFlg == true)
	{
		//���W�̑���
		obstacle->pos.z -= obstacle->moveSpeed;
		//��Q���̍��W�ݒ�
		MV1SetPosition(obstacle->modelHandle, obstacle->pos);
		//�����蔻��̈ړ�
		ObstacleCollisionCircleMove(collision, obstacle->moveSpeed);
	}

	//��ʊO�ɂł����_�ŕ\���t���O�����낷
	if (obstacle->pos.z <= -20.0)
	{
		obstacle->displayFlg = false;
	}
}

void ObstacleBeeUpdate(Obstacle* obstacle, CollisionCircle* collision)
{
	//��Q���̍Đ���
	if (obstacle->displayFlg == false)
	{
		//�t���O�𗧂Ă�
		obstacle->displayFlg = true;
		//���W�̃Z�b�g
		obstacle->pos = VGet(0.0f, OBSTACLE_BEE_POSY, OBSTACLE_INITIAL_POSZ);
		//�����蔻��̍��W�Z�b�g
		CollisionBeeCircleInit(collision, obstacle->pos);
	}

	//�v���C���[�Ɍ������Ĉړ�
	if (obstacle->displayFlg == true)
	{
		//���W�̑���
		obstacle->pos.z -= obstacle->moveSpeed;
		//��Q���̍��W�ݒ�
		MV1SetPosition(obstacle->modelHandle, obstacle->pos);
		//�����蔻��̈ړ�
		ObstacleCollisionCircleMove(collision, obstacle->moveSpeed);
	}

	//��ʊO�ɂł����_�ŕ\���t���O�����낷
	if (obstacle->pos.z <= -20.0)
	{
		obstacle->displayFlg = false;
	}
}

void ObstacleDraw(Obstacle* obstacle)
{
	//�`��(�t���O�������Ă���ꍇ�̂�)
	if (obstacle->displayFlg == true)
	{
		MV1DrawModel(obstacle->modelHandle);
	}
}