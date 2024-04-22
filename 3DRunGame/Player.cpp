#include "Player.h"
#include "Enemy.h"

Player::Player() {
    // コンストラクタの実装
}

Player::~Player()
{
}

void Player::Init() {
    // 初期化処理の実装
    JumpHeight = 24;
    JumpHeight1 = 15;

	CountFrame = 0;

    // グラフィック『player.png』をメモリにロード
    PlayerGraph = LoadGraph("image/player.png");
    GetGraphSize(PlayerGraph, &PlayerW, &PlayerH);

    // キャラクターの初期データをセット
    PlayerX = 60;
    PlayerY = GroundCoordinate;

    JumpNum = 0;
}

void Player::Update() {
    // 更新処理の実装
	// 落下処理
	PlayerY -= JumpPower;
	PlayerY -= JumpPower1;
	//PlayerY -= JumpPower2;

	//落下加速度付加
	JumpPower -= 0.8f;
	JumpPower1 -= 0.9f;

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
		JumpNum = 0;
		CountFrame = 0;
	}

	CountFrame++;

	// プレイヤーのジャンプ処理
	{
		if (PlayerY == GroundCoordinate)
		{
			if (InputJump1())
			{
				JumpPower = JumpHeight;
				JumpNum = 1;
				// 読みこんだ音をバックグラウンド再生します(『PlaySoundMem』関数使用)
				PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
			}
		}

		if (InputJump2())
		{
			if (JumpNum == 1 && CountFrame >= 8)
			{
				JumpPower1 = JumpHeight1;
				JumpNum = 2;
				// 読みこんだ音をバックグラウンド再生します(『PlaySoundMem』関数使用)
				PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
			}
		}
	}
}

void Player::Draw() {
    // 描画処理の実装
	// スライムの弾んでるモーション
	const float SinSpeed = 0.1f;
	const float AnimationSize = 8.0f;
	static float AnimationHeight = 0.0f;	// スライムが弾んでいるようにアニメーションしているよう見せるための高さ値
	static float SinCount = 0;
	SinCount += SinSpeed;
	AnimationHeight = sinf(SinCount) * AnimationSize;		// 決まった数値だけ高さを増やしてあげる

	// プレイヤーを描画する
	DrawExtendGraph(PlayerX, PlayerY - AnimationHeight, PlayerX + PlayerW, PlayerY + PlayerH, PlayerGraph, TRUE);
}

bool Player::CheckCollision(int x, int y) {
    // 衝突判定処理の実装
	// プレイヤー画像と敵画像で当たり判定
	{
		if (PlayerX + IMAGE_SIZE >= EnemyPos.x && PlayerX <= EnemyPos.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos.y && PlayerY <= EnemyPos.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos1.x && PlayerX <= EnemyPos1.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos1.y && PlayerY <= EnemyPos1.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos2.x && PlayerX <= EnemyPos2.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos2.y && PlayerY <= EnemyPos2.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos3.x && PlayerX <= EnemyPos3.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos3.y && PlayerY <= EnemyPos3.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos4.x && PlayerX <= EnemyPos4.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos4.y && PlayerY <= EnemyPos4.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos5.x && PlayerX <= EnemyPos5.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos5.y && PlayerY <= EnemyPos5.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos6.x && PlayerX <= EnemyPos6.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos6.y && PlayerY <= EnemyPos6.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos7.x && PlayerX <= EnemyPos7.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos7.y && PlayerY <= EnemyPos7.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos8.x && PlayerX <= EnemyPos8.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos8.y && PlayerY <= EnemyPos8.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos9.x && PlayerX <= EnemyPos9.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos9.y && PlayerY <= EnemyPos9.y + IMAGE_SIZE) {
				// 当たったらプレイヤーをデリート
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
	}
}
