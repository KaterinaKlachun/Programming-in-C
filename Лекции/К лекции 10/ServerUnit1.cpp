//---------------------------------------------------------------------------

#pragma hdrstop
#include<conio.h>
#include<stdio.h>
#include<windows.h>

//---------------------------------------------------------------------------
// Программа иллюстрирует работу со специальным инструментом
// межпрограммного обмена данными - пайпами. Данная программа является
// сервером. Она создаёт пайп и ждёт присоединения к нему программы-клиента.
// После успешного соединения просит вводить числа и записывает их в пайп.
// Другая программа - клиент читает числа из пайпа и выдаёт их на консоль
#pragma argsused
int main(int argc, char* argv[])
{
char s[80];
int num;
unsigned long WriteCount;
HANDLE PipeHandle;

//Создаём пайп с именем Data_Ch. ВНИМАНИЕ! Для корректной интерпретации строки
// с именем вместо одного слеша ставим два!
PipeHandle = CreateNamedPipe("\\\\.\\pipe\\Data_Ch",PIPE_ACCESS_OUTBOUND,PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT, 3, 10000, 10000, 5000, NULL);
if (INVALID_HANDLE_VALUE!=PipeHandle)              
{
printf("Wait to connect...\n");
}
else
{
printf("Error!\n");
}

if (ConnectNamedPipe(PipeHandle, NULL))  // Ждём пока к пайпу присоединится клиент
{
printf("Connecting success!\n");
}




while (s[0]!='q')
{
printf("Input number: \n");
gets(s);
num = atoi(s);  //Вводим с консоли число и записываем его в пайп
WriteFile(PipeHandle, &num, sizeof(num), &WriteCount, NULL);
}


getch();

FlushFileBuffers(PipeHandle);
DisconnectNamedPipe(PipeHandle);
CloseHandle(PipeHandle);

        return 0;
}
//---------------------------------------------------------------------------
 