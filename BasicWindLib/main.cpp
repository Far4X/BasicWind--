#include <windows.h>
#include "Classes/Objects/Window.hpp"
#include "Classes/Objects/Shapes/Circle.hpp"
#include "Classes/Objects/Shapes/Rect.hpp"
#include "Classes/Objects/Shapes/RoundedRect.hpp"
#include "Classes/Objects/Button.hpp"



#include <iostream>

void printHello(){
    std::cout << "BTN CLKD" << std::endl;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    Window *ptr_win = new Window(hInstance, nCmdShow);
    float pos[2] = {100.0, 100.0};
    float color[3] = {255, 0, 0};

    Circle test_cicrle(ptr_win, pos, 100, color);

    float pos2[2] = {300.0, 100.0};
    float color2[3] = {0, 300, 0};
    float size[2] = {200, 100};
    float ellipse[2] = {10, 10};


    RoundedRect test_rect(ptr_win, pos, size, ellipse, color2);

    float pos3[2] = {200.0, 200.0};
    float color3[3] = {150, 150, 150};
    float size3[2] = {100, 50};

    Button test_button(ptr_win, pos3, size3, color3, printHello);

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
