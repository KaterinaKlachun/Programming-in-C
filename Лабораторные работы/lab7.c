#include <stdio.h>
#include <windows.h>

struct humen {
    char name[50];
    char surname[50];
    int year;
};

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    struct humen A[4];
    struct humen B[4];
    struct humen temp;

    int i, j;

    printf("Введите 4 записи в формате: фамилия имя год\n");

    for (i = 0; i < 4; i++) {
        printf("Человек %d: ", i + 1);
        scanf("%s %s %d", A[i].surname, A[i].name, &A[i].year);
    }

    for (i = 0; i < 4; i++) {
        B[i] = A[i];
    }

    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3 - i; j++) {
            if (B[j].year > B[j + 1].year) {
                temp = B[j];
                B[j] = B[j + 1];
                B[j + 1] = temp;
            }
        }
    }

    printf("\nОтсортированный массив по году рождения:\n");
    for (i = 0; i < 4; i++) {
        printf("%s %s %d\n", B[i].surname, B[i].name, B[i].year);
    }

    return 0;
}