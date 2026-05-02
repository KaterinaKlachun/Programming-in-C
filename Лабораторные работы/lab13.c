#include <stdio.h>
#include <signal.h>
#include <conio.h>
#include <windows.h>

void SignalHandler(int sig)
{
    printf("\nПолучен сигнал: ");

    switch (sig)
    {
        case SIGABRT:
            printf("SIGABRT - аварийное завершение программы\n");
            break;

        case SIGFPE:
            printf("SIGFPE - ошибка арифметической операции\n");
            break;

        case SIGILL:
            printf("SIGILL - недопустимая инструкция\n");
            break;

        case SIGINT:
            printf("SIGINT - прерывание с клавиатуры\n");
            break;

        case SIGSEGV:
            printf("SIGSEGV - ошибка доступа к памяти\n");
            break;

        case SIGTERM:
            printf("SIGTERM - запрос на завершение программы\n");
            break;

        default:
            printf("Неизвестный сигнал\n");
            break;
    }

    printf("Сигнал обработан программой.\n");
}

void ShowMenu()
{
    printf("\nВыберите сигнал для возбуждения:\n");
    printf("1 - SIGABRT\n");
    printf("2 - SIGFPE\n");
    printf("3 - SIGILL\n");
    printf("4 - SIGINT\n");
    printf("5 - SIGSEGV\n");
    printf("6 - SIGTERM\n");
    printf("0 - Выход\n");
    printf("Ваш выбор: ");
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int choice;

    signal(SIGABRT, SignalHandler);
    signal(SIGFPE, SignalHandler);
    signal(SIGILL, SignalHandler);
    signal(SIGINT, SignalHandler);
    signal(SIGSEGV, SignalHandler);
    signal(SIGTERM, SignalHandler);

    printf("Программа обработки сигналов запущена.\n");

    do
    {
        ShowMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                raise(SIGABRT);
                break;

            case 2:
                raise(SIGFPE);
                break;

            case 3:
                raise(SIGILL);
                break;

            case 4:
                raise(SIGINT);
                break;

            case 5:
                raise(SIGSEGV);
                break;

            case 6:
                raise(SIGTERM);
                break;

            case 0:
                printf("Завершение программы.\n");
                break;

            default:
                printf("Ошибка: неверный пункт меню.\n");
                break;
        }

    } while (choice != 0);

    getch();
    return 0;
}