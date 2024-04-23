#include "define.h"
#ifndef GAMEOVERSCENE_H
#define GAMEOVERSCENE_H

class GameOverScene {
public:
    GameOverScene();
    void Init();
    void Update();
    void Draw();

private:
    int ArrowPosY;
    int CountFrame;

};

#endif // GAMEOVERSCENE_H
