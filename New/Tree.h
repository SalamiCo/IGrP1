#ifndef TreeH
#define TreeH

#include <list>
#include <iostream>
#include "Square.h"
#include "Pencil.h"

class Tree{
	private:
		std::list<Square> next, archive;
	public:
		Tree();
		void DrawNextLevel();
		void AddNextLevel();
};

#endif
 