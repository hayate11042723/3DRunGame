#include "Enemy.h"

Enemy::Enemy() {
    // コンストラクタの実装
}

Enemy::~Enemy(){
    // デストラクタの実装
}

void Enemy::Init() {
    // 初期化処理の実装
    Speed = 3;
	MoovSpeed = 10;

    // グラフィック『enemy.png』をメモリにロード
    EnemyGraph = LoadGraph("image/enemy.png");
    GetGraphSize(EnemyGraph, &EnemyW, &EnemyH);
    EnemyNum = 0;

	// エネミーの初期化
	EnemyPos.x = Initialization;
	EnemyPos.y = Initialization;

	EnemyPos1.x = Initialization;
	EnemyPos1.y = Initialization;

	EnemyPos2.x = Initialization;
	EnemyPos2.y = Initialization;

	EnemyPos3.x = Initialization;
	EnemyPos3.y = Initialization;

	EnemyPos4.x = Initialization;
	EnemyPos4.y = Initialization;

	EnemyPos5.x = Initialization;
	EnemyPos5.y = Initialization;

	EnemyPos6.x = Initialization;
	EnemyPos6.y = Initialization;

	EnemyPos7.x = Initialization;
	EnemyPos7.y = Initialization;

	EnemyPos8.x = Initialization;
	EnemyPos8.y = Initialization;

	EnemyPos9.x = Initialization;
	EnemyPos9.y = Initialization;

	// テロップの初期化
	TelopPos1.x = Initialization;
	TelopPos1.y = Initialization;

	TelopPos2.x = Initialization;
	TelopPos2.y = Initialization;
}

void Enemy::Update() {
    // 更新処理の実装
	// エネミーの出現処理
	{
		if (EnemyNum == 0 && Time >= 0) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 1 && Time >= 3000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 2 && Time >= 6000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 3 && Time >= 8000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 4 && Time >= 10000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 5 && Time >= 12000) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 6 && Time >= 12000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 7 && Time >= 14000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 8 && Time >= 14000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 9 && Time >= 16000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 10 && Time >= 16000) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 11 && Time >= 18000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 12 && Time >= 18000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 13 && Time >= 20000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 14 && Time >= 20000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 15 && Time >= 22000) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 16 && Time >= 24000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 17 && Time >= 24000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 18 && Time >= 26000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 19 && Time >= 28000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 20 && Time >= 28000) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 21 && Time >= 30000) {
			TelopPos1.x = 690;
			TelopPos1.y = 0;
			EnemyNum++;
		}
		if (EnemyNum == 22 && Time >= 33000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 23 && Time >= 33000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 24 && Time >= 33000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 25 && Time >= 34000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 26 && Time >= 34000) {
			EnemyPos5.x = EnemyStart;
			EnemyPos5.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 27 && Time >= 35000) {
			EnemyPos6.x = EnemyStart;
			EnemyPos6.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 28 && Time >= 36000) {
			EnemyPos7.x = EnemyStart;
			EnemyPos7.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 29 && Time >= 36000) {
			EnemyPos8.x = EnemyStart;
			EnemyPos8.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 30 && Time >= 37000) {
			EnemyPos9.x = EnemyStart;
			EnemyPos9.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 31 && Time >= 37000) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 32 && Time >= 38000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 33 && Time >= 39000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 34 && Time >= 39000) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 35 && Time >= 41000) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 36 && Time >= 41000) {
			EnemyPos5.x = EnemyStart;
			EnemyPos5.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 37 && Time >= 42000) {
			EnemyPos6.x = EnemyStart;
			EnemyPos6.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 38 && Time >= 42000) {
			EnemyPos7.x = EnemyStart;
			EnemyPos7.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 39 && Time >= 43000) {
			EnemyPos8.x = EnemyStart;
			EnemyPos8.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 40 && Time >= 43000) {
			EnemyPos9.x = EnemyStart;
			EnemyPos9.y = EnemyUp1;
			EnemyNum++;
		}
		if (EnemyNum == 41 && Time >= 45000) {
			TelopPos2.x = 690;
			TelopPos2.y = 0;
			EnemyNum++;
		}
		if (EnemyNum == 42 && Time >= 45000) {
			TelopPos2.x = 690;
			TelopPos2.y = 0;
			EnemyNum++;
		}
		if (EnemyNum == 43 && Time >= 47000) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 44 && Time >= 47000) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 45 && Time >= 47850) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 46 && Time >= 47850) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 47 && Time >= 48700) {
			EnemyPos5.x = EnemyStart;
			EnemyPos5.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 48 && Time >= 49550) {
			EnemyPos6.x = EnemyStart;
			EnemyPos6.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 49 && Time >= 49550) {
			EnemyPos7.x = EnemyStart;
			EnemyPos7.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 50 && Time >= 50400) {
			EnemyPos8.x = EnemyStart;
			EnemyPos8.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 51 && Time >= 50400) {
			EnemyPos9.x = EnemyStart;
			EnemyPos9.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 52 && Time >= 51250) {
			EnemyPos.x = EnemyStart;
			EnemyPos.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 53 && Time >= 52100) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 54 && Time >= 52100) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 55 && Time >= 52950) {
			EnemyPos3.x = EnemyStart;
			EnemyPos3.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 56 && Time >= 52950) {
			EnemyPos4.x = EnemyStart;
			EnemyPos4.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 57 && Time >= 53800) {
			EnemyPos5.x = EnemyStart;
			EnemyPos5.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 58 && Time >= 54650) {
			EnemyPos6.x = EnemyStart;
			EnemyPos6.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 59 && Time >= 54650) {
			EnemyPos7.x = EnemyStart;
			EnemyPos7.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 60 && Time >= 55500) {
			EnemyPos8.x = EnemyStart;
			EnemyPos8.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 61 && Time >= 55500) {
			EnemyPos9.x = EnemyStart;
			EnemyPos9.y = EnemyUp2;
			EnemyNum++;
		}
		if (EnemyNum == 62 && Time >= 56350) {
			EnemyPos1.x = EnemyStart;
			EnemyPos1.y = GroundCoordinate;
			EnemyNum++;
		}
		if (EnemyNum == 63 && Time >= 56350) {
			EnemyPos2.x = EnemyStart;
			EnemyPos2.y = EnemyUp2;
			EnemyNum++;
		}
	}

	// テロップの移動処理
	{
		TelopPos1.x -= MoovSpeed;
		TelopPos2.x -= MoovSpeed;
		}

	// エネミーの移動処理
	{
		EnemyPos.x -= MoovSpeed;
		EnemyPos1.x -= MoovSpeed;
		EnemyPos2.x -= MoovSpeed;
		EnemyPos3.x -= MoovSpeed;
		EnemyPos4.x -= MoovSpeed;
		EnemyPos5.x -= MoovSpeed;
		EnemyPos6.x -= MoovSpeed;
		EnemyPos7.x -= MoovSpeed;
		EnemyPos8.x -= MoovSpeed;
		EnemyPos9.x -= MoovSpeed;
	}
}

