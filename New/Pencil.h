#ifndef PencilH
#define PencilH

#include "Point.h"
#include <math.h>

class Pencil{
	private:
		Point *pos;
		GLdouble dir;
	public:
		Pencil();
		Pencil(Point *p, GLdouble dir);
		void SetPos(Point *p);
		void SetDir(GLdouble d);
		GLdouble GetDir();
                void Turn(GLdouble d);
                void Forward(GLdouble dist);
};

#endif
 