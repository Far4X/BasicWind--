#ifndef SOURCEWINDOW_HPP
#define SOURCEWINDOW_HPP

#include <windows.h>
#include <vector>

class SourceWindow{
    public :
        SourceWindow(int nCmdShow);
        ~SourceWindow();

    private :
        LPCWSTR m_lpWindowName;
        DWORD m_dwStyle;
        DWORD m_dwExStyle;
        int m_x;
        int m_y ;
        int m_width;
        int m_height;
        HWND m_handler_window_parent;
        HWND m_handler_window;
        HMENU m_hMenu;
        static std::vector<SourceWindow*> c_list_source_windows;

    protected :
        virtual LPCWSTR ClassName();
        virtual LRESULT HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);
        static SourceWindow* getThis(HWND handler_target);
        static LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
        HWND getHandler();

        HWND m_hanlder_window;
};

#endif