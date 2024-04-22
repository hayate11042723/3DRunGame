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

    // �G�l�~�[�\����
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

    // �e���b�v�\����
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
