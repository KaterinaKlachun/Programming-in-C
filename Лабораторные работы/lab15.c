#include <stdio.h>
#include <conio.h>
#include <windows.h>

void PrintNormal(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }

    PrintNormal(n / 10);
    printf("%d ", n % 10);
}

void PrintReverse(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }

    printf("%d ", n % 10);
    PrintReverse(n / 10);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;

    printf("Введите натуральное число N: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка: число должно быть натуральным.\n");
        getch();
        return 0;
    }

    printf("Цифры в обычном порядке:\n");
    PrintNormal(n);

    printf("\nЦифры в обратном порядке:\n");
    PrintReverse(n);

    getch();
    return 0;
}