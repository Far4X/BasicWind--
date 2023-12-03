#ifndef CURSOR_BWPP
#define CURSOR_BWPP

class Cursor {
public :
    Cursor();
    Cursor(int pos[2]);
    ~Cursor();
    int* getPosition();
    int getX();
    int getY();

    void updatePosition(const int pos[2]);

private :
    int m_pos[2];
};

#endif