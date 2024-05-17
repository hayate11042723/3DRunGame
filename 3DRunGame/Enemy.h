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

private:
    int x, y;
    int width, height;
    int Speed;
    int EnemyGraph;
    int EnemyNum;
    int MoovSpeed;


};

#endif // ENEMY_H
