#include "GameClearScene.h"

GameClearScene::GameClearScene() {
    // コンストラクタの実装
}

void GameClearScene::Init() {
    // 初期化処理の実装
    ArrowPosY = 10;
    CountFrame = 0;
}

void GameClearScene::Update() {
    // 更新処理の実装
		/*タイマ更新*/
	CountFrame++;
	if (CountFrame > 80000) { CountFrame = 0; }//一定以上数が増えたら初期化(数は適当)

	/*Draw処理*/
	//裏画面の初期化
	ClearDrawScreen();

	// ゲームクリア画面の描画
	DrawGraph(0, 0, MountainGraph, true);
	DrawGraph(0, 0, GraundGraph, true);
	DrawGraph(0, 0, ClearGraph, true);

	// スライムの瞬きの描画
	if ((CountFrame % 100) < 97)
	{
		DrawGraph(0, 0, SlimeAyeGraph, true);
	}
	else
	{
		DrawGraph(0, 0, SlimeAye2Graph, true);
	}
	// クリア画面のテキスト描画
	DrawGraph(0, 0, GameClearTxtGraph, true);

	if ((CountFrame % 60) < 32)
	{
		DrawGraph(-10, ArrowPosY, ArrowGraph, true);
	}

	ScreenFlip();

	/*シーン遷移処理*/
	//エンターでシーン変更
	if (ConfirmButton())
	{
		if (ArrowPosY == 10)
		{
			return TITLESCENE;
		}
	}
}

void GameClearScene::Draw() {
    // 描画処理の実装
}
