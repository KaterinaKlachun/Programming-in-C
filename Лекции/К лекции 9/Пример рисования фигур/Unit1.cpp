//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
//-----Заполняем область рисования белым цветом

 Image1->Canvas->Brush->Style=bsSolid;
 Image1->Canvas->Brush->Color=clWhite;
 Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Color=clWhite;
 Image1->Canvas->Rectangle(1,1,Image1->Width,Image1->Height);
 Button1->Caption = "Линия";
 Button2->Caption = "Прямоугольник";
 Button3->Caption = "Эллипс";
 Button4->Caption = "Ломаная";
 Button5->Caption = "Другой эллипс";
 }

//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
//-----Рисуем линию

 Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Mode=pmCopy;
 Image1->Canvas->Pen->Color=clRed;
 Image1->Canvas->MoveTo(20,20);
 Image1->Canvas->LineTo(200,20);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
//-----Рисуем прямоугольник

 Image1->Canvas->Brush->Style=bsClear;
 Image1->Canvas->Pen->Style=psSolid;
 Image1->Canvas->Pen->Mode=pmCopy;
 Image1->Canvas->Pen->Color=clAqua;
 Image1->Canvas->Rectangle(20,40,200,100);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
//-----Рисуем эллипс

 Image1->Canvas->Brush->Style=bsCross;
 Image1->Canvas->Brush->Color=clLime;
 Image1->Canvas->Pen->Style=psDot;
 Image1->Canvas->Pen->Mode=pmCopy;
 Image1->Canvas->Pen->Color=clNavy;
 Image1->Canvas->Ellipse(20,120,200,180);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
TPoint pp[5];
 
  //-----Рисуем ломаную

 pp[0].x=20;pp[0].y=200;
 pp[1].x=50;pp[1].y=220;
 pp[2].x=70;pp[2].y=200;
 pp[3].x=120;pp[3].y=220;
 pp[4].x=200;pp[4].y=200;

 Image1->Canvas->Brush->Style=bsSolid;
 Image1->Canvas->Brush->Color=clRed;
 Image1->Canvas->Pen->Style=psDash;
 Image1->Canvas->Pen->Mode=pmCopy;
 Image1->Canvas->Pen->Color=clBlue;
 Image1->Canvas->Polyline(pp,4);        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button5Click(TObject *Sender)
{
//-----Рисуем прямоугольник со скруглёнными углами

 Image1->Canvas->Brush->Style=bsHorizontal;
 Image1->Canvas->Brush->Color=RGB(200,100,200);
 Image1->Canvas->Pen->Style=psDashDotDot;
 Image1->Canvas->Pen->Mode=pmCopy;
 Image1->Canvas->Pen->Color=clBlue;
 Image1->Canvas->RoundRect(20,240,200,300,50,25);        
}
//---------------------------------------------------------------------------
