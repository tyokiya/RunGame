#pragma once

struct Obstacle;
struct Player;

/// <summary>
/// �^�C�g����ʍX�V
/// </summary>
/// <param name="ply">�v���C���[�\���̂̃|�C���^</param>
/// <param name="obstacle">��Q���\���̂̃|�C���^</param>
/// <param name="fps">�t���[�����[�g�J�E���g</param>
void TittleUpdate(Player* ply, Obstacle* obstacle, int fps);

/// <summary>
/// �^�C�g���e�L�X�g�`��
/// </summary>
void TittleTextDraw(bool flg);