#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    void Initialize();
    void Update();
    void Draw();
    bool CheckCollision(int x, int y);
    // 他のメンバやメソッドを追加する可能性があります
private:
    int x, y;
    int width, height;
    int jumpPower, jumpPower2;
    int PlayerX, PlayerY;
    int PlayerH, PlayerW;
    int PlayerGraph;
    // 他のメンバ変数を追加する可能性があります
};

#endif // PLAYER_H
