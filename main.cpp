#include "DxLib.h"
#include "player.h"
#include "obstacle.h"
#include "background.h"
#include "collision.h"
#include "sucore.h"
#include "timer.h"
#include "shadow.h"
#include "gameScene.h"
#include "tittle.h"
#include "result.h"

//-----------------------------------------------------------------------------
// @brief  ���C���֐�.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ��ʃ��[�h�̃Z�b�g
	SetGraphMode(1200, 800, 16);
	ChangeWindowMode(TRUE);
	SetUseLighting(TRUE);
	SetFontSize(45);

	// �c�w���C�u��������������
	if (DxLib_Init() == -1)
	{
		return -1;	// �G���[���N�����璼���ɏI��
	}

	// ��ʂ̍X�V���Ԃ̊Ǘ��p�ϐ�
	LONGLONG nowCount, prevCount;                      // �}�C�N���b(100������1�b�P�ʂŎ����擾)
	nowCount = prevCount = GetNowHiPerformanceCount();
	float fixedDeltaTime = 1.0f / 60.0f;               // 60����1�b = 0.01666...�b
	float waitFrameTime = 15500;                       // 16000�}�C�N���b = 16�~���b = 0.016�b

	int fps = 0;			//�t���[���J�E���g

	//���s0.1�`1000�܂ł��J�����̕`��͈͂Ƃ���
	SetCameraNearFar(0.1f, 1000.0f);
	//(90, 50, 20)�̎��_����(0, 45, 40)�̃^�[�Q�b�g������p�x�ɃJ������ݒu
	SetCameraPositionAndTarget_UpVecY(VGet(90, 50, 20), VGet(0, 45, 40));
	//////////////////////////////////////////
	/// �\���̐錾
	///////////////////////////////////////////
	//�v�����[
	Player ply;
	//��Q��
	Obstacle obstacle;			//�u���b�N��Q��
	Obstacle obstacleBee;		//�͂���Q��
	//�w�i�摜
	BackGround backGround;
	//�����蔻��
	CollisionCircle plyCollision;
	CollisionCircle obstacleCollision;
	CollisionCircle obstacleBeeCollision;
	//���_
	Sucore gameSucore;
	//�^�C�}�[
	Timer timer;
	//�e
	Shadow shadow;
	//���݂̃Q�[���V�[��
	GameScene nowGameScene;

	bool startFlg = false;					//�Q�[���J�n�t���O
	bool tittleTextFlg = false;				//�^�C�g���e�L�X�g�̃t���O
	bool timeOverFlg = false;				//���Ԑ؂�t���O
	int timeOverFrameCnt = 0;				//���Ԑ؂ꎞ�̃t���[����

	bool resultSucoreFlg = false;			//���U���g�̃X�R�A�`��t���O

	//////////////////////////////////////
	/// ����������
	/////////////////////////////////////
	PlayerInit(&ply);			
	ObstacleInit(&obstacle, MV1LoadModel("img/obstacle/block1.mv1"));	
	ObstacleBeeInit(&obstacleBee, MV1LoadModel("img/obstacle/Bee.mv1"));
	BackGroundInit(&backGround);		
	CollisionCircleInit(&plyCollision, VGet(0.0f,10.0f,0.0f),PLAYER_RADIUS);	
	CollisionCircleInit(&obstacleCollision, obstacle.pos,OBSTACLE_RADIUS);
	CollisionBeeCircleInit(&obstacleBeeCollision, obstacleBee.pos,OBSTACLE_BEE_RADIUS);
	SucoreInit(&gameSucore);
	TimerInit(&timer);
	ShadowInit(&shadow);
	//�Q�[���S�ݒ�
	nowGameScene = TitleScene;
	//nowGameScene = ResultScene;

	// �G�X�P�[�v�L�[��������邩�E�C���h�E��������܂Ń��[�v
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// deltaTime�v��
		float deltaTime;
		nowCount = GetNowHiPerformanceCount();
		deltaTime = (nowCount - prevCount) / 1000000.0f;
		
		// ��ʂ�����������
		ClearDrawScreen();

		//�V�[���m�F
		switch (nowGameScene)
		{
		case TitleScene:
			//�^�C�g������

			//���X�V
			TittleUpdate(&ply, &obstacle, fps);

			//�`��
			BackGroundDraw(&backGround);
			PlayerDraw(&ply);
			ObstacleDraw(&obstacle);
			TittleTextDraw(tittleTextFlg);
			//5�t���[�����ƂɃt���O�X�V
			if (fps % 20 == 0)
			{
				if (tittleTextFlg == true)
				{
					tittleTextFlg = false;
				}
				else
				{
					tittleTextFlg = true;
				}
			}

			//�L�[���͂ŃV�[���؂�ւ�
			if (CheckHitKey(KEY_INPUT_SPACE) == 1)
			{
				//fps������
				fps = 0;
				//�V�[���؂�ւ�
				nowGameScene = PlayScene;
				//��Q���̍ŏ�����
				ObstacleInit(&obstacle, MV1LoadModel("img/obstacle/block1.mv1"));
			}
			break;

		case PlayScene:
			//�v���C����

			//////////////////////////////////////
			/// �X�V����
			////////////////////////////////////////
			if (ply.displayFlg == true && startFlg == true)
			{
				PlayerUpdata(&ply, fps, &plyCollision, &obstacle, &gameSucore);
				ObstacleUpdate(&obstacle, &obstacleCollision);
				ObstacleBeeUpdate(&obstacleBee, &obstacleBeeCollision);
				//�v���C���[�Ɗ�̓����蔻��
				if (ply.displayFlg == true)
				{
					CollisionJudgement(&plyCollision, &obstacleCollision, &ply, &obstacle, &gameSucore);
				}
				//�v���C���[�Ƃ͂��̓����蔻��
				if (ply.displayFlg == true)
				{
					CollisionJudgement(&plyCollision, &obstacleBeeCollision, &ply, &obstacleBee, &gameSucore);
				}
			}
			BackGroundUpdate(&backGround);

			/////////////////////////////////////
			/// �`�揈��
			////////////////////////////////////
			BackGroundDraw(&backGround);
			ObstacleDraw(&obstacle);
			ObstacleDraw(&obstacleBee);
			GetSucoreDraw(&gameSucore);
			TotalSucoreDraw(&gameSucore);
			TimerDraw(&timer);
			//�����蔻�苅�`��(�e�X�g�p)
			/*CollisionCircleDraw(&obstacleBeeCollision, OBSTACLE_BEE_RADIUS);
			CollisionCircleDraw(&obstacleCollision, OBSTACLE_RADIUS);
			CollisionCircleDraw(&plyCollision, PLAYER_RADIUS);*/
			if (ply.displayFlg == true)
			{
				ShadowDraw(&shadow, ply.jumpFlg);
			}
			PlayerDraw(&ply);

			//��e�Ō��_����
			if (ply.displayFlg == false)
			{
				PlayerDeathMotion(&ply, fps,&plyCollision);
				//���X���ɂȂ�Ȃ��悤��Q���̃t���O������
				AllObstacleFlgReset(&obstacle, &obstacleBee);
			}

			//�Q�[���J�n�J�E���g�_�E������
			if (startFlg == false && timer.timeLimit != 0)
			{
				CountDown(fps, startFlg);
			}

			/////////////////////////////////////
			/// �������ԊǗ�
			////////////////////////////////////
			if (startFlg == true)
			{
				TimerCountDown(&timer, fps);
			}

			//����0�Ŏ��Ԑ؂ꏈ��
			if (timer.timeLimit == 0 && startFlg == true)
			{
				//�t���O�����낷
				startFlg = false;
				//���Ԑ؂�t���O�𗧂Ă�
				timeOverFlg = true;
				//�t���[�������
				timeOverFrameCnt = fps;
			}
			//���Ԑ؂�`��
			if (timeOverFlg == true)
			{
				SetFontSize(200);
				DrawString(190, 50, "Time over", GetColor(255, 0, 0));
			}

			//�V�[���؂�ւ�
			if (fps == timeOverFrameCnt + 120 && timeOverFlg == true)
			{
				//�v���C���[���U���g�p������
				ResultPlayerInit(&ply);
				nowGameScene = ResultScene;
				
			}

			break;

		case ResultScene:
			//���U���g����

			ResultUpdate(resultSucoreFlg,fps);

			//�`�揈��
			ResultDraw(&backGround,&gameSucore,resultSucoreFlg);
			//�v���C���[�̕`��
			PlayerDraw(&ply);

			break;
		default:
			break;
		}

		// ����ʂ̓��e��\��ʂɔ��f������
		ScreenFlip();

		//60FPS�҂�
		while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
		{
			;
		}

		prevCount = nowCount;
		//�t���[���J�E���g����
		fps++;
	}


	// �c�w���C�u�����̌�n��
	DxLib_End();

	// �\�t�g�̏I��
	return 0;
}