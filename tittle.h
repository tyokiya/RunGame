#pragma once

struct Obstacle;
struct Player;

struct TitlleMaterial
{
	int excellentImg;					//エクセレントのテキストイメージハンドル
	int goodImg;						//グッドのテキストイメージハンドル
	bool excellentFlg;					//エクセレントフラグ
	bool goodFlg;						//グッドフラグ
	int excellentFlgCounter;			//エクセレントフラグカウンター(立った時のfpsを保管)
	int goodFlgCounter;					//グッドフラグカウンター(立った時のfpsを保管)
	int jumpCounter;					//ジャンプ回数のカウンター
};

/// <summary>
/// タイトル初期化
/// </summary>
/// <param name="material">タイトル素材構造体</param>
void TittleInit(TitlleMaterial& material);

/// <summary>
/// タイトル画面更新
/// </summary>
/// <param name="ply">プレイヤー構造体のポインタ</param>
/// <param name="obstacle">障害物構造体のポインタ</param>
/// <param name="fps">フレームレートカウント</param>
void TittleUpdate(Player* ply, Obstacle* obstacle, int fps, TitlleMaterial& material);

void TittleEffectDraw(TitlleMaterial& material);

/// <summary>
/// タイトルテキスト描画
/// </summary>
void TittleTextDraw(bool flg);