#include <vector>
#include "SourceWindow.hpp"
#include <iostream>


std::vector<SourceWindow*> SourceWindow::c_list_source_windows = {};

SourceWindow::SourceWindow(HINSTANCE hInstance, int nCmdShow) : Shape(){    
    m_dwExStyle = WS_OVERLAPPEDWINDOW;
    m_x = 100;
    m_y = 100;
    m_width = 500;
    m_height = 500;
    m_handler_window_parent = NULL;
    m_hMenu = NULL;
    m_nCmdShow = nCmdShow;

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
    SourceWindow* ptr_this = SourceWindow::getThis(hwnd);

    if (uMsg == WM_NCCREATE){
        CREATESTRUCT* pCreate = (CREATESTRUCT*)lParam;
        ptr_this = nullptr;
        SetWindowLongPtr(hwnd, GWLP_USERDATA, (LONG_PTR)ptr_this);
    }
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

ID2D1HwndRenderTarget* SourceWindow::getRenderTarget(){
    throw TypeError(6, "Shape has no render target");
    return NULL;
}

void SourceWindow::detectClick(int pos[2]){
    for (int i = 0; i < m_list_shapes.size(); i++){
        m_list_shapes[i]->detectClick(pos);
    }
}

Shape *SourceWindow::getWindow(){
    return this;
}