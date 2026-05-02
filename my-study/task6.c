#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct Student
{
    char name[50];
    int grade;
    struct Student *next;
};

struct Student* addStudent(struct Student *head)
{
    struct Student *p;
    struct Student *temp;

    p = (struct Student*)malloc(sizeof(struct Student));

    if (p == NULL)
    {
        printf("Ошибка выделения памяти.\n");
        return head;
    }

    printf("Введите имя студента: ");
    scanf("%s", p->name);

    printf("Введите оценку: ");
    scanf("%d", &p->grade);

    p->next = NULL;

    if (head == NULL)
    {
        head = p;
    }
    else
    {
        temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = p;
    }

    return head;
}

void printList(struct Student *head)
{
    struct Student *temp = head;

    if (temp == NULL)
    {
        printf("Список пуст.\n");
        return;
    }

    while (temp != NULL)
    {
        printf("Студент: %s, оценка: %d\n", temp->name, temp->grade);
        temp = temp->next;
    }
}

struct Student* deleteList(struct Student *head)
{
    struct Student *temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }

    return NULL;
}

int main()
{
    struct Student *head = NULL;
    int choice;

    do
    {
        printf("\n1 - Добавить студента\n");
        printf("2 - Вывести список\n");
        printf("0 - Выход\n");
        printf("Выбор: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            head = addStudent(head);
        }
        else if (choice == 2)
        {
            printList(head);
        }

    } while (choice != 0);

    head = deleteList(head);

    getch();
    return 0;
}