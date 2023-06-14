#pragma once
#define TIMELIMIT 1	//90
#define TIMER_IMG_SIZE 45

//�^�C�}�[�\����
struct Timer
{
	int timeLimit;			//��������
	int timerImg;			//�C���[�W�n���h��
};

/// <summary>
/// �^�C�}�[������
/// </summary>
/// <param name="timer">�^�C�}�[�\���̂̃|�C���^</param>
void TimerInit(Timer* timer);

/// <summary>
/// �^�C�}�[�J�E���g�_�E��
/// </summary>
/// <param name="timer">�^�C�}�[�\���̂̃|�C���^</param>
/// <param name="fps">�t���[���J�E���g</param>
void TimerCountDown(Timer* timer,int fps);

/// <summary>
/// �c�莞�Ԃ̕`��
/// </summary>
/// <param name="timer">�^�C�}�[�\���̂̃|�C���^</param>
void TimerDraw(Timer* timer);