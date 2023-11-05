#include "MainWindow.hpp"

Window::Window(HINSTANCE hInstance, int nCmdShow) : SourceWindow(hInstance, nCmdShow){
    m_factory = NULL;
    m_render_target = NULL;
    m_brush = NULL;
    this->WindowCreated();
} ;

Window::~Window(){

}

LRESULT Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
    case WM_CREATE :
        return this->WindowCreated();

    case WM_DESTROY :
        this->DiscardGraphicResources();
        m_factory->Release();
        PostQuitMessage(0);

        return 0;

    case WM_PAINT :
        this->OnPaint();
        return 0;

    case WM_SIZE :
        this->Resize();
        return 0;

    case WM_NCMOUSEMOVE :
        return DefWindowProc(m_handler_window, uMsg, wParam, lParam);

    default:
        return DefWindowProc(m_handler_window, uMsg, wParam, lParam);
    }
}

const LPCSTR Window::ClassName(){
    LPCSTR output("MainWindow");
    return output;
}

void Window::Resize(){
    if (m_render_target != nullptr){
        RECT rect_app;
        
        GetClientRect(m_handler_window, &rect_app);
        D2D1_SIZE_U size = D2D1::SizeU(rect_app.right, rect_app.bottom);

        m_render_target->Resize(size);
        this->CalculateLayout();
        InvalidateRect(m_handler_window, NULL, FALSE);
    }
}

void Window::OnPaint(){
    HRESULT handler_result = this->CreateGraphicResources(); 
    if (SUCCEEDED(handler_result)){
        PAINTSTRUCT paint_struct;
        BeginPaint(m_handler_window, &paint_struct);

        m_render_target->BeginDraw();
        m_render_target->Clear(D2D1::ColorF(D2D1::ColorF::SkyBlue));
        m_render_target->FillEllipse(m_ellipse, m_brush);

        handler_result = m_render_target->EndDraw();
        if (FAILED(handler_result) || handler_result == D2DERR_RECREATE_TARGET){
            this->DiscardGraphicResources();
        }
        EndPaint(m_handler_window, &paint_struct);
    }
}

void Window::DiscardGraphicResources(){
    m_render_target->Release();
    m_brush->Release();
}

void Window::CalculateLayout(){
    if (m_render_target != NULL){
        D2D1_SIZE_F size = m_render_target->GetSize();
        const float x = size.width / 2;
        const float y = size.height / 2;
        float radius = 0;
        if (x < y){
            radius = x;
        }
        else {
            radius = y;
        }

        m_ellipse = D2D1::Ellipse(D2D1::Point2F(x, y), radius, radius);
    }
}

HRESULT Window::CreateGraphicResources(){
    HRESULT handler_result = S_OK;
    if (m_render_target == NULL){
        
        RECT rect_app;


        GetClientRect(m_handler_window, &rect_app);
        
        D2D1_SIZE_U size = D2D1::SizeU(rect_app.right, rect_app.bottom);
        handler_result = m_factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(m_handler_window, size), &m_render_target);
        if(SUCCEEDED(handler_result)){
            const D2D1_COLOR_F color = D2D1::ColorF(1.0f, 1.0f, 0);
            handler_result = m_render_target->CreateSolidColorBrush(color, &m_brush);
            if (SUCCEEDED(handler_result)){
                this->CalculateLayout();
            }
        }

    }
    return handler_result;
}


int Window::WindowCreated(){
    if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory))){
        return -1;
    }
    return 0;
}