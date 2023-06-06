#include"DxLib.h"
#include "collision.h"
#include "player.h"
#include "obstacle.h"
#include "sucore.h"

void CollisionCircleInit(CollisionCircle* circle,VECTOR setposition) 
{
	//���W�̃Z�b�g
	circle->pos = setposition;
	//�t���O�̂��傫��
	circle->hitFlg = false;
}

void PlayerCollisionCircleMove(CollisionCircle* circle, float jumpCoefficient)
{
	circle->pos.y += jumpCoefficient;
}

void ObstacleCollisionCircleMove(CollisionCircle* circle, float moveSpeed)
{
	circle->pos.z -= moveSpeed;
}

void CollisionCircleDraw(CollisionCircle* circle)
{
	DrawSphere3D(circle->pos, RADIUS, 32, GetColor(255, 0, 0), GetColor(255, 255, 255), TRUE);
}

void CollisionJudgement(CollisionCircle* plyCircle, CollisionCircle* obstacleCircle, Player* ply, Obstacle* obstacle, Sucore* sucore)
{
	//���ꂼ��̍��W�̋������ׂĔ��a��菬�����Ȃ�����q�b�g����
	if (plyCircle->pos.x + obstacleCircle->pos.x < (RADIUS * 2)
	 && plyCircle->pos.y + obstacleCircle->pos.y < (RADIUS * 2)
	 && plyCircle->pos.z + obstacleCircle->pos.z < (RADIUS * 2))
	{
		//�����t���O������
		ply->displayFlg = false;
		obstacle->displayFlg = false;
		//�X�R�A�̌��_
		SucoreDow(sucore);
		//���S�T�E���h�Đ�
		PlaySoundMem(ply->deatSound, DX_PLAYTYPE_BACK);
	}
}