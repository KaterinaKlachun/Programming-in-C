//---------------------------------------------------------------------------

#include <vcl.h>
#include <stdio.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TDateTime Starttime;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{

Panel1->Caption="КЛИКНИ СЮДА!";
ScrollBar1->Max=1000;
ScrollBar1->Min=55;
ScrollBar1->Position=330;
ScrollBar1->SmallChange=55;
ScrollBar1->LargeChange=110;
Panel1->Left=15;
Panel1->Top=15;
Label1->Caption="";
Label2->Caption="";
Timer1->Enabled=false;
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//Программа двигает панель по экрану с задаваемой
//с помощью ScrollBar скоростью
//
void __fastcall TForm1::Panel1Click(TObject *Sender)
{
Panel1->Caption="ПОЕХАЛИ!";
Timer1->Interval=ScrollBar1->Position;
Timer1->Enabled=true; //Включаем таймер
Starttime=Time();  //Запоминаем время старта        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
char s[80];
char change;

change=5;

Timer1->Interval=ScrollBar1->Position; //--Задаём интервал таймера

//---Задаём закон движения панели
if ((Panel1->Left<Form1->Width-Panel1->Width-15)&&(Panel1->Top==15))
{
Panel1->Left=Panel1->Left+change;
};
if ((Panel1->Left>Form1->Width-Panel1->Width-15)&&(Panel1->Top<Form1->Height/2))
{
Panel1->Top=Panel1->Top+change;
};
if ((Panel1->Left>15)&&(Panel1->Top>=Form1->Height/2))
{
Panel1->Left=Panel1->Left-change;
};
if ((Panel1->Left==15)&&(Panel1->Top>15))
{
Panel1->Top=Panel1->Top-change;
};
                 
//--Выводим на экран служебную информацию

sprintf(s, "Интервал таймера = %f сек\nСкорость панели = %f пикс/сек", ScrollBar1->Position/1000.0, change/(ScrollBar1->Position/1000.0));
Label1->Caption=s;

Label2->Caption="Прошло времени после старта  "+TimeToStr(Time()-Starttime);
}
//---------------------------------------------------------------------------
