#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n;
    int *arr;
    int sum = 0;
    double average;

    printf("Введите размер массива: ");
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("Ошибка размера.\n");
        getch();
        return 0;
    }

    arr = (int*)malloc(n * sizeof(int));

    if (arr == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        getch();
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
        sum = sum + arr[i];
    }

    average = (double)sum / n;

    printf("Сумма: %d\n", sum);
    printf("Среднее значение: %.2lf\n", average);

    free(arr);

    getch();
    return 0;
}