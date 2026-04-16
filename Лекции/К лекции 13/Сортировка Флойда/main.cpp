/*
Пример программы, производящей сортировку методом Флойда       
Автор кода Б.Н. Иванов
*/
#include <stdio.h>
#define N 21
void sort3(int *a, int n);
void surface(int *a, int i, int k);

void main(void)
{
	int i, a[N] = {7, 2, 1, 4, 3, 5, 8, 2, 5, 3, 5, 8, 7, 1, 3, 9, 3, 7, 1, 6, 5};
	printf("\n");
	for( i = 0; i < N; i++ ) printf("%d ", a[i]);
	sort3(a, N);
	printf("\n");
	for( i = 0; i < N; i++ ) printf("%d ", a[i]);
}

void sort3(int *a, int n)
{//Производит сортировку массива a длинной n. Изначально строится почти упорядоченое дерево
// далее производится собственно сортировка
	int i, k, w;
	for( i = (n - 1) / 2; i > 0; i-- ) surface(a, i, n - 1);
	for( k = n - 1; k > 0; k--)
	{
		surface(a, 0, k);
		w = a[k];
		a[k] = a[0];
		a[0] = w;
	}
}

void surface(int *a, int i, int k)
{// функция посторения почти упорядоченного дерева
	int j, m, copy;
	copy = a[i];
	m = 2 * i + 1;
	while( m <= k )
	{
		if( m == k ) j = m;
		else j = ( a[m] < a[m + 1] ) ? m:m+1;
		if( a[j] < copy )
		{
			a[i] = a[j];
			i = j;
			m = 2 * i + 1;
		}
		else break;
	}
	a[i] = copy;
}