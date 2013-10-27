#ifndef PencilH
#define PencilH

#include "Point.h"

class Pencil{
	private:
		Point pos;
		GLdouble dir;
	public:
		Pencil();
		Pencil(GLdouble x, GLdouble y, GLdouble dir);
		void setPos(Point p);
		void setDir(GLdouble d);
		GLdouble getDir();
};

#endif