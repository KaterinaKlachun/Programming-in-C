//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//---------------------------------------------------------------------------

//Программа иллюстрирует объявление и работу с различными типами данных,
//определяемых пользователем - использование оператора переименования типов,
//перечислимые типы, структуры.
//

#pragma argsused
int main(int argc, char* argv[])
{typedef char symbol;          //Переименование типа char в тип symbol
 typedef char string[80];      //Переименование массива char[80] в тип string
    symbol c;
    string s;

 enum color {red, yellow, green}; //Объявление перечислимого типа color,
    color col;                    //переменные этого типа могут принимать значения
                                  //red, yellow или green
  
 struct student
        {char firstname[20];      //Объявление типа-структуры student, элементами
         char sirname[20];        //которого являются имя, фамилия, номер группы
         char groupnumber[10];    //и номер телефона
         int phone;
         };
    student st1, *st2;            //Обьявляем переменные: st1 типа student и st2 типа указатель на тип student

 //---------------------------------------------------
 //Пример использования перечислимого типа

 col=red;
 col=yellow;

 //Пример обращения к элементам переменной-структуры,
 //если имеется сама переменная (в нашем случае st1)

    printf("Input firstname of student 1\n");    //Вводим данные о первом студенте
    gets(st1.firstname);

    printf("Input sirname of student 1\n");
    gets(st1.sirname);

    printf("Input groupnumber of student 1\n");
    gets(st1.groupnumber);

    printf("Input phone of student 1\n");
    gets(s);
    st1.phone=atoi(s);


    printf("\nInformation about student 1:\n");   //Выводим данные о первом студенте на консоль
    printf(" Name: %s \n", st1.firstname);
    printf(" Sirname: %s \n", st1.sirname);
    printf(" Group: %s \n", st1.groupnumber);
    printf(" Phone: %d \n\n", st1.phone);





 //Пример обращения к элементам переменной-структыры,
 //если имеется указатель на неё (в нашем случае st2)
 //
 
    st2=(student*)malloc(sizeof(student));  //выделяем память для размещения переменной типа student

    printf("\nInput firstname of student 2\n");   //Вводим данные о втором студенте
    gets(st2->firstname);

    printf("Input sirname of student 2\n");
    gets(st2->sirname);

    printf("Input groupnumber of student 2\n");
    gets(st2->groupnumber);

    printf("Input phone of student 2\n");
    gets(s);
    st2->phone=atoi(s);


    printf("\nInformation about student 2:\n");    //Выводим данные о втором студенте на консоль
    printf(" Name: %s \n", st2->firstname);
    printf(" Sirname: %s \n", st2->sirname);
    printf(" Group: %s \n", st2->groupnumber);
    printf(" Phone: %d \n", st2->phone);




 //--------------------------------------------------

 getch();
 free(st2);
        return 0;
}
//---------------------------------------------------------------------------
 