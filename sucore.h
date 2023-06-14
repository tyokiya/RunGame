#pragma once
#define NORMAL_SUCORE 100			//通常の得点
#define BORNUS_SUCORE 300			//ボーナス時の得点
#define SUCORE_IMG_NUM 70			//得点イメージの配列数
#define DOWN_SUCORE 150				//減点する点数

//得点構造体
struct Sucore
{
	int nowScore;				//得点
	int getScore;				//1フレームの間に獲得した得点
	int sucoreImgHandl[SUCORE_IMG_NUM];	//得点のイメージハンドル
	bool drawFlg;						//描画フラグ
	int drawCnt;						//描画時間のカウント
	int sucoreSound;					//獲得サウンド
	int excellentImg;					//エクセレントのテキストイメージハンドル
	int goodImg;						//グッドのテキストイメージハンドル
};

/// <summary>
/// スコア初期化
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
void SucoreInit(Sucore* sucore);

/// <summary>
/// 獲得スコア初期化
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
void GetSucoreInit(Sucore* sucore);

/// <summary>
/// スコア増加
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
/// <param name="distanceBornus">距離ボーナス</param>
void SucoreAdd(Sucore* sucore, float distanceBornus);

/// <summary>
/// 獲得スコア描画
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
void GetSucoreDraw(Sucore* sucore);

/// <summary>
/// トータルスコア描画
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
void TotalSucoreDraw(Sucore* sucore);

/// <summary>
/// スコアの減点
/// </summary>
/// <param name="sucore">得点判定構造体のポインタ</param>
void SucoreDown(Sucore* sucore);

