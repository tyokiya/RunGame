#pragma once

struct Player;
struct BackGround;
struct Sucore;

/// <summary>
/// �v�����[�̃��U���g�p������
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
void ResultPlayerInit(Player* ply);

/// <summary>
/// ���U���g�w�i�`��
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
void ResultDraw(BackGround* back, Sucore* sucore);