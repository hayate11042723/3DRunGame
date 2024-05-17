#include "DxLib.h"
#include <math.h>
#include "Enemy.h"
#include "GameScene.h"
#include "GameClearScene.h"
#include "GameOverScene.h"
#include "InputManager.h"
#include "Player.h"
#include "TitleScene.h"
#include "define.h"

void BackScroll(const int t_areaX, const int tD_graph, const int t_winWidth, const int t_winHeight)
{
	DrawRectGraph(0, 0, t_areaX, 0, t_winWidth, t_winHeight, tD_graph, false);
	DrawRectGraph(t_winWidth - t_areaX, 0, 0, 0, t_areaX, t_winHeight, tD_graph, false);
}

// プログラムは WinMain から始まります
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	LONGLONG RoopStartTime = 0;
	bool GameRoop = true;

	// 一部の関数はDxLib_Init()の前に実行する必要がある
	ChangeWindowMode(false);
	SetWindowText("すらいむすとろぉく");

	// 画面モードの設定
	SetGraphMode(1280, 720, 32);
	if (DxLib_Init() == -1)		// ＤＸライブラリ初期化処理
	{
		return -1;			// エラーが起きたら直ちに終了
	}
	SetDrawScreen(DX_SCREEN_BACK);

	TitleScene* titlescene = new TitleScene();
	
	GameClearScene* clearscene = new GameClearScene();

	GameOverScene* overscene = new GameOverScene();

	Player* player = new Player();

	Enemy* enemy = new Enemy();

	// メインループ
	while (GameRoop)
	{
		RoopStartTime = GetNowHiPerformanceCount();

		ClearDrawScreen();

		

		//裏画面を表へ
		ScreenFlip();

		//リフレッシュ処理(-1ならエラー)
		if (ProcessMessage() < 0)
		{
			break;
		}

		// escキーでゲーム終了
		if (CheckHitKey(KEY_INPUT_ESCAPE))
		{
			break;
		}

		// FPS60に固定する
		while (GetNowHiPerformanceCount() - RoopStartTime < 16667)
		{
			// 16.66ミリ秒(16667マイクロ秒)経過するまで待つ
		}
	}

	DxLib_End();				// ＤＸライブラリ使用の終了処理

	return 0;				// ソフトの終了 
}

