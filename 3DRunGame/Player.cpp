#include "Player.h"
#include "Enemy.h"

Player::Player() {
    // �R���X�g���N�^�̎���
}

Player::~Player()
{
}

void Player::Init() {
    // �����������̎���
    JumpHeight = 24;
    JumpHeight1 = 15;

	CountFrame = 0;

    // �O���t�B�b�N�wplayer.png�x���������Ƀ��[�h
    PlayerGraph = LoadGraph("image/player.png");
    GetGraphSize(PlayerGraph, &PlayerW, &PlayerH);

    // �L�����N�^�[�̏����f�[�^���Z�b�g
    PlayerX = 60;
    PlayerY = GroundCoordinate;

    JumpNum = 0;
}

void Player::Update() {
    // �X�V�����̎���
	// ��������
	PlayerY -= JumpPower;
	PlayerY -= JumpPower1;
	//PlayerY -= JumpPower2;

	//���������x�t��
	JumpPower -= 0.8f;
	JumpPower1 -= 0.9f;

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
		JumpNum = 0;
		CountFrame = 0;
	}

	CountFrame++;

	// �v���C���[�̃W�����v����
	{
		if (PlayerY == GroundCoordinate)
		{
			if (InputJump1())
			{
				JumpPower = JumpHeight;
				JumpNum = 1;
				// �ǂ݂��񂾉����o�b�N�O���E���h�Đ����܂�(�wPlaySoundMem�x�֐��g�p)
				PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
			}
		}

		if (InputJump2())
		{
			if (JumpNum == 1 && CountFrame >= 8)
			{
				JumpPower1 = JumpHeight1;
				JumpNum = 2;
				// �ǂ݂��񂾉����o�b�N�O���E���h�Đ����܂�(�wPlaySoundMem�x�֐��g�p)
				PlaySoundMem(SeHandle, DX_PLAYTYPE_BACK);
			}
		}
	}
}

void Player::Draw() {
    // �`�揈���̎���
	// �X���C���̒e��ł郂�[�V����
	const float SinSpeed = 0.1f;
	const float AnimationSize = 8.0f;
	static float AnimationHeight = 0.0f;	// �X���C�����e��ł���悤�ɃA�j���[�V�������Ă���悤�����邽�߂̍����l
	static float SinCount = 0;
	SinCount += SinSpeed;
	AnimationHeight = sinf(SinCount) * AnimationSize;		// ���܂������l���������𑝂₵�Ă�����

	// �v���C���[��`�悷��
	DrawExtendGraph(PlayerX, PlayerY - AnimationHeight, PlayerX + PlayerW, PlayerY + PlayerH, PlayerGraph, TRUE);
}

bool Player::CheckCollision(int x, int y) {
    // �Փ˔��菈���̎���
	// �v���C���[�摜�ƓG�摜�œ����蔻��
	{
		if (PlayerX + IMAGE_SIZE >= EnemyPos.x && PlayerX <= EnemyPos.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos.y && PlayerY <= EnemyPos.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos1.x && PlayerX <= EnemyPos1.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos1.y && PlayerY <= EnemyPos1.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos2.x && PlayerX <= EnemyPos2.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos2.y && PlayerY <= EnemyPos2.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos3.x && PlayerX <= EnemyPos3.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos3.y && PlayerY <= EnemyPos3.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
		if (PlayerX + IMAGE_SIZE >= EnemyPos4.x && PlayerX <= EnemyPos4.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos4.y && PlayerY <= EnemyPos4.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos5.x && PlayerX <= EnemyPos5.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos5.y && PlayerY <= EnemyPos5.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos6.x && PlayerX <= EnemyPos6.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos6.y && PlayerY <= EnemyPos6.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos7.x && PlayerX <= EnemyPos7.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos7.y && PlayerY <= EnemyPos7.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos8.x && PlayerX <= EnemyPos8.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos8.y && PlayerY <= EnemyPos8.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}if (PlayerX + IMAGE_SIZE >= EnemyPos9.x && PlayerX <= EnemyPos9.x + IMAGE_SIZE) {
			if (PlayerY + IMAGE_SIZE >= EnemyPos9.y && PlayerY <= EnemyPos9.y + IMAGE_SIZE) {
				// ����������v���C���[���f���[�g
				DeleteGraph(PlayerGraph);
				return GAMEOVERSCENE;
			}
		}
	}
}
