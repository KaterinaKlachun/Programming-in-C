#include <stdio.h>
#include <string.h>
#include <windows.h>

struct human {
    char name[50];
    char surname[50];
    int year;
    char gender[10];
    double height;
};

void swap(struct human *a, struct human *b) {
    struct human temp = *a;
    *a = *b;
    *b = temp;
}

int compare(struct human a, struct human b, int f1, int f2) {
    // поле 1
    if (f1 == 1 && a.year != b.year) return a.year - b.year;
    if (f1 == 2 && strcmp(a.name, b.name) != 0) return strcmp(a.name, b.name);
    if (f1 == 3 && strcmp(a.surname, b.surname) != 0) return strcmp(a.surname, b.surname);
    if (f1 == 4 && strcmp(a.gender, b.gender) != 0) return strcmp(a.gender, b.gender);
    if (f1 == 5 && a.height != b.height) return (a.height > b.height) ? 1 : -1;

    // поле 2 (если первое совпало)
    if (f2 == 1) return a.year - b.year;
    if (f2 == 2) return strcmp(a.name, b.name);
    if (f2 == 3) return strcmp(a.surname, b.surname);
    if (f2 == 4) return strcmp(a.gender, b.gender);
    if (f2 == 5) return (a.height > b.height) ? 1 : -1;

    return 0;
}

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    FILE *f = fopen("input.txt", "r");

    struct human arr[100];
    int n = 0;

    while (fscanf(f, "%s %s %d %s %lf",
                  arr[n].surname,
                  arr[n].name,
                  &arr[n].year,
                  arr[n].gender,
                  &arr[n].height) == 5) {
        n++;
    }

    fclose(f);

    int f1, f2;
    printf("Выберите поле 1 (1-год,2-имя,3-фамилия,4-пол,5-рост): ");
    scanf("%d", &f1);

    printf("Выберите поле 2 (0-нет): ");
    scanf("%d", &f2);

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (compare(arr[j], arr[j + 1], f1, f2) > 0) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }

    printf("\nРезультат:\n");
    for (int i = 0; i < n; i++) {
        printf("%s %s %d %s %.2lf\n",
               arr[i].surname,
               arr[i].name,
               arr[i].year,
               arr[i].gender,
               arr[i].height);
    }

    return 0;
}