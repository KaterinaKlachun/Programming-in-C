#include <stdarg.h>
#include "functions.h"

double sum_args(int count, ...)
{
    va_list args;
    va_start(args, count);

    double result = 0;

    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }

    va_end(args);
    return result;
}

double max_args(int count, ...)
{
    va_list args;
    va_start(args, count);

    double result = va_arg(args, double);

    for (int i = 1; i < count; i++) {
        double value = va_arg(args, double);

        if (value > result) {
            result = value;
        }
    }

    va_end(args);
    return result;
}

double min_args(int count, ...)
{
    va_list args;
    va_start(args, count);

    double result = va_arg(args, double);

    for (int i = 1; i < count; i++) {
        double value = va_arg(args, double);

        if (value < result) {
            result = value;
        }
    }

    va_end(args);
    return result;
}

double avg_args(int count, ...)
{
    va_list args;
    va_start(args, count);

    double result = 0;

    for (int i = 0; i < count; i++) {
        result += va_arg(args, double);
    }

    va_end(args);
    return result / count;
}