#include <vector>
#include "SourceWindow.hpp"
#include <iostream>


std::vector<SourceWindow*> SourceWindow::c_list_source_windows = {};

SourceWindow::SourceWindow(HINSTANCE hInstance, int nCmdShow){    
    m_dwExStyle = WS_OVERLAPPEDWINDOW;
    m_x = 100;
    m_y = 100;
    m_width = 500;
    m_height = 500;
    m_handler_window_parent = NULL;
    m_hMenu = NULL;

    WNDCLASS WindowClass = {0};

    WindowClass.lpfnWndProc = WindowProc;
    WindowClass.hInstance = hInstance;
    
    WindowClass.lpszClassName = "MainWindow";

    RegisterClass(&WindowClass);

    SourceWindow::c_list_source_windows.push_back(this);

    m_handler_window = CreateWindowEx(WS_EX_OVERLAPPEDWINDOW, "MainWindow", "Circle", WS_OVERLAPPEDWINDOW, m_x, m_y,
        m_width, m_height, m_handler_window_parent, m_hMenu, hInstance, NULL);


    ShowWindow(m_handler_window, nCmdShow);

    std::cout << "Created Window" << std::endl;
}

SourceWindow::~SourceWindow(){

}

LRESULT SourceWindow::WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
    std::cout << "In windowproc. Message is " << uMsg << std::endl;

    SourceWindow* ptr_this = SourceWindow::getThis(hwnd);
;
    if (uMsg == WM_NCCREATE){
        CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
        ptr_this = nullptr;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ptr_this);
        std::cout << "Created ptr_this : " << ptr_this << " : " << c_list_source_windows[0] << std::endl;
    }

    std::cout << "Received message. ptr_this : " << ptr_this << std::endl;
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
        //std::cout << "Handler number " << i << " : " << c_list_source_windows[i]->getHandler() << std::endl;
        //std::cout << "Target : " <<handler_target << std::endl;
        if (c_list_source_windows[i]->getHandler() == handler_target){
            ptr_target = c_list_source_windows[i];
        }
    }
    return ptr_target;
}

const HWND SourceWindow::getHandler() {
    return m_handler_window;
}

const LPCSTR SourceWindow::ClassName(){
    return 0;
}

LRESULT SourceWindow::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam){
    return DefWindowProc(m_handler_window, uMsg, wParam, lParam);
}

int SourceWindow::WindowCreated(){
    std::cout << "Not here" << std::endl;
    return 0;
}