#include "DxLib.h"
#include "sucore.h"
#include "player.h"

void SucoreInit(Sucore* sucore)
{
	sucore->nowScore = 0;
	//画像の読み込み
	LoadDivGraph("img/sucore/number.png", 70, 10, 7, 337.7, 346.7, sucore->sucoreImgHandl);
	sucore->excellentImg = LoadGraph("img/backimg/excellent.png", TRUE);
	sucore->goodImg = LoadGraph("img/backimg/nice.png", TRUE);
	//フラグ初期化
	sucore->drawFlg = false;
	//カウント初期化
	sucore->drawCnt = 0;
	//効果音設定
	sucore->sucoreSound = LoadSoundMem("sound/player/getSound.wav");
}	

void GetSucoreInit(Sucore* sucore)
{
	sucore->getScore = 0;
}

void SucoreAdd(Sucore* sucore, float distanceBornus)
{
	//スコアアップの確認
	if (distanceBornus <= 40.0f)
	{
		sucore->getScore = BORNUS_SUCORE;
	}
	else
	{
		sucore->getScore = NORMAL_SUCORE;
	}
	//得点の加算
	sucore->nowScore += sucore->getScore;
	//描画フラグを立てる
	sucore->drawFlg = true;
	//効果音再生
	PlaySoundMem(sucore->sucoreSound, DX_PLAYTYPE_BACK);
}

void GetSucoreDraw(Sucore* sucore)
{
	//描画フラグ立っていたら描画
  	if (sucore->drawFlg == true)
	{
		if (sucore->getScore == NORMAL_SUCORE)
		{
			//スコア画像の描画
			for (int i = 0; i < 3; i++)
			{
				DrawExtendGraph(160, 400 - (sucore->drawCnt * 10), 260, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[61], TRUE);
				DrawExtendGraph(210, 400 - (sucore->drawCnt * 10), 310, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
				DrawExtendGraph(260, 400 - (sucore->drawCnt * 10), 360, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
			}
			//テキスト画像描画
			DrawExtendGraph(400, 0, 800, 225, sucore->goodImg, TRUE);
		}
		else if (sucore->getScore == BORNUS_SUCORE)
		{
			//スコア画像の描画
			for (int i = 0; i < 3; i++)
			{
				DrawExtendGraph(160, 400 - (sucore->drawCnt * 10), 260, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[63], TRUE);
				DrawExtendGraph(210, 400 - (sucore->drawCnt * 10), 310, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
				DrawExtendGraph(260, 400 - (sucore->drawCnt * 10), 360, 500 - (sucore->drawCnt * 10), sucore->sucoreImgHandl[60], TRUE);
			}
			//テキスト画像描画
			DrawExtendGraph(400, 0, 800, 225, sucore->excellentImg, TRUE);
		}
		//カウント追加
		sucore->drawCnt++;
	}
	
	if (sucore->drawCnt == 30)
	{
		//描画フラグを下す
		sucore->drawFlg = false;
		//カウント初期化
		sucore->drawCnt = 0;
		//獲得スコアの初期化　
		GetSucoreInit(sucore);
	}
}

void TotalSucoreDraw(Sucore* sucore)
{
	int n1, n2, n3, n4;
	//一桁当たりの数をとる
	n1 = sucore->nowScore % 10;
	n2 = sucore->nowScore % 100 / 10;
	n3 = sucore->nowScore % 1000 / 100;
	n4 = sucore->nowScore % 10000 / 1000;
	//0行かないための処理
	if (n1 < 0){
		n1 = 0;}
	if (n2 < 0){
		n2 = 0;}
	if (n3 < 0){
		n3 = 0;}
	if (n4 < 0){
		n4 = 0;}

	//一桁当たりの描画
	DrawExtendGraph(0, 0, 40, 40, sucore->sucoreImgHandl[n4 + 60], TRUE);
	DrawExtendGraph(30, 0, 70, 40, sucore->sucoreImgHandl[n3 + 60], TRUE);
	DrawExtendGraph(60, 0, 100, 40, sucore->sucoreImgHandl[n2 + 60], TRUE);
	DrawExtendGraph(90, 0, 130, 40, sucore->sucoreImgHandl[n1 + 60], TRUE);
}

void SucoreDow(Sucore* sucore)
{
	//スコアの減点
	if (sucore->nowScore > 1)
	{
		sucore->nowScore -= DOWN_SUCORE;
	}
}