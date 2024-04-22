#include "define.h"
#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    Enemy();
    ~Enemy();
    void Init();
    void Update();
    void Draw();

    // エネミー構造体
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

    // テロップ構造体
    VECTOR TelopPos1;
    VECTOR TelopPos2;
private:
    int x, y;
    int width, height;
    int Speed;
    int EnemyGraph;
    int EnemyNum;
    int MoovSpeed;


};

#endif // ENEMY_H
