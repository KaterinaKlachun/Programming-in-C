#include <stdio.h>
#include <conio.h>

int main()
{
    FILE *input;
    FILE *output;

    char surname[50];
    char name[50];
    char patronymic[50];
    int year;
    int limit;

    input = fopen("input.txt", "rt");

    if (input == NULL)
    {
        printf("Ошибка открытия файла input.txt\n");
        getch();
        return 0;
    }

    output = fopen("output.txt", "wt");

    if (output == NULL)
    {
        printf("Ошибка создания файла output.txt\n");
        fclose(input);
        getch();
        return 0;
    }

    printf("Введите год: ");
    scanf("%d", &limit);

    while (fscanf(input, "%s %s %s %d", surname, name, patronymic, &year) == 4)
    {
        if (year > limit)
        {
            fprintf(output, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }

    fclose(input);
    fclose(output);

    printf("Данные записаны в output.txt\n");

    getch();
    return 0;
}