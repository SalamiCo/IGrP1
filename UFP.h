//---------------------------------------------------------------------------

#ifndef UFPH
#define UFPH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>

#include <gl\gl.h>
#include <gl\glu.h>

//---------------------------------------------------------------------------
class TGLForm2D : public TForm
{
__published:	// IDE-managed Components
  void __fastcall FormCreate(TObject *Sender);
  void __fastcall FormResize(TObject *Sender);
  void __fastcall FormPaint(TObject *Sender);
  void __fastcall FormDestroy(TObject *Sender);
        void __fastcall FormKeyPress(TObject *Sender, char &Key);

private:	// User declarations
 HDC hdc;
 HGLRC hrc;
 //definen el tamaño del volumen de vista
 GLfloat xLeft,xRight,yTop,yBot;
 //guarda el radio del puerto de vista
 GLfloat RatioViewPort;
 //Variable para guardar el centro de la escena
 GLfloat centerX, centerY;
 //Displacement increase
 GLfloat displacementeIncrease;
 // métodos privados
 void __fastcall SetPixelFormatDescriptor();
 void __fastcall GLScene();

 public:		// User declarations
   __fastcall TGLForm2D(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TGLForm2D *GLForm2D;
//---------------------------------------------------------------------------
#endif
