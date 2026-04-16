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

OpenDialog1->Filter="Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";   //Задаём фмльтр для ращирений файлов, показываемых в диалоговых окнах
SaveDialog1->Filter="Текстовые файлы (*.txt)|*.txt|Все файлы (*.*)|*.*";   //
SaveDialog1->DefaultExt="txt";
Label1->Caption="";
Memo1->Lines->Clear();
Memo1->Font->Size=12;
Memo1->Font->Color=clNavy;
Label2->Caption="Программа иллюстрирует работу с текстовым редактором\n и диалоговыми окнами загрузки и записи в файл";
Button1->Caption="Удалить строки на букву А";
Button2->Caption="Удалить строки на букву Б";
Button3->Caption="Load From File";
Button4->Caption="Save To File";

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
char i1, i2;

i1=OpenDialog1->Execute();  //Открываем диалоговое окно чтения файла
i2=FileExists(OpenDialog1->FileName); //  Если файл существует

if (i1 && i2)
        {
         Label1->Caption="";
         Memo1->Lines->LoadFromFile(OpenDialog1->FileName);  //Загружаем из него текст
        }
        else
        {
         Label1->Caption="Невозможно открыть файл";
        };        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button4Click(TObject *Sender)
{
char i1;

i1=SaveDialog1->Execute();   //Открываем диалоговое окно записи в файл

if (i1) {
        Label1->Caption="";
        Memo1->Lines->SaveToFile(SaveDialog1->FileName);  //Записываем текст в файл
        };
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button1Click(TObject *Sender)
{
int i;

         for(i=0;i<Memo1->Lines->Count;i++)    //Перебираем все строки редактора
         {
                if (Memo1->Lines->Strings[i]!=""){
                if (Memo1->Lines->Strings[i][1]=='А') //Если первая буква в строке равна А
                {
                Memo1->Lines->Delete(i);         //  удаляем строку
                i--;
                };
                };
          };        
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Button2Click(TObject *Sender)
{
int i;

         for(i=0;i<Memo1->Lines->Count;i++)   //Перебираем все строки редактора
         {
                if (Memo1->Lines->Strings[i]!=""){
                if (Memo1->Lines->Strings[i][1]=='Б')  //Если первая буква в строке равна Б
                {
                Memo1->Lines->Delete(i);      //  удаляем строку
                i--;
                };
                };
          };        
}
//---------------------------------------------------------------------------
