//
// Created by Malaya Shekhar on 12/07/24.
//

#pragma once

#include <iostream>
#include "window_manager.h"

class EventManager {
public:
    EventManager(WindowManager *windowManager);
    void update();

private:
    WindowManager *windowManager;
};
