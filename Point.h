#ifndef PointH
#define PointH

class Point{
    private:
        GLdouble x;
        GLdouble y;
    public:
        Point();
        Point(GLdouble x, GLdouble y);
        GLdouble getX();
        GLdouble getY();
        void setX(GLdouble x);
        void setY(GLdouble y);
};

#endif