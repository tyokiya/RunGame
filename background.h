#pragma once
#define IMG_MOVE_SPEED 10.0f
#define BARD_IMG_SIZE 75
//背景画像構造体
struct BackGround
{
	int backImg;					//背景画像ハンドル
	int roadImg;					//道画像ハンドル
	int bardImg;					//鳥画像ハンドル
	float bardImgX, bardImgY;		//鳥画像ハンドル座標
	int resultBackImg;				//リザルト背景画像ハンドル
};

/// <summary>
/// 背景画像初期化
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
void BackGroundInit(BackGround* back);

/// <summary>
/// 背景画像更新
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
void BackGroundUpdate(BackGround* back);

/// <summary>
/// 背景画像描画
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
void BackGroundDraw(BackGround* back);

/// <summary>
/// ゲーム開始前カウントダウン
/// </summary>
/// <param name="back">背景画像構造体のポインタ</param>
/// <param name="starflg">ゲーム開始フラグ</param>
void CountDown(int fps,bool& starflg);