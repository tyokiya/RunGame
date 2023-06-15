#pragma once
#define TIMELIMIT 90	//90
#define TIMER_IMG_SIZE 45

//タイマー構造体
struct Timer
{
	int timeLimit;			//制限時間
	int timerImg;			//イメージハンドル
	bool timeOverFlg;				//時間切れフラグ
	int timeOverFrameCnt;				//時間切れ時のフレーム数
};

/// <summary>
/// タイマー初期化
/// </summary>
/// <param name="timer">タイマー構造体のポインタ</param>
void TimerInit(Timer* timer);

/// <summary>
/// タイマーカウントダウン
/// </summary>
/// <param name="timer">タイマー構造体のポインタ</param>
/// <param name="fps">フレームカウント</param>
void TimerCountDown(Timer* timer,int fps);

/// <summary>
/// 残り時間の描画
/// </summary>
/// <param name="timer">タイマー構造体のポインタ</param>
void TimerDraw(Timer* timer);