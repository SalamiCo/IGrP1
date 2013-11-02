#ifndef TreeH
#define TreeH

#include <vector>
#include <iostream>
#include <math.h>
#include "Square.h"
#include "Pencil.h"

class Tree{
	private:
		std::vector<Square> next, archive;
	public:
		Tree();
		Tree(int X,int Y);
		void DrawNextLevel();
		void AddNextLevel();
		void UndoLevel();
};

#endif
 