/*
* Имеется изображение, представленное матрицей NxN; каждый пиксел представлен 4 байтами. Напишите метод для поворота изображения на 90 градусов.
У дастся ли вам выполнить эту операцию «на месте»? 
*/

#include <iostream>
#include <time.h>

int** allocate_matrix(const int& n)
{
	int** arr = new int* [n];

	for (int i = 0; i < n; ++i)
	{
		arr[i] = new int[n];
	}
	return arr;
}

void set_matrix(int** arr, const int& n)
{
	srand(time(NULL));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void print(int** arr, const int& n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

void rotation(int** arr, int** temp, const int& n)
{
	int k = n - 1;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			temp[i][j] = arr[k - j][i];
		}
	}
}

void delete_matrix(int** arr, const int& n)
{
	for (int i = 0; i < n; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

//int main(int argc, const char* argv[])
//{
//	if (argc != 2)
//	{
//		std::cerr << "Count of arguments incorrect. Your second argument should be numbers\n";
//		return -1;
//	}
//
//	const int n = std::atoi(argv[1]);
//
//	auto arr = allocate_matrix(n);
//	set_matrix(arr, n);
//	print(arr, n);
//
//	auto temp = allocate_matrix(n);
//	rotation(arr, temp, n);
//	print(temp,  n);
//
//	delete_matrix(arr, n);
//	delete_matrix(temp, n);
//
//	return 0;
//}