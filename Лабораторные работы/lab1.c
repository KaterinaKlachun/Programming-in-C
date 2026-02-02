#include <stdio.h>   // printf, scanf
#include <math.h>    // pow, sqrt
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    // 1. Объявляем переменные
    double a, b, c;
    double D;
    double x1, x2;

    // 2. Ввод коэффициентов с клавиатуры
    printf("Введите коэффициент a: ");
    scanf("%lf", &a);

    printf("Введите коэффициент b: ");
    scanf("%lf", &b);

    printf("Введите коэффициент c: ");
    scanf("%lf", &c);

    // 3. Вычисляем дискриминант
    D = pow(b, 2) - 4 * a * c;

    // 4. Проверяем значение дискриминанта
    if (D > 0) {
        // Два корня
        x1 = (-b + sqrt(D)) / (2 * a);
        x2 = (-b - sqrt(D)) / (2 * a);

        printf("D > 0\n");
        printf("x1 = %.2lf\n", x1);
        printf("x2 = %.2lf\n", x2);
    }
    else if (D == 0) {
        // Один корень
        x1 = -b / (2 * a);

        printf("D = 0\n");
        printf("x = %.2lf\n", x1);
    }
    else {
        // Корней нет
        printf("D < 0\n");
        printf("Корней нет\n");
    }

    // 5. Завершение программы
    return 0;
}

// Коэффициенты (примеры):
// a = 1
// b = -4
// c = 4

// a = 1
// b = 2
// c = 5

// a = 1
// b = -5
// c = 6