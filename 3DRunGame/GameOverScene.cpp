#include "GameOverScene.h"

    // �R���X�g���N�^�̎���
GameOverScene::GameOverScene() {
}

    // �����������̎���
void GameOverScene::Init() {
	ArrowPosY = 0;
	CountFrame = 0;
}

    // �X�V�����̎���
void GameOverScene::Update() {
	/*�v�Z����*/
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

	/*�^�C�}�X�V*/
	CountFrame++;
	if (CountFrame > 80000) { CountFrame = 0; }//���ȏ㐔���������珉����(���͓K��)

	/*Draw����*/
	//����ʂ̏�����
	ClearDrawScreen();

	// �Q�[���I�[�o�[��ʂ̕`��
	DrawGraph(0, 0, GameOverGraph, true);
	DrawGraph(0, 0, GameOverTxtGraph, true);

	// ���̕`��
	if ((CountFrame % 60) < 32)
	{
		DrawGraph(0, ArrowPosY, ArrowGraph, true);
	}

	// �Q�[���I�[�o�[���̌o�ߎ��Ԃ̕\��
	{
		Cr1 = GetColor(255, 200, 20);
		Cr2 = GetColor(0, 0, 0);
		SetFontSize(68);
		ChangeFont("HG�n�p�p�߯�ߑ�");
		ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);
		DrawFormatString(105, 305, Cr2, "�o�ߎ���");
		DrawFormatString(185, 385, Cr2, "%d�b", Time / 1000);
		DrawFormatString(100, 300, Cr1, "�o�ߎ���");
		DrawFormatString(180, 380, Cr1, "%d�b", Time / 1000);
	}

	ScreenFlip();
}

    // �`�揈���̎���
void GameOverScene::Draw() {
}
