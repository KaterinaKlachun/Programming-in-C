//---------------------------------------------------------------------------

#pragma hdrstop
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <windows.h>
#include "secunit.h"

//Программа иллюстрирует работу с динамической памятью с помощью стандартных
//функций С, операторов С++ и системных функций Windows.
//
//---------------------------------------------------------------------------

#pragma argsused
int main(int argc, char* argv[])
{char s[80];
 HANDLE h1;
 int *ii, *jj, *kk;
 int ni, nj, nk, i;

//Традиционное динамическое размешение одномерного массива стандартными 
//средствами С

printf("Input dimension of 1D array ii\n");
gets(s);
ni=atoi(s);

ii=(int*)malloc(ni*sizeof(int));
if (ii)
{
        for(i=0;i<ni;i++)
        {ii[i]=i;}
}

//Динамическое размещение одномерного массива специальными операторами С++

printf("Input dimention of 1D array jj\n");
gets(s);
nj=atoi(s);

jj=new int[nj];
if (jj)
{
        for(i=0;i<nj;i++)
        {jj[i]=i;}
}

//Динамическое размещение одномерного массива с помощью
//функций WinAPI

printf("Input dimention of 1D array kk\n");
gets(s);
nk=atoi(s);

h1=GlobalAlloc(GMEM_FIXED,nk*sizeof(int));
if (h1) {kk=(int*)GlobalLock(h1);}
if (kk)
{
        for(i=0;i<nk;i++)
        {kk[i]=i;}
}

//Вывод массивов ii, jj, kk и сумм их элементов на печать (функция sum() описана
//в другом модуле - secunit.cpp

printf("\n");
for(i=0;i<ni;i++)
{printf("%d  ",ii[i]);}
printf("\n");
printf("%d\n", sum(ii, ni));

for(i=0;i<nj;i++)
{printf("%d  ",jj[i]);}
printf("\n");
printf("%d\n", sum(jj, nj));

for(i=0;i<nk;i++)
{printf("%d  ",kk[i]);}
printf("\n");
printf("%d\n", sum(kk, nk));

//Освобождение памяти

free(ii);
delete[ ] jj;
GlobalFree(h1);


printf("\nOK\n");
getch();
        return 0;
}
//---------------------------------------------------------------------------
 