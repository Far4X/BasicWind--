#include <windows.h>
#include "Classes/Objects/Window.hpp"
#include "Classes/Objects/Shapes/Circle.hpp"

#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    Window *ptr_win = new Window(hInstance, nCmdShow);
    float pos[2] = {100.0, 100.0};
    float color[3] = {255, 0, 0};

    Circle test_cicrle(ptr_win, pos, 100, color);
    std::cout << "Add win : " << ptr_win << std::endl;
    ptr_win->addShapeToDraw(&test_cicrle);
    ShowWindow((ptr_win->getHandler()), nCmdShow);
    std::cout << "Out of SW" << std::endl;

    // Run the message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
