#include <stdio.h>
#include <conio.h>

int main()
{
    int queue[5];
    int n = 5;
    int head = 0;
    int tail = 0;
    int choice;
    int value;

    do
    {
        printf("\n1 - Добавить в очередь\n");
        printf("2 - Удалить из очереди\n");
        printf("3 - Размер очереди\n");
        printf("0 - Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            if (tail == n)
            {
                printf("Очередь заполнена.\n");
            }
            else
            {
                printf("Введите число: ");
                scanf("%d", &value);

                queue[tail] = value;
                tail++;
            }
        }
        else if (choice == 2)
        {
            if (head == tail)
            {
                printf("Очередь пуста.\n");
            }
            else
            {
                printf("Удалено: %d\n", queue[head]);
                head++;
            }
        }
        else if (choice == 3)
        {
            printf("Размер очереди: %d\n", tail - head);
        }

    } while (choice != 0);

    getch();
    return 0;
}