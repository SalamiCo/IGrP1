#ifndef PointH
#define PointH

#include <windows.h>
#include <gl\gl.h>
#include <gl\glu.h>

class Point{
    private:
        GLdouble x;
        GLdouble y;
    public:
        Point();
        Point(GLdouble x, GLdouble y);
        GLdouble GetX();
        GLdouble GetY();
        void SetX(GLdouble x);
        void SetY(GLdouble y);
};

#endif
 