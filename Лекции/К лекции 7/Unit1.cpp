//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include <stdio.h>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
Label1->Caption="";Label2->Caption="";
Label3->Caption="";Label4->Caption="";
Label5->Caption="";
Panel1->Font->Name="Helvetica";
Panel1->Font->Size=12;
Panel1->Caption="Жми мышью сюда!";
Panel1->Cursor=crHandPoint;

Label6->Caption="Программа реагирует на движение по форме указателя мыши, нажатия клавиш мыши по зелёной панели\n и нажатия клавиш клавиатуры \"Пробел\", \"Ввод\" и стрелок";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Panel1MouseDown(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 if (Button==mbLeft) {Label1->Caption="По панели нажали левой кнопкой мыши"; Label2->Caption="";};
 if (Button==mbRight) {Label1->Caption="По панели нажали правой кнопкой мыши"; Label2->Caption="";};
 if (Button==mbMiddle) {Label1->Caption="По панели нажали средней кнопкой мыши"; Label2->Caption="";};

 if (Shift.Contains(ssShift)) {Label2->Caption="Была нажата клавиша Shift";};
 if (Shift.Contains(ssAlt)) {Label2->Caption="Была нажата клавиша Alt";};
 if (Shift.Contains(ssCtrl)) {Label2->Caption="Была нажата клавиша Ctrl";};
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
char s[80];

sprintf(s, "X= %d, Y= %d", X, Y);

Label3->Caption="Координаты указателя мыши:";
Label4->Caption=s;        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
if (Key==0x25) {Label5->Caption="Нажали клавишу \"Стрелка влево\"";};
if (Key==0x26) {Label5->Caption="Нажали клавишу \"Стрелка вверх\"";};
if (Key==0x27) {Label5->Caption="Нажали клавишу \"Стрелка вправо\"";};
if (Key==0x28) {Label5->Caption="Нажали клавишу \"Стрелка вниз\"";};
if (Key==0x28) {Label5->Caption="Нажали клавишу \"Стрелка вниз\"";};
if (Key==0x20) {Label5->Caption="Нажали клавишу \"Space (пробел)\"";};
if (Key==0xD) {Label5->Caption="Нажали клавишу \"Enter (ввод)\"";};        
}
//---------------------------------------------------------------------------
