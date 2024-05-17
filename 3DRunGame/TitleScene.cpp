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
	/*�v�Z����*/
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

	/*�^�C�}�X�V*/
	CountFrame++;
	if (CountFrame > 380) { CountFrame = 0; }//���ȏ㐔���������珉����(���͓K��)

	/*Draw����*/
	//����ʂ̏�����
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

	// �G�l�~�[�̈ړ����x
	EnemyPos.x -= MoovSpeed;
	EnemyPos1.x -= MoovSpeed;
	EnemyPos2.x -= MoovSpeed;

	const float SinSpeed = 0.1f;
	const float AnimationSize = 8.0f;
	static float AnimationHeight = 0.0f;	// �v���C���[���e��ł���悤�ɃA�j���[�V�������Ă���悤�����邽�߂̍����l
	static float SinCount = 0;
	SinCount += SinSpeed;
	AnimationHeight = sinf(SinCount) * AnimationSize;		// ���܂������l���������𑝂₵�Ă�����
	// �v���C���[�̕`��
	DrawExtendGraph(PlayerX, PlayerY - AnimationHeight, PlayerX + PlayerW, PlayerY + PlayerH, PlayerGraph, TRUE);
	// �G�l�~�[�̕`��
	DrawExtendGraph(EnemyPos.x, EnemyPos.y - AnimationHeight, EnemyPos.x + EnemyW, EnemyPos.y + EnemyH, EnemyGraph, TRUE);
	DrawExtendGraph(EnemyPos1.x, EnemyPos1.y - AnimationHeight, EnemyPos1.x + EnemyW, EnemyPos1.y + EnemyH, EnemyGraph, TRUE);
	DrawExtendGraph(EnemyPos2.x, EnemyPos2.y - AnimationHeight, EnemyPos2.x + EnemyW, EnemyPos2.y + EnemyH, EnemyGraph, TRUE);
	// �^�C�g���̕`��
	DrawGraph(0, 0, TitleGraph, true);
	DrawGraph(0, 0, ChangeSceenGraph, true);
	DrawGraph(0, 0, ChangeSceen2Graph, true);


	AreaX += Speed;
	if (AreaX > EnemyStart)
	{
		AreaX = 0;
	}

	// ��������
	PlayerY -= JumpPower;
	PlayerY -= JumpPower1;

	// ���������x�t��
	JumpPower -= 0.5;
	JumpPower1 -= 0.5;

	// �v���C���[����ʉ��[����͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (PlayerY > 720 - 64) PlayerY = 720 - 64;
	// �v���C���[����ʓV�䂩��͂ݏo�����ɂȂ��Ă������ʓ��̍��W�ɖ߂��Ă�����
	if (PlayerY < 0 + 64) PlayerY = 0 + 64;

	// �����n�ʂɂ��Ă�����~�܂�
	if (PlayerY > GroundCoordinate)
	{
		PlayerY = GroundCoordinate;
		JumpPower = 0;
		JumpPower1 = 0;
	}
	// �^�C�g���f���̃W�����v�^�C�~���O
	if (CountFrame == 220)JumpPower = 24;
	if (CountFrame == 375)JumpPower1 = 29;

	//���\��(�_�ł�����)
	if ((CountFrame % 60) < 32)
	{
		DrawGraph(0, ArrowPosY, ArrowGraph, true);
	}
}

void TitleScene::Draw()
{
}