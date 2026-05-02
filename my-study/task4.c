#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main()
{
    int n = 5;
    int *pmem;
    int *pstack;
    int choice;
    int value;

    pmem = (int*)malloc(n * sizeof(int));

    if (pmem == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        getch();
        return 0;
    }

    pstack = pmem;

    do
    {
        printf("\n1 - Добавить в стек\n");
        printf("2 - Удалить из стека\n");
        printf("3 - Размер стека\n");
        printf("0 - Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (pstack - pmem == n)
            {
                printf("Стек заполнен.\n");
            }
            else
            {
                printf("Введите число: ");
                scanf("%d", &value);

                *pstack = value;
                pstack = pstack + 1;
            }
        }
        else if (choice == 2)
        {
            if (pstack == pmem)
            {
                printf("Стек пуст.\n");
            }
            else
            {
                pstack = pstack - 1;
                printf("Удалено: %d\n", *pstack);
            }
        }
        else if (choice == 3)
        {
            printf("Размер стека: %d\n", pstack - pmem);
        }

    } while (choice != 0);

    free(pmem);

    getch();
    return 0;
}