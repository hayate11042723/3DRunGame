#include"define.h"
#ifndef GAMECLEARSCENE_H
#define GAMECLEARSCENE_H

class GameClearScene {
public:
    GameClearScene();
    void Init();
    void Update();
    void Draw();
   
private:
    int ArrowPosY;
    int CountFrame;
    int AreaX;
    int Speed;
};

#endif // GAMECLEARSCENE_H
