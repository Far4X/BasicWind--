#ifndef UNICODE
#define UNICODE

#endif

#ifndef MAINWINDPLUSPLUS
#define MAINWINDPLUSPLUS

#include "Window.hpp"
#include <d2d1.h>
#include <iostream>

#pragma comment(lib, "d2d1")

#include "basewin.hpp"

class MainWindow : public BaseWindow<MainWindow> {
public : 
    MainWindow();
    ~MainWindow();
    MainWindow() : m_Factory(NULL), m_RenderTarget(NULL), m_Brush(NULL){}

    PCWSTR  ClassName() const { return L"Circle Window Class"; }
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
private :
    ID2D1Factory *m_Factory;
    ID2D1HwndRenderTarget *m_RenderTarget;
    ID2D1SolidColorBrush *m_Brush;
    D2D1_ELLIPSE m_ellipse;

    void CalculateLayout();
    HRESULT CreateGraphicsResources();
    void DiscardGraphicsResources();
    void OnPaint();
    void Resize();
};


#endif