#pragma once

struct Player;
struct Obstacle;
struct Sucore;
struct CollisionCircle;
struct Timer;

//�Q�[���V�[���񋓑�
enum GameScene
{
	TitleScene,	//�^�C�g��
	PlayScene,	//�v���C
	ResultScene	//���U���g
};

//�ăX�^�[�g���̕K�v�ȗv�f�̏�����
void ReSutartInit(Player& ply, Sucore& sucore, Timer& timer, Obstacle& obstacle_Bee, CollisionCircle& collision);
