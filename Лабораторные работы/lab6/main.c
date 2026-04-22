#include <stdio.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *in, *out;

    char surname[50], name[50], patronymic[50];
    int year;

    in = fopen("input.txt", "r");
    out = fopen("output.txt", "w");

    if (in == NULL || out == NULL) {
        printf("Ошибка открытия файла\n");
        return 1;
    }

    while (fscanf(in, "%s %s %s %d", surname, name, patronymic, &year) == 4) {
        if (year > 1980) {
            fprintf(out, "%s %s %s %d\n", surname, name, patronymic, year);
        }
    }

    fclose(in);
    fclose(out);

    printf("Готово. Результат записан в output.txt\n");

    return 0;
}