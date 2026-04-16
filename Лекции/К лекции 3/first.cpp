//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include "second.h" 

//---------------------------------------------------------------------------

//Программа состоит из двух модулей - first.cpp, second.cpp
//и вычисляет периметр и площадь прямоугольника. Функции
//вычисления периметра и площади rect_perimeter и
//rect_square описаны в модуле second.cpp и становятся
//доступны после подключения модуля к проекту и подключения
//заголовка с прототипами second.h
//
//Переменная-счётчик ii объявлена как глобальная и внешняя по отношению
//к главному модулю программы. Она показывает, сколько раз
//вызывалась функция rect_square


extern int ii; // Это глобальная переменная, описанная в другом модуле (second.cpp, в нашем случае)

#pragma argsused
int main(int argc, char* argv[])
{char s[80];
long double a, b, per, squ;

ii=0;

loop1:

printf("Input a:\n");
gets(s);              //Вводим значения длин сторон прямоугольника a и b.
a=atof(s);

printf("Input b:\n");
gets(s);
b=atof(s);

per=rect_perimeter(a, b);   //Вызываем функции определения периметра и площади
squ=rect_square(a, b);

printf("Perimeter=%Lf \nSquare=%Lf\n", per, squ);    //Выводим на консоль результат
printf("You made %d calculations of square\n", ii);

do
{
printf("Do you want to repeat? (Y/N)\n");  // Предлагаем пользователю повторить программу
gets(s);
}
while (s[0]!='y' && s[0]!='Y' && s[0]!='n' && s[0]!='N');
if (s[0]=='y' || s[0]=='Y') {goto loop1;} // Если пользователь нажал 'Y' или 'y' выполняем программу ещё раз

  printf("OK");
  getch();
        return 0;
}
//---------------------------------------------------------------------------
 