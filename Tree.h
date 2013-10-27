#ifndef TreeH
#define TreeH

#include <vector>
#include "Square.h"

class Tree{
	private:
		vector<Square> next, archive;
	public:
		Tree();
		drawNextLevel();
};

#endif