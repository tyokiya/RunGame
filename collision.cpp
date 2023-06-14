#include"DxLib.h"
#include "collision.h"
#include "player.h"
#include "obstacle.h"
#include "sucore.h"
#include <math.h>

void CollisionCircleInit(CollisionCircle* circle, VECTOR setposition, float radius)
{
	//���W�̃Z�b�g
	circle->pos = setposition;
	//�t���O�̂��傫��
	circle->hitFlg = false;
	//���a�̃Z�b�g
	circle->radius = radius;
}

void CollisionBeeCircleInit(CollisionCircle* circle, VECTOR setposition, float radius)
{
	//���W�̃Z�b�g
	circle->pos = setposition;
	//���W�̔�����
	circle->pos.y += 10.0f;
	//�t���O�̂��傫��
	circle->hitFlg = false;
	//���a�̃Z�b�g
	circle->radius = radius;
}

void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient)
{
	circle->pos.y += jumpCoefficient;
}

void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveSpeed)
{
	circle->pos.z -= moveSpeed;
}

void CollisionCircleDraw(CollisionCircle* circle,int radius)
{
	DrawSphere3D(circle->pos, radius, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore)
{
	//�O�����̒藝�ŏՓ˔���
	if (sqrt(pow(obstacleCircle->pos.x - plyCircle->pos.x, 2)
		+ pow(obstacleCircle->pos.y - plyCircle->pos.y, 2)
		+ pow(obstacleCircle->pos.z - plyCircle->pos.z, 2))
		< plyCircle->radius + obstacleCircle->radius)
	{
		//�����t���O������
		ply->displayFlg = false;
		obstacle->displayFlg = false;
		//�X�R�A�̌��_
		SucoreDown(sucore);
		//���S�T�E���h�Đ�
		PlaySoundMem(ply->deatSound, DX_PLAYTYPE_BACK);
	}
}

