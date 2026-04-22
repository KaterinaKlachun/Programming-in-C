#include <stdio.h>
#include <windows.h>
#include "triangle.h"

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double a;
    double b;
    double c;

    printf("Введите стороны треугольника:\n");
    scanf("%lf %lf %lf", &a, &b, &c);

    if (a > 0 && b > 0 && c > 0 &&
        a + b > c && a + c > b && b + c > a) {

        printf("Периметр: %.2lf\n", perimeter(a, b, c));
        printf("Площадь: %.2lf\n", area(a, b, c));

        } else {
            printf("Треугольник не существует\n");
        }

    return 0;
}