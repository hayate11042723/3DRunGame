#include "GameClearScene.h"

GameClearScene::GameClearScene() {
    // �R���X�g���N�^�̎���
}

void GameClearScene::Init() {
    // �����������̎���
    ArrowPosY = 10;
    CountFrame = 0;
}

void GameClearScene::Update() {
    // �X�V�����̎���
		/*�^�C�}�X�V*/
	CountFrame++;
	if (CountFrame > 80000) { CountFrame = 0; }//���ȏ㐔���������珉����(���͓K��)

	/*Draw����*/
	//����ʂ̏�����
	ClearDrawScreen();

	// �Q�[���N���A��ʂ̕`��
	DrawGraph(0, 0, MountainGraph, true);
	DrawGraph(0, 0, GraundGraph, true);
	DrawGraph(0, 0, ClearGraph, true);

	// �X���C���̏u���̕`��
	if ((CountFrame % 100) < 97)
	{
		DrawGraph(0, 0, SlimeAyeGraph, true);
	}
	else
	{
		DrawGraph(0, 0, SlimeAye2Graph, true);
	}
	// �N���A��ʂ̃e�L�X�g�`��
	DrawGraph(0, 0, GameClearTxtGraph, true);

	if ((CountFrame % 60) < 32)
	{
		DrawGraph(-10, ArrowPosY, ArrowGraph, true);
	}

	ScreenFlip();

	/*�V�[���J�ڏ���*/
	//�G���^�[�ŃV�[���ύX
	if (ConfirmButton())
	{
		if (ArrowPosY == 10)
		{
			return TITLESCENE;
		}
	}
}

void GameClearScene::Draw() {
    // �`�揈���̎���
}
