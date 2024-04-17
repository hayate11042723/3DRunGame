#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy();
    void Initialize();
    void Update();
    void Draw();
    bool CheckCollision(int x, int y);
    // 他のメンバやメソッドを追加する可能性があります
private:
    int x, y;
    int width, height;
    int speed;
    // 他のメンバ変数を追加する可能性があります
};

#endif // ENEMY_H
