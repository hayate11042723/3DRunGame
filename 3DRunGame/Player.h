#include "define.h"
#include "Enemy.h"

#ifndef PLAYER_H
#define PLAYER_H

class Enemy;

class Player {
public:
    Player();
    ~Player();
    void Init();
    void Update();
    void Draw();
    bool CheckCollision(int x, int y);

private:
    int width, height;
    int jumpPower, jumpPower2;
    int JumpNum;
    int JumpHeight;
    int JumpHeight1;
    int CountFrame;
};

#endif 
