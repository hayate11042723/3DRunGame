#pragma once

class InputManager {
public:
    InputManager();
    ~InputManager();

    bool IsInputEnterHold();
    bool IsInputUpHold();
    // 他のキー入力処理関数を追加
};