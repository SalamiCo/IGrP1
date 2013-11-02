
#include "Tree.h"

Tree::Tree(){
	Square firstSquare = Square(PointCoord(50,-100), PointCoord(-50,-100), PointCoord(-50,-200), PointCoord(50,-200), 0);
    this->next.push_back(firstSquare);
}

Tree::Tree(int X, int Y){
    Square newSquare = Square(PointCoord(X+50,Y+50), PointCoord(X-50,Y+50), PointCoord(X-50,Y-50), PointCoord(X+50,Y-50), 0);
    this->next.push_back(newSquare);
}

void Tree::DrawNextLevel(){
    std::vector<Square>::iterator i;

    for(i=this->archive.begin(); i!=this->archive.end(); ++i){
        i->DrawSquare(i->GetP1(), i->GetP2(), i->GetP3(), i->GetP4());
    }

    for(i=this->next.begin(); i!=this->next.end(); ++i){
        i->DrawSquare(i->GetP1(), i->GetP2(), i->GetP3(), i->GetP4());      
    }
}

void Tree::AddNextLevel(){
    Pencil pen;
    std::vector<Square>::iterator level;
    std::vector<Square>::iterator stop;
    GLdouble distance;
    int currLevel;

    this->next.reserve(this->next.size()*3);

    // Last Square of the current level
    stop = this->next.end();

    for(level=this->next.begin(); level!=stop; ++level){
        //Calculate the distance for the pencil to move
        distance = level->GetEdge()*cos(M_PI_4);

        //Get next level of the tree
        currLevel = level->GetCurrLevel() + 1;

        //First square
        PointCoord p1 (level->GetP1().GetX(), level->GetP1().GetY());
        pen.SetPos(p1);
        pen.SetDir(level->GetAngle() + M_PI_4);
        pen.Forward(distance);

        PointCoord p2 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        PointCoord p3 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        PointCoord p4 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        Square s1 = Square(p2,p3,p4,p1,currLevel);
        this->next.push_back(s1);

        //Second Square
        pen.Turn(M_PI_4+M_PI);
        pen.Forward(level->GetEdge());

        PointCoord p5 = pen.GetPos();
        pen.Turn(-M_PI_2 - M_PI_4);
        pen.Forward(distance);

        PointCoord p6 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        PointCoord p7 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        PointCoord p8 = pen.GetPos();
        pen.Turn(M_PI_2);
        pen.Forward(distance);

        Square s2 = Square(p7,p8,p5,p6,currLevel);
        this->next.push_back(s2);

        // Save the current level in list 'archive'
        this->archive.push_back(*level);
    }

    // Delete the current level from list 'next'
    this->next.erase(this->next.begin(), stop);
}

void Tree::UndoLevel(){
    // Iterate backwards
    std::vector<Square>::reverse_iterator level;
    int currLevel, squareLevel;

    // Delete the last level from list 'next'
    this->next.erase(this->next.begin(), this->next.end());

    // Add to list 'next' last level from list 'archive'
    level = this->archive.rbegin();
    currLevel = level->GetCurrLevel();
    squareLevel = pow(2,currLevel);
    
    for(int i=1; i<=squareLevel; ++level, ++i){
        this->next.push_back(*level);
        this->archive.pop_back();
    }
}
 