#ifndef UNICODE
#define UNICODE

#endif

#ifndef MAINWINDPLUSPLUS
#define MAINWINDPLUSPLUS

#include "Window.hpp"

#include <d2d1.h>
#include <iostream>

class MainWindow : public Window{
public : 
    MainWindow(HINSTANCE hInstance, int nCmdShow);
    ~MainWindow();
};


#endif