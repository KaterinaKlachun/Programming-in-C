//---------------------------------------------------------------------------

#pragma hdrstop
#include<conio.h>
#include<stdio.h>
#include<windows.h>

//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{
int num;
unsigned long ReadCount;

HANDLE PipeHandle;

//Присоединяемся к пайпу
PipeHandle = CreateFile("\\\\.\\pipe\\Data_Ch", GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, 0);
if (PipeHandle)
{
printf("Connecting success!\n");
}
else
{
printf("Error!\n");
}


do 
{ //Читаем данные из пайпа
ReadFile(PipeHandle, &num, sizeof(num), &ReadCount, NULL);
printf("Number = %d\n", num);
}
while (ReadCount!=0);

printf("Disconnected...\n");
getch();
        return 0;
}
//---------------------------------------------------------------------------
 