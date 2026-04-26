#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

#define MAX_ARRAY(arr, count) ({                 \
double maxValue = (arr)[0];                  \
for (int k = 1; k < (count); k++) {          \
if ((arr)[k] > maxValue) {               \
maxValue = (arr)[k];                 \
}                                        \
}                                            \
maxValue;                                    \
})

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char str[200];
    double numbers[100];
    int count = 0;

    printf("Введите числа через пробел:\n");
    fgets(str, 200, stdin);

    char *token = strtok(str, " ");

    while (token != NULL) {
        numbers[count] = atof(token);
        count++;
        token = strtok(NULL, " ");
    }

    if (count == 0) {
        printf("Числа не введены\n");
        return 1;
    }

    double max = MAX_ARRAY(numbers, count);

    printf("Максимальное число: %.2lf\n", max);

    return 0;
}