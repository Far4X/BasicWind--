#ifndef WINDOWPLUSPLUS
#define WINDOWPLUSPLUS


#include <windows.h>
#include <wingdi.h>
#include <vector>


class Window {
public :
    Window(Window& parent);
    Window();
    ~Window();

private :
    std::vector<Window> m_childs;
    Window* m_parent = nullptr;
};

#endif