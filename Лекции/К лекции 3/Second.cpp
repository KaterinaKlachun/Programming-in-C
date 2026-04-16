//---------------------------------------------------------------------------

#pragma hdrstop

#include "second.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int ii;

long double rect_perimeter(long double a, long double b)
{long double p;

p=(a+b)*2;   // Вычисление периметра прямоугольника

return p;
}



long double rect_square(long double a, long double b)
{long double s;

s=a*b;   // Вычисление площади прямоугольника

ii=ii+1;
return s;

}
