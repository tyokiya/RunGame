#pragma once
#define SHADOW_ANIMETION_COUNT 2		//影画像アニメーション数
#define SHADOW_SIZE_X 250				//影画像サイズx
#define SHADOW_SIZE_Y 100				//影画像サイズy

struct Shadow
{
	float x, y;			//座標
	int img[SHADOW_ANIMETION_COUNT];			//画像ハンドル
};

/// <summary>
/// 影画像初期化
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
void ShadowInit(Shadow* shadow);

/// <summary>
/// 影画像描画
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
/// <param name="jumpFlg">プレイヤーのジャンプフラグ</param>
void ShadowDraw(Shadow* shadow, bool jumpFlg);
