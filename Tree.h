#ifndef TreeH
#define TreeH

#include <vector.h>
#include "Square.h"

class Tree{
	private:
		vector<Square> next, archive;
	public:
		Tree();
		drawNextLevel();
};

#endif