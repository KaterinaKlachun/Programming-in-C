//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Unit1.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall TMyThreadClass::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------


__fastcall TMyThreadClass::TMyThreadClass(bool CreateSuspended)
        : TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall TMyThreadClass::Execute()
{

  while (1)
  {
    this -> index = random(1000);
    Synchronize(UpdateCaption);  // бесконечный цикл, вычисл€ющий значение
                                 //переменной index и вызывающий функцию,
                                 // обновл€ющую надпись на метке с помощью
                                 // метода Synchronize
    Sleep(10);             // ‘ункци€, задерживающа€ поток на 10 мсек
  }
}

void __fastcall TMyThreadClass::UpdateCaption()
{
     lstr->Caption = IntToStr(this->index); // выводим число index в метку
}

//---------------------------------------------------------------------------
 