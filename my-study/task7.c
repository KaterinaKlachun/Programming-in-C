#include <stdio.h>
#include <conio.h>

int sorted(int a[], int n)
{
    int comparisons = 0;
    int i;
    int j;
    int w;

    for (j = 1; j < n; j++)
    {
        w = a[j];
        i = j - 1;

        while (i >= 0)
        {
            comparisons++;

            if (a[i] > w)
            {
                a[i + 1] = a[i];
                i--;
            }
            else
            {
                break;
            }
        }

        a[i + 1] = w;
    }

    return comparisons;
}

int main()
{
    int n;
    int a[100];
    int count;

    printf("Введите количество элементов: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Ошибка размера массива.\n");
        getch();
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        printf("a[%d] = ", i);
        scanf("%d", &a[i]);
    }

    count = sorted(a, n);

    printf("Отсортированный массив:\n");

    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    printf("\nКоличество сравнений: %d\n", count);

    getch();
    return 0;
}