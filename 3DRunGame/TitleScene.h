#pragma once
#include "Enemy.h"

#ifndef TITLESCENE_H
#define TITLESCENE_H

class TitleScene 
{
public:
    TitleScene();
    ~TitleScene();
    void Init();
    void Update();
    void Draw();

private:
	int ArrowPosY;
	int CountFrame;
	int AreaX;
	int Speed ;
	int EnemyGraph;
	int MoovSpeed;
};
#endif 