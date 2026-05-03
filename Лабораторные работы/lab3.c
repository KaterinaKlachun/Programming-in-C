#include <stdio.h>

int main() {

    char str[81];
    int i;

    printf("Введите строку (до 80 символов): ");
    fgets(str, 81, stdin);

    for (i = 0; str[i] != '\0'; i++) {
        if (str[i] == 'a') {
            str[i] = 'A';
        }
        else if (str[i] == 'b') {
            str[i] = 'B';
        }
    }

    printf("Полученная строка: %s\n", str);

    return 0;
}