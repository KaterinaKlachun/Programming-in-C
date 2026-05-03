#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    int a[10][10];
    int degree;

    printf("Введите количество вершин: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Ошибка количества вершин.\n");
        getch();
        return 0;
    }

    printf("Введите матрицу смежности:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Степени вершин:\n");

    for (int i = 0; i < n; i++)
    {
        degree = 0;

        for (int j = 0; j < n; j++)
        {
            if (a[i][j] != 0)
            {
                degree++;
            }
        }

        printf("Вершина %d: %d\n", i + 1, degree);
    }

    getch();
    return 0;
}