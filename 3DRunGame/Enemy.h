#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy();
    void Initialize();
    void Update();
    void Draw();
    bool CheckCollision(int x, int y);
    // ���̃����o�⃁�\�b�h��ǉ�����\��������܂�
private:
    int x, y;
    int width, height;
    int speed;
    // ���̃����o�ϐ���ǉ�����\��������܂�
};

#endif // ENEMY_H
