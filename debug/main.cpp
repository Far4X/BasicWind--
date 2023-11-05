#include <windows.h>
#include "Classes/Objects/Window.hpp"

#include <iostream>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    Window my_win(hInstance, nCmdShow);

    ShowWindow((my_win.getHandler()), SW_SHOWNORMAL);

    // Run the message loop.

    MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}