//// ゲームシーン
//int GameScene()
//{
//	int EnemyGraph;
//	bool GameRoop = true;
//	int Phase = 0;
//	int StartTime;
//	Time = 0;
//	int AreaX = 0;
//	int Speed = 3;
//	unsigned int Cr1;
//	unsigned int Cr2;
//	int NextScene = GAMESCENE;
//
//	int MoovSpeed = 10;
//	int ClarTime = 60000;
//	int JumpHeight = 24;
//	int JumpHeight1 = 15;
//	int CountFrame = 0;
//
//
//	
//	// グラフィック『back.png』をメモリにロード
//	BackGraph = LoadGraph("image/back.png");
//	// 音源『SlimeSe.mp3』をメモリにロード
//	SeHandle = LoadSoundMem("image/SlimeSe.mp3");
//	// グラフィック『TimeWindow.png』をメモリにロード
//	BackGlassGraph = LoadGraph("image/TimeWindow.png");
//
//	// キャラクターの初期データをセット
//	PlayerX = 60;
//	PlayerY = GroundCoordinate;
//
//	// 現在経過時間を得る
//	StartTime = GetNowCount();
//
//	int EnemyNum = 0;
//	int JumpNum = 0;
//
//	// ゲームループ
//	while (GetNowCount() - StartTime < ClarTime)
//	{
//
//		// 描画を行う前に画面をクリアする
//		ClearDrawScreen();
//
//		// このフレームの開始時刻を覚えておく
//		LONGLONG start = GetNowHiPerformanceCount();
//
//		// 背景スクロールの描画
//		BackScroll(AreaX, BackGraph, EnemyStart, 720);
//
//		AreaX += Speed;
//		if (AreaX > EnemyStart)
//		{
//			AreaX = 0;
//		}
//
//		// 経過時間の小窓の描画
//		DrawGraph(15, -10, BackGlassGraph, true);
//
//		// 白の色コードを保存
//		Cr1 = GetColor(255, 200, 20);
//		Cr2 = GetColor(0, 0, 0);
//		Time = GetNowCount() - StartTime;
//
//		SetFontSize(34);
//
//		// 経過時間の描画
//		ChangeFont("HG創英角ﾎﾟｯﾌﾟ体");
//		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
//		DrawFormatString(53, 23, Cr2, "経過時間");
//		DrawFormatString(63, 63, Cr2, "%d秒", Time / 1000);
//		DrawFormatString(50, 20, Cr1, "経過時間");
//		DrawFormatString(60, 60, Cr1, "%d秒", Time / 1000);
//
//		// エネミーの出現処理
//		{
//			if (EnemyNum == 0 && Time >= 0) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 1 && Time >= 3000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 2 && Time >= 6000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 3 && Time >= 8000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 4 && Time >= 10000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 5 && Time >= 12000) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 6 && Time >= 12000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 7 && Time >= 14000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 8 && Time >= 14000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 9 && Time >= 16000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 10 && Time >= 16000) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 11 && Time >= 18000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 12 && Time >= 18000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 13 && Time >= 20000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 14 && Time >= 20000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 15 && Time >= 22000) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 16 && Time >= 24000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 17 && Time >= 24000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 18 && Time >= 26000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 19 && Time >= 28000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 20 && Time >= 28000) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 21 && Time >= 30000) {
//				TelopPos1.x = 690;
//				TelopPos1.y = 0;
//				EnemyNum++;
//			}
//			if (EnemyNum == 22 && Time >= 33000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 23 && Time >= 33000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 24 && Time >= 33000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 25 && Time >= 34000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 26 && Time >= 34000) {
//				EnemyPos5.x = EnemyStart;
//				EnemyPos5.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 27 && Time >= 35000) {
//				EnemyPos6.x = EnemyStart;
//				EnemyPos6.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 28 && Time >= 36000) {
//				EnemyPos7.x = EnemyStart;
//				EnemyPos7.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 29 && Time >= 36000) {
//				EnemyPos8.x = EnemyStart;
//				EnemyPos8.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 30 && Time >= 37000) {
//				EnemyPos9.x = EnemyStart;
//				EnemyPos9.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 31 && Time >= 37000) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 32 && Time >= 38000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 33 && Time >= 39000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 34 && Time >= 39000) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 35 && Time >= 41000) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 36 && Time >= 41000) {
//				EnemyPos5.x = EnemyStart;
//				EnemyPos5.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 37 && Time >= 42000) {
//				EnemyPos6.x = EnemyStart;
//				EnemyPos6.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 38 && Time >= 42000) {
//				EnemyPos7.x = EnemyStart;
//				EnemyPos7.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 39 && Time >= 43000) {
//				EnemyPos8.x = EnemyStart;
//				EnemyPos8.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 40 && Time >= 43000) {
//				EnemyPos9.x = EnemyStart;
//				EnemyPos9.y = EnemyUp1;
//				EnemyNum++;
//			}
//			if (EnemyNum == 41 && Time >= 45000) {
//				TelopPos2.x = 690;
//				TelopPos2.y = 0;
//				EnemyNum++;
//			}
//			if (EnemyNum == 42 && Time >= 45000) {
//				TelopPos2.x = 690;
//				TelopPos2.y = 0;
//				EnemyNum++;
//			}
//			if (EnemyNum == 43 && Time >= 47000) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 44 && Time >= 47000) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 45 && Time >= 47850) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 46 && Time >= 47850) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 47 && Time >= 48700) {
//				EnemyPos5.x = EnemyStart;
//				EnemyPos5.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 48 && Time >= 49550) {
//				EnemyPos6.x = EnemyStart;
//				EnemyPos6.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 49 && Time >= 49550) {
//				EnemyPos7.x = EnemyStart;
//				EnemyPos7.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 50 && Time >= 50400) {
//				EnemyPos8.x = EnemyStart;
//				EnemyPos8.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 51 && Time >= 50400) {
//				EnemyPos9.x = EnemyStart;
//				EnemyPos9.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 52 && Time >= 51250) {
//				EnemyPos.x = EnemyStart;
//				EnemyPos.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 53 && Time >= 52100) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 54 && Time >= 52100) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 55 && Time >= 52950) {
//				EnemyPos3.x = EnemyStart;
//				EnemyPos3.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 56 && Time >= 52950) {
//				EnemyPos4.x = EnemyStart;
//				EnemyPos4.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 57 && Time >= 53800) {
//				EnemyPos5.x = EnemyStart;
//				EnemyPos5.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 58 && Time >= 54650) {
//				EnemyPos6.x = EnemyStart;
//				EnemyPos6.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 59 && Time >= 54650) {
//				EnemyPos7.x = EnemyStart;
//				EnemyPos7.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 60 && Time >= 55500) {
//				EnemyPos8.x = EnemyStart;
//				EnemyPos8.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 61 && Time >= 55500) {
//				EnemyPos9.x = EnemyStart;
//				EnemyPos9.y = EnemyUp2;
//				EnemyNum++;
//			}
//			if (EnemyNum == 62 && Time >= 56350) {
//				EnemyPos1.x = EnemyStart;
//				EnemyPos1.y = GroundCoordinate;
//				EnemyNum++;
//			}
//			if (EnemyNum == 63 && Time >= 56350) {
//				EnemyPos2.x = EnemyStart;
//				EnemyPos2.y = EnemyUp2;
//				EnemyNum++;
//			}
//		}
//		// 落下処理
//		PlayerY -= JumpPower;
//		PlayerY -= JumpPower1;
//		//PlayerY -= JumpPower2;
//
//		//落下加速度付加
//		JumpPower -= 0.8f;
//		JumpPower1 -= 0.9f;
//
//		// プレイヤーが画面下端からはみ出そうになっていたら画面内の座標に戻してあげる
//		if (PlayerY > 720 - 64) PlayerY = 720 - 64;
//		// プレイヤーが画面天井からはみ出そうになっていたら画面内の座標に戻してあげる
//		if (PlayerY < 0 + 64) PlayerY = 0 + 64;
//
//		// もし地面についていたら止まる
//		if (PlayerY > GroundCoordinate)
//		{
//			PlayerY = GroundCoordinate;
//			JumpPower = 0;
//			JumpPower1 = 0;
//			JumpNum = 0;
//			CountFrame = 0;
//		}
//
//		CountFrame++;
//
//		// プレイヤーのジャンプ処理
//		{
//			if (PlayerY == GroundCoordinate)
//			{
//				if (InputJump1())
//				{
//					JumpPower = JumpHeight;
//					JumpNum = 1;
//					// 読みこんだ音をバックグラウンド再生します(『PlaySoundMem』関数使用)
//					PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
//				}
//			}
//
//			if (InputJump2())
//			{
//				if (JumpNum == 1 && CountFrame >= 8)
//				{
//					JumpPower1 = JumpHeight1;
//					JumpNum = 2;
//					// 読みこんだ音をバックグラウンド再生します(『PlaySoundMem』関数使用)
//					PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
//				}
//			}
//		}
//
//		// テロップの移動処理
//		{
//			TelopPos1.x -= MoovSpeed;
//			TelopPos2.x -= MoovSpeed;
//		}
//
//		// エネミーの移動処理
//		{
//			EnemyPos.x -= MoovSpeed;
//			EnemyPos1.x -= MoovSpeed;
//			EnemyPos2.x -= MoovSpeed;
//			EnemyPos3.x -= MoovSpeed;
//			EnemyPos4.x -= MoovSpeed;
//			EnemyPos5.x -= MoovSpeed;
//			EnemyPos6.x -= MoovSpeed;
//			EnemyPos7.x -= MoovSpeed;
//			EnemyPos8.x -= MoovSpeed;
//			EnemyPos9.x -= MoovSpeed;
//		}
//
//		// テロップを描画する
//		DrawGraph(TelopPos1.x, TelopPos1.y, Telop1Graph, true);
//		DrawGraph(TelopPos2.x, TelopPos2.y, Telop2Graph, true);
//
//		// スライムの弾んでるモーション
//		const float SinSpeed = 0.1f;
//		const float AnimationSize = 8.0f;
//		static float AnimationHeight = 0.0f;	// スライムが弾んでいるようにアニメーションしているよう見せるための高さ値
//		static float SinCount = 0;
//		SinCount += SinSpeed;
//		AnimationHeight = sinf(SinCount) * AnimationSize;		// 決まった数値だけ高さを増やしてあげる
//
//		// プレイヤーを描画する
//		DrawExtendGraph(PlayerX, PlayerY - AnimationHeight, PlayerX + PlayerW, PlayerY + PlayerH, PlayerGraph, TRUE);
//
//		// エネミーを描画する
//		{
//			DrawExtendGraph(EnemyPos.x, EnemyPos.y - AnimationHeight, EnemyPos.x + EnemyW, EnemyPos.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos1.x, EnemyPos1.y - AnimationHeight, EnemyPos1.x + EnemyW, EnemyPos1.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos2.x, EnemyPos2.y - AnimationHeight, EnemyPos2.x + EnemyW, EnemyPos2.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos3.x, EnemyPos3.y - AnimationHeight, EnemyPos3.x + EnemyW, EnemyPos3.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos4.x, EnemyPos4.y - AnimationHeight, EnemyPos4.x + EnemyW, EnemyPos4.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos5.x, EnemyPos5.y - AnimationHeight, EnemyPos5.x + EnemyW, EnemyPos5.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos6.x, EnemyPos6.y - AnimationHeight, EnemyPos6.x + EnemyW, EnemyPos6.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos7.x, EnemyPos7.y - AnimationHeight, EnemyPos7.x + EnemyW, EnemyPos7.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos8.x, EnemyPos8.y - AnimationHeight, EnemyPos8.x + EnemyW, EnemyPos8.y + EnemyH, EnemyGraph, TRUE);
//			DrawExtendGraph(EnemyPos9.x, EnemyPos9.y - AnimationHeight, EnemyPos9.x + EnemyW, EnemyPos9.y + EnemyH, EnemyGraph, TRUE);
//		}
//		// プレイヤー画像と敵画像で当たり判定
//		{
//			if (PlayerX + IMAGE_SIZE >= EnemyPos.x && PlayerX <= EnemyPos.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos.y && PlayerY <= EnemyPos.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}
//			if (PlayerX + IMAGE_SIZE >= EnemyPos1.x && PlayerX <= EnemyPos1.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos1.y && PlayerY <= EnemyPos1.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}
//			if (PlayerX + IMAGE_SIZE >= EnemyPos2.x && PlayerX <= EnemyPos2.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos2.y && PlayerY <= EnemyPos2.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}
//			if (PlayerX + IMAGE_SIZE >= EnemyPos3.x && PlayerX <= EnemyPos3.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos3.y && PlayerY <= EnemyPos3.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}
//			if (PlayerX + IMAGE_SIZE >= EnemyPos4.x && PlayerX <= EnemyPos4.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos4.y && PlayerY <= EnemyPos4.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}if (PlayerX + IMAGE_SIZE >= EnemyPos5.x && PlayerX <= EnemyPos5.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos5.y && PlayerY <= EnemyPos5.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}if (PlayerX + IMAGE_SIZE >= EnemyPos6.x && PlayerX <= EnemyPos6.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos6.y && PlayerY <= EnemyPos6.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}if (PlayerX + IMAGE_SIZE >= EnemyPos7.x && PlayerX <= EnemyPos7.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos7.y && PlayerY <= EnemyPos7.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}if (PlayerX + IMAGE_SIZE >= EnemyPos8.x && PlayerX <= EnemyPos8.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos8.y && PlayerY <= EnemyPos8.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}if (PlayerX + IMAGE_SIZE >= EnemyPos9.x && PlayerX <= EnemyPos9.x + IMAGE_SIZE) {
//				if (PlayerY + IMAGE_SIZE >= EnemyPos9.y && PlayerY <= EnemyPos9.y + IMAGE_SIZE) {
//					// 当たったらプレイヤーをデリート
//					DeleteGraph(PlayerGraph);
//					return GAMEOVERSCENE;
//				}
//			}
//		}
//		// 画面が切り替わるのを待つ
//		ScreenFlip();
//	}
//
//	//例外処理
//	return GAMECLEARSCENE;
//}