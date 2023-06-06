#include "DxLib.h"
#include "player.h"
#include "obstacle.h"
#include "background.h"
#include "collision.h"
#include "sucore.h"
#include "timer.h"
#include "shadow.h"
#include "gameScene.h"
#include "tittle.h"
#include "result.h"

//-----------------------------------------------------------------------------
// @brief  メイン関数.
//-----------------------------------------------------------------------------
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// 画面モードのセット
	SetGraphMode(1200, 800, 16);
	ChangeWindowMode(TRUE);
	SetUseLighting(TRUE);
	SetFontSize(45);

	// ＤＸライブラリ初期化処理
	if (DxLib_Init() == -1)
	{
		return -1;	// エラーが起きたら直ちに終了
	}

	// 画面の更新時間の管理用変数
	LONGLONG nowCount, prevCount;                      // マイクロ秒(100万分の1秒単位で時刻取得)
	nowCount = prevCount = GetNowHiPerformanceCount();
	float fixedDeltaTime = 1.0f / 60.0f;               // 60分の1秒 = 0.01666...秒
	float waitFrameTime = 15500;                       // 16000マイクロ秒 = 16ミリ秒 = 0.016秒

	int fps = 0;			//フレームカウント

	//奥行0.1～1000までをカメラの描画範囲とする
	SetCameraNearFar(0.1f, 1000.0f);
	//(90, 50, 20)の視点から(0, 45, 40)のターゲットを見る角度にカメラを設置
	SetCameraPositionAndTarget_UpVecY(VGet(90, 50, 20), VGet(0, 45, 40));
	//////////////////////////////////////////
	/// 構造体宣言
	///////////////////////////////////////////
	//プレヤー
	Player ply;
	//障害物
	Obstacle obstacle;
	//背景画像
	BackGround backGround;
	//当たり判定
	CollisionCircle plyCollision;
	CollisionCircle obstacleCollision;
	//得点
	Sucore gameSucore;
	//タイマー
	Timer timer;
	//影
	Shadow shadow;
	//現在のゲームシーン
	GameScene nowGameScene;

	bool startFlg = false;					//ゲーム開始フラグ
	bool tittleTextFlg = false;				//タイトルテキストのフラグ
	bool timeOverFlg = false;				//時間切れフラグ
	int timeOverFrameCnt = 0;				//時間切れ時のフレーム数

	//////////////////////////////////////
	/// 初期化処理
	/////////////////////////////////////
	PlayerInit(&ply);			
	ObstacleInit(&obstacle, MV1LoadModel("img/map/block1.mv1"));	
	BackGroundInit(&backGround);		
	CollisionCircleInit(&plyCollision, VGet(0.0f,10.0f,0.0f));	
	CollisionCircleInit(&obstacleCollision, obstacle.pos);			
	SucoreInit(&gameSucore);
	TimerInit(&timer);
	ShadowInit(&shadow);
	//ゲーム心設定
	nowGameScene = TitleScene;
	//nowGameScene = ResultScene;

	// エスケープキーが押されるかウインドウが閉じられるまでループ
	while (ProcessMessage() == 0 && CheckHitKey(KEY_INPUT_ESCAPE) == 0)
	{
		// deltaTime計測
		float deltaTime;
		nowCount = GetNowHiPerformanceCount();
		deltaTime = (nowCount - prevCount) / 1000000.0f;
		
		// 画面を初期化する
		ClearDrawScreen();

		//シーン確認
		switch (nowGameScene)
		{
		case TitleScene:
			//タイトル処理

			//情報更新
			TittleUpdate(&ply, &obstacle, fps);

			//描画
			BackGroundDraw(&backGround);
			PlayerDraw(&ply);
			ObstacleDraw(&obstacle);
			TittleTextDraw(tittleTextFlg);
			//5フレームごとにフラグ更新
			if (fps % 20 == 0)
			{
				if (tittleTextFlg == true)
				{
					tittleTextFlg = false;
				}
				else
				{
					tittleTextFlg = true;
				}
			}

			//キー入力でシーン切り替え
			if (CheckHitKey(KEY_INPUT_SPACE) == 1)
			{
				//fps初期化
				fps = 0;
				//シーン切り替え
				nowGameScene = PlayScene;
				//障害物の最初期化
				ObstacleInit(&obstacle, MV1LoadModel("img/map/block1.mv1"));
			}
			break;

		case PlayScene:
			//プレイ処理

			//////////////////////////////////////
			/// 更新処理
			////////////////////////////////////////
			if (ply.displayFlg == true && startFlg == true)
			{
				PlayerUpdata(&ply, fps, &plyCollision, &obstacle, &gameSucore);
				ObstacleUpdate(&obstacle, &obstacleCollision);
				CollisionJudgement(&plyCollision, &obstacleCollision, &ply, &obstacle, &gameSucore);
			}
			BackGroundUpdate(&backGround);

			/////////////////////////////////////
			/// 描画処理
			////////////////////////////////////
			BackGroundDraw(&backGround);
			ObstacleDraw(&obstacle);
			GetSucoreDraw(&gameSucore);
			TotalSucoreDraw(&gameSucore);
			TimerDraw(&timer);
			if (ply.displayFlg == true)
			{
				ShadowDraw(&shadow, ply.jumpFlg);
			}
			PlayerDraw(&ply);

			//被弾で減点処理
			if (ply.displayFlg == false)
			{
				PlayerDeathMotion(&ply, fps);
			}

			//ゲーム開始カウントダウン処理
			if (startFlg == false && timer.timeLimit != 0)
			{
				CountDown(fps, startFlg);
			}

			/////////////////////////////////////
			/// 制限時間管理
			////////////////////////////////////
			if (startFlg == true)
			{
				TimerCountDown(&timer, fps);
			}

			//時間0で時間切れ処理
			if (timer.timeLimit == 0 && startFlg == true)
			{
				//フラグを下ろす
				startFlg = false;
				//時間切れフラグを立てる
				timeOverFlg = true;
				//フレームを取る
				timeOverFrameCnt = fps;
			}
			//時間切れ描画
			if (timeOverFlg == true)
			{
				SetFontSize(200);
				DrawString(190, 50, "Time over", GetColor(255, 0, 0));
			}

			//シーン切り替え
			if (fps == timeOverFrameCnt + 120 && timeOverFlg == true)
			{
				//プレイヤーリザルト用初期化
				ResultPlayerInit(&ply);
				nowGameScene = ResultScene;
				
			}

			break;

		case ResultScene:
			//リザルト処理

			//描画処理
			ResultDraw(&backGround,&gameSucore);
			//プレイヤーの描画
			PlayerDraw(&ply);

			break;
		default:
			break;
		}

		// 裏画面の内容を表画面に反映させる
		ScreenFlip();

		//60FPS待ち
		while (GetNowHiPerformanceCount() - nowCount < waitFrameTime)
		{
			;
		}

		prevCount = nowCount;
		//フレームカウント増加
		fps++;
	}


	// ＤＸライブラリの後始末
	DxLib_End();

	// ソフトの終了
	return 0;
}