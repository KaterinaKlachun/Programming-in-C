//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <math.h>



// ѕрограмма иллюстрирует работу с классами и объектами
//
//
//---------------------------------------------------------------------------

#pragma argsused


class my_vector {                               // ќбъ€вл€ем класс - вектор длины 3
        public:                                 // с элементами-данными x, y и z - координатами вектора
        long double x;                          //
        long double y;                          //
        long double z;

        long double euc_norm();                 //ќбъ€вл€ем функции - элементы класса, вычисл€ющие
        long double one_norm();                 //различные виды нормы вектора - евклидову, первую и
        long double inf_norm();                 //бесконечную

        long double operator*(my_vector v2);     //ѕереопредел€ем оператор умножени€ *
        };


long double my_vector::euc_norm()
{
long double help;
        help=sqrt(x*x+y*y+z*z);
        return help;
}

long double my_vector::one_norm()
{
long double help;
        help=(abs(x)+abs(y)+abs(z));
        return help;
}

long double my_vector::inf_norm()
{
long double help;
        if (abs(x)>=abs(y)) {help=abs(x);}
        else {help=abs(y);};
        if (help>=abs(z)) {help=help;}
        else {help=abs(z);};
        return help;
}

long double my_vector::operator*(my_vector v2)
{long double help;
        help=this->x*v2.x+this->y*v2.y+this->z*v2.z;      //переопредел€ем оператор умножени€ * как
        return help;                                      //скал€рное произведение векторов
};
 




int main(int argc, char* argv[])
{
  my_vector v1, v2;    //ќбъ€вл€ем два объекта - представителей класса вектор.
  long double norm1, norm2, scalar;

  

  v1.x=2;
  v1.y=2;
  v1.z=2;
                        //ѕрисваиваем значение координатам векторов.
  v2.x=1;
  v2.y=1;
  v2.z=1;

  norm1=v1.euc_norm(); //¬ычисл€ем евклидову норму и скал€рное произведение векторов.
  norm2=v2.euc_norm();
  scalar=v1*v2;


  printf("Norm of vector v1 = %Lf, norm of vector v2 = %Lf\n", norm1, norm2);
  printf("Scalar multiplication v1*v2 = %Lf\n", scalar);



  
        printf("OK\n");
        getch();
        return 0;
}
//---------------------------------------------------------------------------
 