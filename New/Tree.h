#ifndef TreeH
#define TreeH

#include <vector>
#include <iostream>
#include "Square.h"
#include "Pencil.h"

class Tree{
	private:
		std::vector<Square> next, archive;
	public:
		Tree();
		void DrawNextLevel();
		void AddNextLevel();
};

#endif
 