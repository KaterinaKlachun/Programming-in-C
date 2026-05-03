#include <stdio.h>
#include <conio.h>

int linearSearch(int a[], int n, int key, int *checks)
{
    *checks = 0;

    for (int i = 0; i < n; i++)
    {
        (*checks)++;

        if (a[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int a[], int n, int key, int *checks)
{
    int left = 0;
    int right = n - 1;
    int middle;

    *checks = 0;

    while (left <= right)
    {
        (*checks)++;

        middle = (left + right) / 2;

        if (a[middle] == key)
        {
            return middle;
        }
        else if (key < a[middle])
        {
            right = middle - 1;
        }
        else
        {
            left = middle + 1;
        }
    }

    return -1;
}

int main()
{
    int n;
    int a[100];
    int key;
    int checks1;
    int checks2;
    int pos1;
    int pos2;

    printf("Введите количество элементов: ");
    scanf("%d", &n);

    if (n <= 0 || n > 100)
    {
        printf("Ошибка размера массива.\n");
        getch();
        return 0;
    }

    printf("Введите отсортированный массив:\n");

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Введите искомое число: ");
    scanf("%d", &key);

    pos1 = linearSearch(a, n, key, &checks1);
    pos2 = binarySearch(a, n, key, &checks2);

    printf("Последовательный поиск: позиция %d, проверок %d\n", pos1, checks1);
    printf("Двоичный поиск: позиция %d, проверок %d\n", pos2, checks2);

    getch();
    return 0;
}