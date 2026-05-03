#include <stdio.h>

void printNormal(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }

    printNormal(n / 10);
    printf("%d ", n % 10);
}

void printReverse(int n)
{
    if (n < 10)
    {
        printf("%d ", n);
        return;
    }

    printf("%d ", n % 10);
    printReverse(n / 10);
}

int main()
{
    int n;

    printf("Введите натуральное число: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка: число должно быть натуральным.\n");
        return 0;
    }

    printf("Обычный порядок:\n");
    printNormal(n);

    printf("\nОбратный порядок:\n");
    printReverse(n);

    return 0;
}