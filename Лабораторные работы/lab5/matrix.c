#include <stdlib.h>
#include "matrix.h"

double** calculate(double** A, double** B, int n, char op) {
    int i, j, k;

    double** result = (double**)malloc(n * sizeof(double*));
    for (i = 0; i < n; i++) {
        result[i] = (double*)malloc(n * sizeof(double));
    }

    if (op == '+') {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                result[i][j] = A[i][j] + B[i][j];
    }

    else if (op == '-') {
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                result[i][j] = A[i][j] - B[i][j];
    }

    else if (op == '*') {
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                result[i][j] = 0;
                for (k = 0; k < n; k++) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }
    }

    return result;
}