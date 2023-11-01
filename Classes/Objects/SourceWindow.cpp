#include "SourceWindow.hpp"
#include <iostream>


SourceWindow::SourceWindow(int nCmdShow){
    m_dwExStyle = 0;
    m_x = CW_USEDEFAULT;
    m_y = CW_USEDEFAULT;
    m_width = CW_USEDEFAULT;
    m_height = CW_USEDEFAULT;
    m_handler_window_parent = 0;
    m_hMenu = 0;

    WNDCLASS WindowClass = {0};

    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = GetModuleHandle(NULL);
    WindowClass.lpszClassName = ClassName();

    RegisterClass(&WindowClass);

    c_list_source_windows.push_back(this);

    m_handler_window = CreateWindowEx(m_dwExStyle, ClassName(), m_lpWindowName, m_dwStyle, m_x, m_y,
        m_width, m_height, m_handler_window_parent, m_hMenu, GetModuleHandle(NULL), this);
    
    ShowWindow(m_handler_window, nCmdShow);
}

LRESULT SourceWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    if (uMsg == WM_NCCREATE){
        std::cout << "Creating window. Code deleted here." << std::endl;
        //Code related to CreateParams. Check if missing params if error. It may occurs here.
    }
    SourceWindow* ptr_this = getThis(hwnd);
    if (ptr_this != nullptr){
        return ptr_this->HandleMessage(uMsg, wParam, lParam);
    }
    else {
        return DefWindowProc(hwnd, uMsg, wParam, lParam);
    }
}

SourceWindow* SourceWindow::getThis(HWND handler_target){
    SourceWindow *ptr_target = nullptr;
    for (int i = 0; i < c_list_source_windows.size(); i++){
        if (c_list_source_windows[i]->getHandler() == handler_target){
            ptr_target = c_list_source_windows[i];
        }
    }
    return ptr_target;
}
