#include <stdio.h>
#include <stdlib.h>
#include "matrix.h"

int main() {

    int n, i, j;
    char op;

    printf("Введите размер матриц n: ");
    scanf("%d", &n);

    double** A = (double**)malloc(n * sizeof(double*));
    double** B = (double**)malloc(n * sizeof(double*));

    for (i = 0; i < n; i++) {
        A[i] = (double*)malloc(n * sizeof(double));
        B[i] = (double*)malloc(n * sizeof(double));
    }

    printf("Введите матрицу A (%dx%d):\n", n, n);
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &A[i][j]);

    printf("Введите матрицу B:\n");
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            scanf("%lf", &B[i][j]);

    printf("Введите операцию (+, -, *): ");
    scanf(" %c", &op);

    double** result = calculate(A, B, n, op);

    printf("Результат:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            printf("%.lf ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}