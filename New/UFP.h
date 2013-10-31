//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include "Tree.h"

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
  void __fastcall FormKeyPress(TObject *Sender, char &Key);
        void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tama�o del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 //Variable para guardar el centro de la escena
 GLfloat centerX, centerY;
 //Displacement increase
 GLfloat displacementeIncrease;
 //Acumulate zoom
 GLfloat acumulateZoom;
//Scene variable
 Tree tree;

 // m�todos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();
 void Draw();

 public:		// User declarations
   __fastcall TGLForm2D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif

