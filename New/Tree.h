#ifndef TreeH
#define TreeH

#include <vector>
#include "Square.h"
#include "Pencil.h"

class Tree{
	private:
		std::vector<Square*> next, archive;
	public:
		Tree();
		void DrawNextLevel();
};

#endif
 