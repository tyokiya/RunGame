#pragma once

struct Obstacle;
struct Player;

/// <summary>
/// タイトル画面更新
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
/// <param name="obstacle">障害物構造体のポインタ</param>
/// <param name="fps">フレームレートカウント</param>
void TittleUpdate(Player* ply, Obstacle* obstacle, int fps);

/// <summary>
/// タイトルテキスト描画
/// </summary>
void TittleTextDraw(bool flg);