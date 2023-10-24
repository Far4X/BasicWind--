#ifndef UNICODE
#define UNICODE
#endif 

#include <windows.h>
#include <iostream>
#include <wingdi.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int nCmdShow)
{
    // Register the window class.
    const wchar_t CLASS_NAME[]  = L"Sample Window Class";
    
    WNDCLASS WindowClass = { };

    WindowClass.lpfnWndProc   = WindowProc;
    WindowClass.hInstance     = hInstance;
    WindowClass.lpszClassName = CLASS_NAME;

    RegisterClass(&WindowClass);

    // Create the window.

    HWND HandlerWindow = CreateWindowEx(
        1,                              // Optional window styles.
        CLASS_NAME,                     // Window class
        L"Test window",    // Window text
        WS_OVERLAPPEDWINDOW,            // Window style

        // Size and position
        CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,

        NULL,       // Parent window    
        NULL,       // Menu
        hInstance,  // Instance handle
        NULL        // Additional application data
        );

    if (HandlerWindow == NULL)
    {
        return 0;
    }

    ShowWindow(HandlerWindow, nCmdShow);

    // Run the message loop.

    MSG msg = { };
    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {   
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProc(HWND HandlerWindow, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch (uMsg) {
        case WM_CLOSE : {
            if(MessageBoxW(HandlerWindow, L"Quit ?", L"My app 2", MB_OKCANCEL) == IDOK){
                std::cerr << "Quitter." << std::endl;
                DestroyWindow(HandlerWindow);
            }   
            else {
                std::cerr << "La feinte" << std::endl;
            }
            return 0;
        }
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;

        case WM_PAINT:
            {
                PAINTSTRUCT ps;
                HDC hdc = BeginPaint(HandlerWindow, &ps);

                // All painting occurs here, between BeginPaint and EndPaint.
                std::cout << "Painting" << std::endl;
                FillRect(hdc, &ps.rcPaint, (HBRUSH) (COLOR_WINDOW + 1));

                EndPaint(HandlerWindow, &ps);
                return 0;

            }
        case WM_LBUTTONDOWN:{
            std::cout << "Left" << std::endl;         
            return 0;
        }
        case WM_RBUTTONDOWN:{
            std::cout << "Right" << std::endl;
            return 0;
        }

    }
    return DefWindowProc(HandlerWindow, uMsg, wParam, lParam);
}