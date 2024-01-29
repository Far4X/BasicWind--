#ifndef BW_TXT_HANDLER_CPP
#define BW_TXT_HANDLER_CPP

#include <string>
#include <d2d1.h>


class TextHandler {
public :
    TextHandler(float pos[2], std::string text);
    TextHandler();
    ~TextHandler();

    void print(HDC &target_hdc);
    void setText(std::string &text);

    float getX();
    float getY();
    std::string getText();
    int getNumChar();
    HFONT getHFont();

private :
    float m_position[2];
    HDC *m_target_hdc;
    std::string m_text;
    HFONT m_font;
};

#endif