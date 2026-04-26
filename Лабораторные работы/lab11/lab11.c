#include <stdio.h>
#include <windows.h>
#include "functions.h"

int main()
{
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    double s = sum_args(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    double mx = max_args(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    double mn = min_args(5, 1.0, 2.0, 3.0, 4.0, 5.0);
    double a = avg_args(5, 1.0, 2.0, 3.0, 4.0, 5.0);

    printf("Сумма = %.2lf\n", s);
    printf("Максимум = %.2lf\n", mx);
    printf("Минимум = %.2lf\n", mn);
    printf("Среднее = %.2lf\n", a);

    return 0;
}