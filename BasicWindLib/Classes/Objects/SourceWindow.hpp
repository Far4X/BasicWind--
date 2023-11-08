#ifndef SOURCEWINDOW_HPP
#define SOURCEWINDOW_HPP

#include <windows.h>
#include <vector>
#include "Shapes/Shape.hpp"

class SourceWindow : public Shape{
    virtual int WindowCreated();
    virtual const LPCSTR ClassName();
    virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
    virtual ID2D1HwndRenderTarget* getRenderTarget();

    public :
        SourceWindow(HINSTANCE hInstance, int nCmdShow);
        ~SourceWindow();
        static std::vector<SourceWindow*> c_list_source_windows;
        const HWND getHandler();


    private :
        LPCSTR m_windowName;
        DWORD m_dwStyle;
        DWORD m_dwExStyle;
        int m_x;
        int m_y ;
        int m_width;
        int m_height;
        HWND m_handler_window_parent;
        HMENU m_hMenu;

    protected :
        static SourceWindow* getThis(HWND handler_target);
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        HWND m_handler_window = nullptr;
};

#endif