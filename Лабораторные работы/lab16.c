#include <stdio.h>
#include <conio.h>
#include <windows.h>

int countBitsLong(long x)
{
    int count = 0;
    unsigned long *p;

    p = (unsigned long*)&x; // приведение типа (работа с памятью)

    for (int i = 0; i < sizeof(long) * 8; i++)
    {
        if ((*p >> i) & 1)
        {
            count++;
        }
    }

    return count;
}

int countBitsDouble(double x)
{
    int count = 0;
    unsigned long long *p;

    p = (unsigned long long*)&x; // доступ к битам double

    for (int i = 0; i < sizeof(double) * 8; i++)
    {
        if ((*p >> i) & 1)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    long a;
    double b;

    printf("Введите значение типа long:\n");
    scanf("%ld", &a);

    printf("Введите значение типа double:\n");
    scanf("%lf", &b);

    int bitsLong = countBitsLong(a);
    int bitsDouble = countBitsDouble(b);

    printf("Количество единичных битов (long): %d\n", bitsLong);
    printf("Количество единичных битов (double): %d\n", bitsDouble);

    getch();
    return 0;
}