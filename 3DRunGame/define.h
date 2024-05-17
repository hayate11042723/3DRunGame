#pragma once
#include "DxLib.h"
#include "math.h"
#include "InputManager.h"

#define IMAGE_SIZE	50

// 操作キーの定義
int Key;
int Key1;
int Key2;

// カラーの定義
int Cr1;
int Cr2;

// 座標関連
int GroundCoordinate = 600;
int EnemyStart = 1280;
int EnemyUp1 = 310;
int EnemyUp2 = 460;

// 時間
int Time;

// プレイヤー関連の定義
int PlayerX, PlayerY;
int PlayerH, PlayerW;
int PlayerGraph;

// エネミーサイズの定義
int EnemyW, EnemyH;

// テロップの定義
int Telop1Graph;
int Telop2Graph;

// 背景の定義
int BackGraph;
int TitleGraph;
int TitleScrollGraph;
int ChangeSceenGraph;
int ChangeSceen2Graph;
int BackGlassGraph;

// マニュアル画面の描画定義
int ManualGraph;
int Manual2Graph;

// ゲームオーバー画面の描画定義
int GameOverGraph;
int GameOverTxtGraph;

// クリア画面の描画定義
int ClearGraph;
int GameClearTxtGraph;

// 背景素材の描画定義
int SkyGraph;
int MountainGraph;
int GraundGraph;

// 瞬きの描画定義
int SlimeAyeGraph;
int SlimeAye2Graph;

// →の定義
int ArrowGraph;

// サウンドハンドルの定義
int BgmHandle;
int SeHandle;
int GameOverHandle;

// JumpPowerの定義
float JumpPower;
float JumpPower1;

// シーン
constexpr int GAMEEND = 0;
constexpr int TITLESCENE = 1;
constexpr int MANUALSCENE = 2;
constexpr int STARTMANUALSCENE = 3;
constexpr int GAMESCENE = 4;
constexpr int GAMEOVERSCENE = 5;
constexpr int GAMECLEARSCENE = 6;

bool IsInputEnterHold = false;// InputEneter用の変数
bool IsInputUpHold = false;// InputUp用の変数
bool IsInputDownHold = false;// InputDown用の変数
bool IsInputJump1Hold = false;// InputJump1用の変数
bool IsInputJump2Hold = false;// InputJump2用の変数
bool IsInputJump3Hold = false;// InputJump3用の変数

// キーやボタンの定義
bool ConfirmButton();
bool InputUp();
bool InputDown();
bool InputJump1();
bool InputJump2();

XINPUT_STATE Input;

// 座標の初期化用
float Initialization = 800;

// エネミー構造体
VECTOR EnemyPos;
VECTOR EnemyPos1;
VECTOR EnemyPos2;
VECTOR EnemyPos3;
VECTOR EnemyPos4;
VECTOR EnemyPos5;
VECTOR EnemyPos6;
VECTOR EnemyPos7;
VECTOR EnemyPos8;
VECTOR EnemyPos9;

// テロップ構造体
VECTOR TelopPos1;
VECTOR TelopPos2;