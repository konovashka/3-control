/*2. Дано натуральное число m, последовательность целых чисел а1, а2, .. ‚ам и
целочисленная квадратная матрица порядка m . Строку i номером \ назовем
отмеченной, если аi>0, и неотмеченной, В противном случае. Построить вектор
из первых положительных элементов отмеченных строк. Если отмеченная строка
не содержит положительных элементов, то положить в вектор 0.
Если матрица не содержит отмеченных строк, то выдать сообщение.
В программе описать:
- функцию, которая выделяет память под матрицу»
- функцию, которая заполняет матрицу с ввода,
- функцию, которая находит первый положитель
- функцию, которая строит по матрице вектор.*/

#include <iostream>
using namespace std;
void fill(int** a, int n, int m);
void fill1(int* arr, int m);
int** memory(int n, int m);
int find_firs_positiv(int** arr, int number_str, int m);
int counter_size(int* vektor, int m);
void build(int** a, int* vektor, int* ans, int m);

int main()
{
	int m;
	printf("vvedite M\n");
	scanf_s("%d", &m);
	int** arr = memory(m, m);
	fill(arr, m, m);
	int* vektor = new int[m];
	fill1(vektor, m);
	int* ans = new int[counter_size(vektor, m)];
	build(arr, vektor, ans, m);
	if (counter_size(vektor, m)>0)
	{
	for (int i = 0; i < counter_size(vektor,m); i++)
		{
			printf("%d ", ans[i]);
		}
	}
	else
	{
		printf("v vektore net chisel bol'she 0");
	}
	return 0;
}
//выделение памяти
int** memory(int n, int m)
{
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
	{
		a[i] = new int[m];
	}
	return a;
}
//заполнение элементов
void fill(int** a, int n, int m)
{
	printf("zapolnite massiv\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf_s("%d", &a[i][j]);
		}
	}
}
//заполнение вектора
void fill1(int* arr, int m)
{
	printf("zapolnite vektor\n");
	for (int i = 0; i < m; i++)
	{
		scanf_s("%d", &arr[i]);
	}
}
//поиск первого положительного элемента
int find_firs_positiv(int** arr,int number_str, int m)
{
	for (int i = 0; i < m; i++)
	{
		if (arr[number_str][i] > 0)
			return arr[number_str][i];
	}
	return 0;
}
//счётчик "отмеченных" элементов вектора
int counter_size(int* vektor, int m)
{
	int count = 0;
	for (int i = 0; i < m; i++)
	{
		if (vektor[i] > 0)
			count++;
	}
	return count;
}
//заполнение вектора-ответа
void build(int** a, int* vektor, int* ans, int m)
{
	int j = 0;
	for (int i = 0; i < m && j<counter_size(vektor,m); i++)
	{
		if (vektor[i]>0)
		{
			ans[j] = find_firs_positiv(a, i, m);
			j++;
		}
	}
}