#ifndef TreeH
#define TreeH

#include <vector>
#include "Square.h"

class Tree{
	private:
		std::vector<Square> next, archive;
	public:
		Tree();
		drawNextLevel();
};

#endif