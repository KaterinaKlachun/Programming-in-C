#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>


int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    char s[100];
    int i = 0;
    double result = 0;
    double num = 0;
    char sign = '+';

    printf("Введите выражение:\n");
    gets(s);

    while (s[i] != '\0') {

        // считываем число (включая знак)
        char temp[20];
        int j = 0;

        // если есть знак перед числом
        if (s[i] == '+' || s[i] == '-') {
            sign = s[i];
            i++;
        }

        // собираем число
        while ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
            temp[j++] = s[i++];
        }
        temp[j] = '\0';

        num = atof(temp);

        // применяем операцию
        if (sign == '+') result += num;
        else result -= num;
    }

    printf("Результат: %.2lf\n", result);

    return 0;
}