void Enemy::Draw() {
    // 描画処理の実装
		// テロップを描画する
	DrawGraph(TelopPos1.x, TelopPos1.y, Telop1Graph, true);
	DrawGraph(TelopPos2.x, TelopPos2.y, Telop2Graph, true);

	// スライムの弾んでるモーション
	const float SinSpeed = 0.1f;
	const float AnimationSize = 8.0f;
	static float AnimationHeight = 0.0f;	// スライムが弾んでいるようにアニメーションしているよう見せるための高さ値
	static float SinCount = 0;
	SinCount += SinSpeed;
	AnimationHeight = sinf(SinCount) * AnimationSize;		// 決まった数値だけ高さを増やしてあげる

	// エネミーを描画する
	{
		DrawExtendGraph(EnemyPos.x, EnemyPos.y - AnimationHeight, EnemyPos.x + EnemyW, EnemyPos.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos1.x, EnemyPos1.y - AnimationHeight, EnemyPos1.x + EnemyW, EnemyPos1.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos2.x, EnemyPos2.y - AnimationHeight, EnemyPos2.x + EnemyW, EnemyPos2.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos3.x, EnemyPos3.y - AnimationHeight, EnemyPos3.x + EnemyW, EnemyPos3.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos4.x, EnemyPos4.y - AnimationHeight, EnemyPos4.x + EnemyW, EnemyPos4.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos5.x, EnemyPos5.y - AnimationHeight, EnemyPos5.x + EnemyW, EnemyPos5.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos6.x, EnemyPos6.y - AnimationHeight, EnemyPos6.x + EnemyW, EnemyPos6.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos7.x, EnemyPos7.y - AnimationHeight, EnemyPos7.x + EnemyW, EnemyPos7.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos8.x, EnemyPos8.y - AnimationHeight, EnemyPos8.x + EnemyW, EnemyPos8.y + EnemyH, EnemyGraph, TRUE);
		DrawExtendGraph(EnemyPos9.x, EnemyPos9.y - AnimationHeight, EnemyPos9.x + EnemyW, EnemyPos9.y + EnemyH, EnemyGraph, TRUE);
	}
}
