#pragma once

struct Player;
struct BackGround;
struct Sucore;

/// <summary>
/// �v�����[�̃��U���g�p������
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
void ResultPlayerInit(Player* ply);

void ResultUpdate(bool& flg,int fps);

/// <summary>
/// ���U���g�w�i�`��
/// </summary>
/// <param name="back">�w�i�摜�\���̂̃|�C���^</param>
/// <param name="flg">�X�R�A�`��t���O</param>
void ResultDraw(BackGround* back, Sucore* sucore, bool flg);

