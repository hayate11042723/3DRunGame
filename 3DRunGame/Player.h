#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    void Initialize();
    void Update();
    void Draw();
    bool CheckCollision(int x, int y);
    // ���̃����o�⃁�\�b�h��ǉ�����\��������܂�
private:
    int x, y;
    int width, height;
    int jumpPower, jumpPower2;
    int PlayerX, PlayerY;
    int PlayerH, PlayerW;
    int PlayerGraph;
    // ���̃����o�ϐ���ǉ�����\��������܂�
};

#endif // PLAYER_H
