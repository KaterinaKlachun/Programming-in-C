#include <stdio.h>
#include <conio.h>

struct Human
{
    char name[30];
    char surname[30];
    int birthYear;
};

int main()
{
    struct Human people[4];
    struct Human temp;

    for (int i = 0; i < 4; i++)
    {
        printf("Введите имя: ");
        scanf("%s", people[i].name);

        printf("Введите фамилию: ");
        scanf("%s", people[i].surname);

        printf("Введите год рождения: ");
        scanf("%d", &people[i].birthYear);
    }

    for (int i = 0; i < 4 - 1; i++)
    {
        for (int j = 0; j < 4 - i - 1; j++)
        {
            if (people[j].birthYear > people[j + 1].birthYear)
            {
                temp = people[j];
                people[j] = people[j + 1];
                people[j + 1] = temp;
            }
        }
    }

    printf("\nСписок после сортировки:\n");

    for (int i = 0; i < 4; i++)
    {
        printf("%s %s, %d\n", people[i].name, people[i].surname, people[i].birthYear);
    }

    getch();
    return 0;
}