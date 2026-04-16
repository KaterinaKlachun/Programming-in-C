//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>




//---------------------------------------------------------------------------
//Программа иллюстрирует работу с файлами (чтение и запись в текстовом
//и двоичном режимах) традиционными средствами языка С и с помощью функций WinAPI
//


#pragma argsused
int main(int argc, char* argv[])
{FILE *f1;
char s[256];
int sum, i;
HANDLE h1;
unsigned long temp;


//РАБОТА С ФАЙЛАМИ В ТЕКСТОВОМ РЕЖИМЕ------------------

//Открытие файла data.txt и чтение данных (текста) из него
//традиционными средствами языка С

sum=0;

f1=fopen("data.txt", "rt");
while(fgets(s, 256, f1)) //Из файла читаются строки
{
	i=atoi(s);               //пока не будет достигнут
	sum=sum+i;
}               //конец файла                 
fclose(f1);

printf("Data from file \"data.txt\" read.\n");



//Вывод данных (текста) в тектовый файл WritingFile1.txt
//

f1=fopen("WritingFile1.txt", "wt");
fprintf(f1, "File for writing the text by C tools\n");
fprintf(f1, "Sum=%d", sum);
fclose(f1);

printf("Data to file \"WritingFile1.txt\" written.\n");


//-------------------------------------------------------






//РАБОТА С ФАЙЛАМИ В ДВОИЧНОМ РЕЖИМЕ--------------------

//Открытие файла data.b и чтение из него
//двоичных данных

f1=fopen("data.b", "rb");
for(i=0;i<8;i++)
{fread(&s[i], sizeof(char), 1, f1);}//Из файла 8 раз последовательно
                                    //читаются числа типа char (по одному)
fclose(f1);

printf("\nData from file \"data.b\" read (as you can see):\n");
for(i=0;i<8;i++)
{printf("%d  ", s[i]);}             //Вывод на печать прочитанных чисел
 printf("\n");




//Запись двоичных данных в файл WritingFile2.b

for(i=0;i<256;i++)
{s[i]=i;}

f1=fopen("WritingFile2.b", "wb");     //Запись данных в двоичный
for(i=0;i<256;i++)                    //файл: последовательности чисел
{fwrite(&s[i], sizeof(char), 1, f1);} //типа char от 0 до 255
fclose(f1);

printf("\nData to file \"WritingFile2.b\" written\n");
//---------------------------------------------------------------------------






//--------------------------------------------------------------------------
//Пример использования функций WinAPI для записи в файл

h1=CreateFile("Windowfunc.b",
                 GENERIC_WRITE,
                 FILE_SHARE_WRITE,
                 NULL,
                 CREATE_ALWAYS,
                 FILE_ATTRIBUTE_ARCHIVE,
                 NULL);
WriteFile(h1, s, 256, &temp , NULL);
CloseHandle(h1);

printf("\nDatas to file \"Windowfunc.b\" written by WinAPI functions (%d bytes)\n", temp);
//---------------------------------------------------------------------------



printf("OK\n");
getch();
        return 0;
}
//---------------------------------------------------------------------------
