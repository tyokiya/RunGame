#pragma once

struct Player;
struct BackGround;
struct Sucore;

/// <summary>
/// プレヤーのリザルト用初期化
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
void ResultPlayerInit(Player* ply);

void ResultUpdate(bool& flg,int fps);

/// <summary>
/// リザルト背景描画
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
/// <param name="flg">スコア描画フラグ</param>
void ResultDraw(BackGround* back, Sucore* sucore, bool flg);

