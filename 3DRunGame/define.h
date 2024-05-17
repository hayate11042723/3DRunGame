#pragma once
#include "DxLib.h"
#include "math.h"
#include "InputManager.h"

#define IMAGE_SIZE	50

// ����L�[�̒�`
int Key;
int Key1;
int Key2;

// �J���[�̒�`
int Cr1;
int Cr2;

// ���W�֘A
int GroundCoordinate = 600;
int EnemyStart = 1280;
int EnemyUp1 = 310;
int EnemyUp2 = 460;

// ����
int Time;

// �v���C���[�֘A�̒�`
int PlayerX, PlayerY;
int PlayerH, PlayerW;
int PlayerGraph;

// �G�l�~�[�T�C�Y�̒�`
int EnemyW, EnemyH;

// �e���b�v�̒�`
int Telop1Graph;
int Telop2Graph;

// �w�i�̒�`
int BackGraph;
int TitleGraph;
int TitleScrollGraph;
int ChangeSceenGraph;
int ChangeSceen2Graph;
int BackGlassGraph;

// �}�j���A����ʂ̕`���`
int ManualGraph;
int Manual2Graph;

// �Q�[���I�[�o�[��ʂ̕`���`
int GameOverGraph;
int GameOverTxtGraph;

// �N���A��ʂ̕`���`
int ClearGraph;
int GameClearTxtGraph;

// �w�i�f�ނ̕`���`
int SkyGraph;
int MountainGraph;
int GraundGraph;

// �u���̕`���`
int SlimeAyeGraph;
int SlimeAye2Graph;

// ���̒�`
int ArrowGraph;

// �T�E���h�n���h���̒�`
int BgmHandle;
int SeHandle;
int GameOverHandle;

// JumpPower�̒�`
float JumpPower;
float JumpPower1;

// �V�[��
constexpr int GAMEEND = 0;
constexpr int TITLESCENE = 1;
constexpr int MANUALSCENE = 2;
constexpr int STARTMANUALSCENE = 3;
constexpr int GAMESCENE = 4;
constexpr int GAMEOVERSCENE = 5;
constexpr int GAMECLEARSCENE = 6;

bool IsInputEnterHold = false;// InputEneter�p�̕ϐ�
bool IsInputUpHold = false;// InputUp�p�̕ϐ�
bool IsInputDownHold = false;// InputDown�p�̕ϐ�
bool IsInputJump1Hold = false;// InputJump1�p�̕ϐ�
bool IsInputJump2Hold = false;// InputJump2�p�̕ϐ�
bool IsInputJump3Hold = false;// InputJump3�p�̕ϐ�

// �L�[��{�^���̒�`
bool ConfirmButton();
bool InputUp();
bool InputDown();
bool InputJump1();
bool InputJump2();

XINPUT_STATE Input;

// ���W�̏������p
float Initialization = 800;

// �G�l�~�[�\����
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

// �e���b�v�\����
VECTOR TelopPos1;
VECTOR TelopPos2;