#include <stdio.h>
#include <math.h>
#include <windows.h>

int main() {
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);

    int n;
    printf("Введите размер матрицы n: ");
    scanf("%d", &n);

    double A[n][n];
    double sumMain = 0;
    double sumSide = 0;

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%lf", &A[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        sumMain += A[i][i];
        sumSide += A[i][n - 1 - i];
    }

    printf("Сумма главной диагонали = %.2lf\n", sumMain);
    printf("Сумма побочной диагонали = %.2lf\n", sumSide);

    int m;
    printf("\nВведите размер матрицы m: ");
    scanf("%d", &m);

    int B[m][m];
    int C[m][m];

    printf("Введите элементы матрицы:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &B[i][j]);
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            C[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < m; k++) {
                C[i][j] += B[i][k] * B[k][j];
            }
        }
    }

    printf("Квадрат матрицы:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
