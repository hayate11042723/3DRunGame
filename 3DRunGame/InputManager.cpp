#include "InputManager.h"
#include <DxLib.h>

InputManager::InputManager() {}

InputManager::~InputManager() {}

bool InputManager::IsInputEnterHold() {
    return CheckHitKey(KEY_INPUT_RETURN) != 0;
}

bool InputManager::IsInputUpHold() {
    return CheckHitKey(KEY_INPUT_UP) != 0;
}