#include <stdio.h>
#include <setjmp.h>
#include <conio.h>
#include <windows.h>

jmp_buf jumpBuffer;

int n;
int sum = 0;

void FibonacciSum(int index, int a, int b)
{
    if (index > n)
    {
        longjmp(jumpBuffer, 1);
    }

    printf("%d ", a);

    sum = sum + a;

    FibonacciSum(index + 1, b, a + b);
}

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    printf("Введите количество чисел Фибоначчи: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка: количество чисел должно быть больше 0.\n");
        getch();
        return 0;
    }

    if (setjmp(jumpBuffer) == 0)
    {
        printf("Числа Фибоначчи:\n");
        FibonacciSum(1, 1, 1);
    }
    else
    {
        printf("\nСумма чисел Фибоначчи: %d\n", sum);
    }

    getch();
    return 0;
}