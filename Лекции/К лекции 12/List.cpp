//---------------------------------------------------------------------------

#pragma hdrstop

//---------------------------------------------------------------------------

#pragma argsused
#include <conio.h>
#include <stdio.h>


// Программа содержит описание функций CreateList(), DeleteList(), AddToList(),
// реализующих создание односвязного линейного списка, его даление из памяти
// и добавление нового элемента в конец списка. Функция main() иллюстрирует
// работу данных функций - элементами односвязного списка являются символы,
// которые добавляются в список и выводятся на консоль.

struct data_next    //Описываем структуру из двух полей - данных и указателя
{char data;
 data_next* next;
};



data_next* GreateList()   //Описываем функцию содания списка (пустого)
{data_next* help;         //

help=NULL;

return help;
}



void DeleteList(data_next* &PointerToList)  //Описываем функцию удаления списка из памяти
{data_next* help;                          //посредством поочерёдного удаления его элементов,
 int n, n1, i, j;                          //начиная с последнего.


n=0;
help=PointerToList;

while (help!=NULL)   //Определяем число элементов в списке n
{
help=help->next;
n=n+1;
};

n1=n;
for(i=0;i<n;i++)      //Теперь каждый раз осуществляем доступ к предпоследнему элементу
{help=PointerToList;   //списка и удаляем последний элемент. n1 - текущее число элементов в
   for(j=0;j<n1-1;j++)  //списке (которые ещё не удалены).
   {
   help=help->next;
   };
delete help;
n1=n1-1;

};

PointerToList=NULL;

return;
}



void AddToList(data_next* &PointerToList, char c)  //Описываем функцию добавления в конец списка,
{data_next* help;                                  //c - добавляемый символ.

if (PointerToList==NULL)  //Если список пустой,
{
PointerToList=new data_next;  //то включаем его первый элемент и изменяем
PointerToList->data=c;        //значение указателя на начало списка PointerToList
PointerToList->next=NULL;
}
else
{
help=PointerToList;       //если же список не пустой, то осуществляем доступ к
while (help->next!=NULL)  //последнему элементу
{                         //
help=help->next;
};
help->next=new data_next;  //а затем выделяем память под ещё один элемент и
help=help->next;           //присваиваем ему значение (в данном случае с)
help->data=c;
help->next=NULL;
};

return ;
}

 



int main(int argc, char* argv[]) //Иллюстрируем работу со списком
{data_next* mylist1;             //
 data_next* help;
 

 mylist1=GreateList();   //Создаём пустой список
 AddToList(mylist1, 'A');  // и последовательно добавляем в него символы
 AddToList(mylist1, 'B');  //
 AddToList(mylist1, 'C');
 AddToList(mylist1, 'D');

 help=mylist1;
  while (help!=NULL)
 {
 printf("%c", help->data);  //Теперь поочерёдно выводим символы из списка
 help=help->next;           //на консоль.
 };

 DeleteList(mylist1);      //Удаляем список из памяти


        getch();
        return 0;
}
//---------------------------------------------------------------------------
 