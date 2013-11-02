
#include "Tree.h"

Tree::Tree(){
	Square firstSquare = Square(PointCoord(50,-100), PointCoord(-50,-100), PointCoord(-50,-200), PointCoord(50,-200));
    this->next.push_back(firstSquare);
}

Tree::Tree(int X, int Y){
    Square newSquare = Square(PointCoord(X+50,Y+50), PointCoord(X-50,Y+50), PointCoord(X-50,Y-50), PointCoord(X+50,Y-50));
    this->next.push_back(newSquare);
}

void Tree::DrawNextLevel(){
    std::vector<Square>::iterator i;
    for(i=this->archive.begin(); i!=this->archive.end(); ++i){
        glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0); //Red
            glVertex2f( i->GetP1().GetX(), i->GetP1().GetY());
            glColor3f(0.0,1.0,0.0); //Green
            glVertex2f( i->GetP2().GetX(), i->GetP2().GetY());
            glColor3f(0.0,0.0,1.0); //Blue
            glVertex2f( i->GetP3().GetX(), i->GetP3().GetY());
            glColor3f(1.0,0.0,1.0); //Purple
            glVertex2f( i->GetP4().GetX(), i->GetP4().GetY());
        glEnd();
    }
    for(i=this->next.begin(); i!=this->next.end(); ++i){
        glBegin(GL_QUADS);
            glColor3f(1.0,0.0,0.0); //Red
            glVertex2f( i->GetP1().GetX(), i->GetP1().GetY());
            glColor3f(0.0,1.0,0.0); //Green
            glVertex2f( i->GetP2().GetX(), i->GetP2().GetY());
            glColor3f(0.0,0.0,1.0); //Blue
            glVertex2f( i->GetP3().GetX(), i->GetP3().GetY());
            glColor3f(1.0,0.0,1.0); //Purple
            glVertex2f( i->GetP4().GetX(), i->GetP4().GetY());
        glEnd();
    }
}

void Tree::AddNextLevel(){
    Pencil pen;
    std::vector<Square>::iterator level;
    std::vector<Square>::iterator stop;
    GLdouble distance;

    this->next.reserve(this->next.size()*3);

    // Last Square of the current level
    stop = this->next.end();

    for(level=this->next.begin(); level!=stop; ++level){
        //Calculate the distance for the pencil to move
        distance = level->GetEdge()*cos(M_PI_4);

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

        Square s1 = Square(p2,p3,p4,p1);
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

        Square s2 = Square(p7,p8,p5,p6);
        this->next.push_back(s2);

        // Save the current level in list 'archive'
        this->archive.push_back(*level);
    }

    // Delete the current level from list 'next'
    this->next.erase(this->next.begin(), stop);
}
 