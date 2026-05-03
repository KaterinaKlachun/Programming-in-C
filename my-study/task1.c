#include <stdio.h>

int countBitsLong(long x)
{
    int count = 0;
    unsigned long *p = (unsigned long*)&x;

    for (int i = 0; i < sizeof(long) * 8; i++)
    {
        if (((*p) >> i) & 1)
        {
            count++;
        }
    }

    return count;
}

int countBitsDouble(double x)
{
    int count = 0;
    unsigned long long *p = (unsigned long long*)&x;

    for (int i = 0; i < sizeof(double) * 8; i++)
    {
        if (((*p) >> i) & 1)
        {
            count++;
        }
    }

    return count;
}

int main()
{
    long a;
    double b;

    printf("Введите long: ");
    scanf("%ld", &a);

    printf("Введите double: ");
    scanf("%lf", &b);

    printf("Единичных битов в long: %d\n", countBitsLong(a));
    printf("Единичных битов в double: %d\n", countBitsDouble(b));

    return 0;
}