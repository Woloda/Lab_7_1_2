// 1 Спосіб --- "Рекурсивний"
#include <iostream>
#include <Windows.h>
#include <iomanip>

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High, int index, int index_j);
void matriz_print(int** matriz, const int line, const int column, int index, int index_j);
int matriz_sum(int** matriz, const int line, const int column, int index, int index_j, int sum);
int matriz_ymova(int** matriz, const int line, const int column, int index, int index_j, int kilk_elements);
void sort_matriz(int** matriz, const int line, const int column, int index, int max, int i_max);
void sort_matriz1(int** matriz, const int line, const int column, int index, int min, int i_min, int index1, int index2, bool ask);
void sort_matriz2(int** matriz, const int line, const int column, int index, int max, int i_max, int index1, int index2, bool ask1);

int main(void)
{
	srand((unsigned)time(NULL));

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	using std::cout;
	using std::endl;

	const int line = 8;
	const int column = 6;

	int** matriz = new int* [line];
	for (int index = 0; index < line; index++)
		matriz[index] = new int[column];

	int High = 97;
	int Low = 16;
	matriz_create(matriz, line, column, Low, High, 0, 0);
	cout << "Сформований масив: " << endl;
	cout << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << endl;

	cout << endl;
	sort_matriz(matriz, line, column, 0, matriz[0][0], 0);
	sort_matriz1(matriz, line, column, 0, matriz[0][1], 0, 0, 0, FALSE);
	sort_matriz2(matriz, line, column, 0, matriz[0][2], 0, 0, 0, FALSE);
	cout << "Модифікований масив: " << endl;
	cout << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << endl;

	cout << endl;
	int suma = matriz_sum(matriz, line, column, 0, 0, 0);
	cout << "Сума елементів матриці за вказаним критерієм: " << suma << endl;
	cout << endl;

	int kilk_elements = matriz_ymova(matriz, line, column, 0, 0, 0);
	cout << "Кількість елементів за вказаним критерієм: " << kilk_elements << endl;
	cout << endl;

	cout << "Модифікований масив: " << endl;
	cout << endl;
	matriz_print(matriz, line, column, 0, 0);
	cout << endl;

	return 0;
}

void matriz_create(int** matriz, const int line, const int column, const int Low, const int High, int index, int index_j)
{
	matriz[index][index_j] = Low + rand() % (High - Low + 1);
	if (index_j < column - 1)
		matriz_create(matriz, line, column, Low, High, index, index_j + 1);
	else
		if (index < line - 1)
			matriz_create(matriz, line, column, Low, High, index + 1, 0);
}

void matriz_print(int** matriz, const int line, const int column, int index, int index_j)
{
	using std::cout;
	using std::endl;
	cout << std::setw(4) << matriz[index][index_j];
	if (index_j < column - 1)
		matriz_print(matriz, line, column, index, index_j + 1);
	else
		if (index < line - 1)
		{
			cout << endl;
			matriz_print(matriz, line, column, index + 1, 0);
		}
}

int matriz_sum(int** matriz, const int line, const int column, int index, int index_j, int sum)
{
	if ((matriz[index][index_j] % 7 == 0) || ((index % 2 != 0) || (index_j % 2 != 0)))
		sum += matriz[index][index_j];
	else;

	if (index_j < column - 1)
		matriz_sum(matriz, line, column, index, index_j + 1, sum);
	else
		if (index < line - 1)
			matriz_sum(matriz, line, column, index + 1, 0, sum);
		else
			return sum;
}

int matriz_ymova(int** matriz, const int line, const int column, int index, int index_j, int kilk_elements)
{
	if ((matriz[index][index_j] % 7 == 0) || ((index % 2 != 0) || (index_j % 2 != 0)))
	{
		matriz[index][index_j] = 0;
		kilk_elements++;
	}
	else;
	if (index_j < column - 1)
		matriz_ymova(matriz, line, column, index, index_j + 1, kilk_elements);
	else
		if (index < line - 1)
			matriz_ymova(matriz, line, column, index + 1, 0, kilk_elements);
		else
			return kilk_elements;
}

void sort_matriz(int** matriz, const int line, const int column, int index, int max, int i_max)
{
	max = matriz[index][0];
	i_max = index;
	for (int index_j = index + 1; index_j < line; index_j++)
	{
		if (max < matriz[index_j][0])
		{
			max = matriz[index_j][0];
			i_max = index_j;
		}
	}
	for (int index_j = 0; index_j < column; index_j++)
	{
		int tmp = matriz[index][index_j];
		matriz[index][index_j] = matriz[i_max][index_j];
		matriz[i_max][index_j] = tmp;
	}

	if (index < line - 1)
		sort_matriz(matriz, line, column, index + 1, max, i_max);
	else;
}

void sort_matriz1(int** matriz, const int line, const int column, int index, int min, int i_min, int index1, int index2, bool ask)
{
	for (index1 = 0; index1 < line; index1++)
	{
		for (index2 = index1 + 1; index2 < line; index2++)
		{
			if (matriz[index1][0] == matriz[index2][0])
			{
				ask = TRUE;
				index1 = line;
				index2 = line;
			}
		}
	}
	if (ask == TRUE)
	{
		min = matriz[index][1];
		i_min = index;
		for (int index_j = index + 1; index_j < line; index_j++)
		{
			if (min > matriz[index_j][1])
			{
				min = matriz[index_j][1];
				i_min = index_j;
			}
		}
		for (int index_j = 0; index_j < column; index_j++)
		{
			int tmp = matriz[index][index_j + 1];

			matriz[index][index_j + 1] = matriz[i_min][index_j + 1];

			matriz[i_min][index_j + 1] = tmp;
		}
	}
	if (index < line - 1)
		sort_matriz1(matriz, line, column, index + 1, min, i_min, index1, index2, ask);
	else;
}
void sort_matriz2(int** matriz, const int line, const int column, int index, int max, int i_max, int index1, int index2, bool ask1)
{
	for (index1 = 0; index1 < line; index1++)
	{
		for (index2 = index1 + 1; index2 < line; index2++)
		{
			if (matriz[index1][0] == matriz[index2][1])
			{
				ask1 = TRUE;
				index1 = line;
				index2 = line;
			}
		}
	}
	if (ask1 == TRUE)
	{
		for (int index = 0; index < line; index++)
		{

			max = matriz[index][2];
			i_max = index;
			for (int index_j = index + 1; index_j < line; index_j++)
			{
				if (max < matriz[index_j][2])
				{
					max = matriz[index_j][2];
					i_max = index_j;
				}

			}
			for (int index_j = 0; index_j < column; index_j++)
			{
				int tmp = matriz[index][index_j + 2];

				matriz[index][index_j + 2] = matriz[i_max][index_j + 2];

				matriz[i_max][index_j + 2] = tmp;
			}

		}
	}
	if (index < line - 1)
		sort_matriz(matriz, line, column, index + 1, max, i_max);
	else;
}
