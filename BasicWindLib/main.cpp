#include <windows.h>
#include "Classes/Objects/Window.hpp"
#include "Classes/Objects/Shapes/Circle.hpp"
#include "Classes/Objects/Shapes/Rect.hpp"
#include "Classes/Objects/Shapes/RoundedRect.hpp"



#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    Window *ptr_win = new Window(hInstance, nCmdShow);
    float pos[2] = {100.0, 100.0};
    float color[3] = {255, 0, 0};

    Circle test_cicrle(ptr_win, pos, 100, color);

    float pos2[2] = {300.0, 100.0};
    float color2[3] = {0, 300, 0};
    float sizer[2] = {200, 100};
    float ellipse[2] = {10, 10};


    RoundedRect test_rect(ptr_win, pos, sizer, ellipse, color2);

    ptr_win->addShapeToDraw(&test_cicrle);
    ptr_win->addShapeToDraw(&test_rect);
    ShowWindow((ptr_win->getHandler()), nCmdShow);

    // Run the message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
