#ifndef UNICODE
#define UNICODE

#endif

#ifndef WINDPLUSPLUS
#define WINDPLUSPLUS

#include "SourceWindow.hpp"

#include <d2d1.h>
#include <iostream>

class Window : public SourceWindow{
public : 
    const LPCSTR ClassName();
    Window(HINSTANCE hInstance, int nCmdShow);
    ~Window();

private :
    ID2D1Factory *m_factory;
    ID2D1HwndRenderTarget *m_render_target;
    ID2D1SolidColorBrush *m_brush;

    //Tmp
    D2D1_ELLIPSE m_ellipse;

    void CalculateLayout();
    void OnPaint();
    void Resize();
    void DiscardGraphicResources();
    HRESULT CreateGraphicResources();
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    int WindowCreated();
};


#endif