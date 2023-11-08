#include "MainWindow.hpp"

Window::Window(HINSTANCE hInstance, int nCmdShow) : SourceWindow(hInstance, nCmdShow){
    m_factory = NULL;
    m_render_target = NULL;
    m_brush = NULL;
    this->WindowCreated();
} ;

Window::~Window(){
    m_render_target->Release();
}

LRESULT Window::HandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam){
    switch (uMsg){
    case WM_CREATE :
        std::cout << "CTing" << std::endl;
        return this->WindowCreated();

    case WM_DESTROY :
        std::cout << "DSTing" << std::endl;
        this->DiscardGraphicResources();
        m_factory->Release();
        PostQuitMessage(0);

        return 0;

    case WM_PAINT :
        std::cout << "Painting" << std::endl;
        this->OnPaint();
        return 0;

    case WM_SIZE :
        std::cout << "Resize" << std::endl;
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
        for (int i = 0; i < m_list_shapes.size(); i++){
            m_list_shapes[i]->drawShape();
        }        

        handler_result = m_render_target->EndDraw();
        if (FAILED(handler_result) || handler_result == D2DERR_RECREATE_TARGET){
            this->DiscardGraphicResources();
        }
        EndPaint(m_handler_window, &paint_struct);
    }
    else {
        std::cout << "CGR error" << std::endl;
    }
}

void Window::DiscardGraphicResources(){ 
    m_render_target->Release();
    m_brush->Release();
}

void Window::CalculateLayout(){

}

HRESULT Window::CreateGraphicResources(){
    
    HRESULT handler_result = S_OK;
    if (m_render_target == NULL){
        
        RECT rect_app;
        GetClientRect(m_handler_window, &rect_app);
        
        D2D1_SIZE_U size = D2D1::SizeU(rect_app.right, rect_app.bottom);
        handler_result = m_factory->CreateHwndRenderTarget(D2D1::RenderTargetProperties(), D2D1::HwndRenderTargetProperties(m_handler_window, size), &m_render_target);
    }
    for (int i = 0; i < m_list_shapes.size(); i++){
        std::cout << "Update brush" << std::endl;
        m_list_shapes[i]->updateBrush();
        std::cout << "Brush updated" << std::endl;
    } 
    return handler_result;
}

ID2D1HwndRenderTarget* Window::getRenderTarget(){
    return m_render_target;
}

int Window::WindowCreated(){
    if (FAILED(D2D1CreateFactory(D2D1_FACTORY_TYPE_SINGLE_THREADED, &m_factory))){
        return -1;
    }
    return 0;
}

void Window::addShapeToDraw(Shape *new_shape){
    m_list_shapes.push_back(new_shape);
}