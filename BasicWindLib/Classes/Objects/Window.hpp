#ifndef UNICODE
#define UNICODE

#endif

#ifndef WINDPLUSPLUS_HPP
#define WINDPLUSPLUS_HPP

#include "SourceWindow.hpp"
#include "../Tools/Cursor.hpp"
#include "../Tools/TextHandler.hpp"

#include <d2d1.h>
#include <iostream>
#include <vector>

class Window : public SourceWindow{
public : 
    const LPCSTR ClassName();
    Window(HINSTANCE hInstance, int nCmdShow);
    ~Window();
    ID2D1HwndRenderTarget* getRenderTarget();
    void drawShape();

private :
    ID2D1Factory *m_factory;
    ID2D1HwndRenderTarget *m_render_target;
    ID2D1SolidColorBrush *m_brush;
    Cursor m_cursor;

    //Tmp
    void CalculateLayout();
    void Resize();
    void DiscardGraphicResources();
    HRESULT CreateGraphicResources();
    LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    int WindowCreated();
};


#endif