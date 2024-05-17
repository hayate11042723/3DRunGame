#include "GameOverScene.h"

    // コンストラクタの実装
GameOverScene::GameOverScene() {
}

    // 初期化処理の実装
void GameOverScene::Init() {
	ArrowPosY = 0;
	CountFrame = 0;
}

    // 更新処理の実装
void GameOverScene::Update() {
	/*計算処理*/
		//Input Down.
	if (InputDown())
	{
		if (ArrowPosY == 0)
		{
			ArrowPosY = 80;
		}
		else
		{
			ArrowPosY = 0;
		}
	}
	//Input Up.
	if (InputUp())
	{
		if (ArrowPosY == 80)
		{
			ArrowPosY = 0;
		}
		else
		{
			ArrowPosY = 80;
		}
	}

	/*タイマ更新*/
	CountFrame++;
	if (CountFrame > 80000) { CountFrame = 0; }//一定以上数が増えたら初期化(数は適当)

	/*Draw処理*/
	//裏画面の初期化
	ClearDrawScreen();

	// ゲームオーバー画面の描画
	DrawGraph(0, 0, GameOverGraph, true);
	DrawGraph(0, 0, GameOverTxtGraph, true);

	// →の描画
	if ((CountFrame % 60) < 32)
	{
		DrawGraph(0, ArrowPosY, ArrowGraph, true);
	}

	// ゲームオーバー時の経過時間の表示
	{
		Cr1 = GetColor(255, 200, 20);
		Cr2 = GetColor(0, 0, 0);
		SetFontSize(68);
		ChangeFont("HG創英角ﾎﾟｯﾌﾟ体");
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
		DrawFormatString(105, 305, Cr2, "経過時間");
		DrawFormatString(185, 385, Cr2, "%d秒", Time / 1000);
		DrawFormatString(100, 300, Cr1, "経過時間");
		DrawFormatString(180, 380, Cr1, "%d秒", Time / 1000);
	}

	ScreenFlip();
}

    // 描画処理の実装
void GameOverScene::Draw() {
}
