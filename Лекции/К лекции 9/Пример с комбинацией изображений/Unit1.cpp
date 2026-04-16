//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//Программа иллюстрирует работу с растровой графикой в памяти машины -
//формирование растровых изображений, их копирование и объединение
//с использованием различных эффектов

TRect myrect1;
Graphics::TBitmap *b1, *b2, *b3, *b4;    //Объявляем глобальные переменные



//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

myrect1.Left=0;
myrect1.Top=0;
myrect1.Right=200;
myrect1.Bottom=100; //Присваиваем значения переменной myrect

b1=new Graphics::TBitmap;
b2=new Graphics::TBitmap;
b3=new Graphics::TBitmap;
b4=new Graphics::TBitmap;  //Создаём переменные типа TBitmap (растровое изображение)

b1->Height=15;b1->Width=15;
b1->PixelFormat=pf16bit;

b2->Height=100;b2->Width=200;
b2->PixelFormat=pf16bit;
b3->Height=100;b3->Width=200;  //Задаём формат переменных типа TBitmap
b3->PixelFormat=pf16bit;
b4->Height=100;b4->Width=200;
b4->PixelFormat=pf16bit;


b1->Canvas->Brush->Style=bsSolid;
b1->Canvas->Brush->Color=clRed;
b1->Canvas->Pen->Color=clRed;
b1->Canvas->Rectangle(0,0,15,15);
b1->Canvas->Brush->Color=clYellow;
b1->Canvas->Ellipse(0,0,15,15);      //Рисуем изображение на переменной b1 (в памяти машины)


}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{

Form1->Canvas->Draw(20,20,b1);  //Копируем на форму переменную b1

b2->Canvas->Pen->Color=clRed;
b2->Canvas->Brush->Bitmap=b1;    //Определяем свойства кисти
b2->Canvas->Rectangle(0,0,200,100); //Рисуем изображение на переменной b2,
                                    //используя для заливки b1

Form1->Canvas->Draw(50,20,b2);     //Копируем на форму переменную b2

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{

b3->Canvas->Pen->Color=clBlue;
b3->Canvas->Brush->Color=clBlue;
b3->Canvas->Rectangle(0,0,100,100);
b3->Canvas->Pen->Color=clGreen;
b3->Canvas->Brush->Color=clGreen;
b3->Canvas->Rectangle(100,0,200,100);  //Рисуем изображение на переменной b3

Form1->Canvas->Draw(50,150,b3);       //Копируем на форму переменную b3

}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button3Click(TObject *Sender)
{
b4->Canvas->CopyMode=cmSrcCopy;
b4->Canvas->CopyRect(myrect1,b3->Canvas,myrect1);    //Копируем в переменную b4 переменную b3


if (RadioGroup1->ItemIndex==0) {b4->Canvas->CopyMode=cmSrcCopy;};
if (RadioGroup1->ItemIndex==1) {b4->Canvas->CopyMode=cmSrcAnd;};
if (RadioGroup1->ItemIndex==2) {b4->Canvas->CopyMode=cmSrcErase;};
if (RadioGroup1->ItemIndex==3) {b4->Canvas->CopyMode=cmSrcInvert;};     //Определяем тип операции объединения
if (RadioGroup1->ItemIndex==4) {b4->Canvas->CopyMode=cmSrcPaint;};
if (RadioGroup1->ItemIndex==5) {b4->Canvas->CopyMode=cmNotSrcCopy;};
if (RadioGroup1->ItemIndex==6) {b4->Canvas->CopyMode=cmNotSrcErase;};

b4->Canvas->CopyRect(myrect1,b2->Canvas,myrect1);  //Объединяем изображение на переменной b4 c изображением b2 по выбранному правилу
Form1->Canvas->Draw(50,280,b4);                    //и копируем результат на форму

        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
delete b1;
delete b2;
delete b3;
delete b4;         
}
//---------------------------------------------------------------------------
