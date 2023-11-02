#ifndef UNICODE
#define UNICODE

#endif

#ifndef MAINWINDPLUSPLUS
#define MAINWINDPLUSPLUS

#include "SourceWindow.hpp"

#include <d2d1.h>
#include <iostream>

class MainWindow : public SourceWindow{
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    int WindowCreated();
public : 
    const LPCSTR ClassName();
    MainWindow(HINSTANCE hInstance, int nCmdShow);
    ~MainWindow();

private :
    ID2D1Factory *m_factory = nullptr;
    ID2D1HwndRenderTarget *m_render_target = nullptr;
    ID2D1SolidColorBrush *m_brush = nullptr;

    //Tmp
    D2D1_ELLIPSE m_ellipse;

    void CalculateLayout();
    void OnPaint();
    void Resize();
    void DiscardGraphicResources();
    HRESULT CreateGraphicResources();
};


#endif