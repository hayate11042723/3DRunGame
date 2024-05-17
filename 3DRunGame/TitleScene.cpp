#include "TitleScene.h"
#include "InputManager.h"
#include "define.h"

TitleScene::TitleScene() 
{
	ArrowPosY = 0;
	CountFrame = 0;
	AreaX = 0;
	Speed = 3;
	MoovSpeed = 10;
	PlayerX = 60;
	PlayerY = GroundCoordinate;
}

TitleScene::~TitleScene() 
{
}

void TitleScene::Init()
{
}

void TitleScene::Update()
{
	/*計算処理*/
		//Input Down.
	if (InputDown())
	{
		if (ArrowPosY == 0)
		{
			ArrowPosY = 60;
		}
		else if (ArrowPosY == 60 && ArrowPosY > 120)
		{
			ArrowPosY = 0;
		}
		else
		{
			ArrowPosY = 120;
		}
	}
	//Input Up.
	if (InputUp())
	{
		if (ArrowPosY == 120)
		{
			ArrowPosY = 60;
		}
		else if (ArrowPosY == 60 && ArrowPosY < 120)
		{
			ArrowPosY = 0;
		}
		else
		{
			ArrowPosY = 120;
		}
	}

	/*タイマ更新*/
	CountFrame++;
	if (CountFrame > 380) { CountFrame = 0; }//一定以上数が増えたら初期化(数は適当)

	/*Draw処理*/
	//裏画面の初期化
	ClearDrawScreen();

	if (CountFrame == 120)
	{
		EnemyPos.x = EnemyStart;
		EnemyPos.y = 600;
	}
	if (CountFrame == 280)
	{
		EnemyPos1.x = EnemyStart;
		EnemyPos1.y = EnemyUp2;
	}
	if (CountFrame == 280)
	{
		EnemyPos2.x = EnemyStart;
		EnemyPos2.y = 600;
	}

	// エネミーの移動速度
	EnemyPos.x -= MoovSpeed;
	EnemyPos1.x -= MoovSpeed;
	EnemyPos2.x -= MoovSpeed;

	const float SinSpeed = 0.1f;
	const float AnimationSize = 8.0f;
	static float AnimationHeight = 0.0f;	// プレイヤーが弾んでいるようにアニメーションしているよう見せるための高さ値
	static float SinCount = 0;
	SinCount += SinSpeed;
	AnimationHeight = sinf(SinCount) * AnimationSize;		// 決まった数値だけ高さを増やしてあげる
	// プレイヤーの描画
	DrawExtendGraph(PlayerX, PlayerY - AnimationHeight, PlayerX + PlayerW, PlayerY + PlayerH, PlayerGraph, TRUE);
	// エネミーの描画
	DrawExtendGraph(EnemyPos.x, EnemyPos.y - AnimationHeight, EnemyPos.x + EnemyW, EnemyPos.y + EnemyH, EnemyGraph, TRUE);
	DrawExtendGraph(EnemyPos1.x, EnemyPos1.y - AnimationHeight, EnemyPos1.x + EnemyW, EnemyPos1.y + EnemyH, EnemyGraph, TRUE);
	DrawExtendGraph(EnemyPos2.x, EnemyPos2.y - AnimationHeight, EnemyPos2.x + EnemyW, EnemyPos2.y + EnemyH, EnemyGraph, TRUE);
	// タイトルの描画
	DrawGraph(0, 0, TitleGraph, true);
	DrawGraph(0, 0, ChangeSceenGraph, true);
	DrawGraph(0, 0, ChangeSceen2Graph, true);


	AreaX += Speed;
	if (AreaX > EnemyStart)
	{
		AreaX = 0;
	}

	// 落下処理
	PlayerY -= JumpPower;
	PlayerY -= JumpPower1;

	// 落下加速度付加
	JumpPower -= 0.5;
	JumpPower1 -= 0.5;

	// プレイヤーが画面下端からはみ出そうになっていたら画面内の座標に戻してあげる
	if (PlayerY > 720 - 64) PlayerY = 720 - 64;
	// プレイヤーが画面天井からはみ出そうになっていたら画面内の座標に戻してあげる
	if (PlayerY < 0 + 64) PlayerY = 0 + 64;

	// もし地面についていたら止まる
	if (PlayerY > GroundCoordinate)
	{
		PlayerY = GroundCoordinate;
		JumpPower = 0;
		JumpPower1 = 0;
	}
	// タイトルデモのジャンプタイミング
	if (CountFrame == 220)JumpPower = 24;
	if (CountFrame == 375)JumpPower1 = 29;

	//矢印表示(点滅させる)
	if ((CountFrame % 60) < 32)
	{
		DrawGraph(0, ArrowPosY, ArrowGraph, true);
	}
}

void TitleScene::Draw()
{
}