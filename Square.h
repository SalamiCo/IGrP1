#ifndef SquareH
#define SquareH

#include <gl\gl.h>
#include <gl\glu.h>

class Square{
	private:
		GLdouble x1,x2,x3,x4;
	public:
		Square();
		Square(GLdouble x1, GLdouble x2, GLdouble x3, GLdouble x4);
};

#endif