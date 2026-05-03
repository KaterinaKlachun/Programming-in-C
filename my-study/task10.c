#include <stdio.h>
#include <conio.h>

int main()
{
    int n;
    int w[10][10];
    int dist[10];
    int used[10];
    int start;
    int min;
    int v;

    printf("Введите количество вершин: ");
    scanf("%d", &n);

    if (n <= 0 || n > 10)
    {
        printf("Ошибка количества вершин.\n");
        getch();
        return 0;
    }

    printf("Введите матрицу весов (0 если ребра нет):\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &w[i][j]);
        }
    }

    printf("Введите начальную вершину: ");
    scanf("%d", &start);

    start--;

    for (int i = 0; i < n; i++)
    {
        dist[i] = 100000;
        used[i] = 0;
    }

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        min = 100000;
        v = -1;

        for (int j = 0; j < n; j++)
        {
            if (used[j] == 0 && dist[j] < min)
            {
                min = dist[j];
                v = j;
            }
        }

        if (v == -1)
        {
            break;
        }

        used[v] = 1;

        for (int j = 0; j < n; j++)
        {
            if (w[v][j] > 0 && dist[v] + w[v][j] < dist[j])
            {
                dist[j] = dist[v] + w[v][j];
            }
        }
    }

    printf("Кратчайшие расстояния:\n");

    for (int i = 0; i < n; i++)
    {
        printf("До вершины %d: %d\n", i + 1, dist[i]);
    }

    getch();
    return 0;
}