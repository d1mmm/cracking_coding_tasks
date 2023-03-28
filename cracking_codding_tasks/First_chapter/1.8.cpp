/*
* Напишите алгоритм, реализующий следующее условие: если элемент матрицы
MxN равен О, то весь столбец и вся строка обнуляются.
*/

#include <iostream>
#include <string>
#include "../my_vector.h"

int** allocate_matrix(const int& m, const int& n)
{
	int** arr = new int* [m];
	for (int i = 0; i < m; ++i)
	{
		arr[i] = new int[n];
	}
	return arr;
}

void set_matrix(int** arr, const int& m, const int& n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[i][j] = rand() % 10;
		}
	}
}

void print(int** arr, const int& m, const int& n)
{
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			std::cout << arr[i][j] << "\t";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}


void reset(int** arr, const int& m, const int& n)
{
	vector<std::pair<int, int>> vec;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (arr[i][j] == 0)
			{
				vec.push_back(std::make_pair(i,j));
			}
		}
	}

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < vec.get_size(); ++j)
		{
			arr[i][vec[j].second] = 0;
		}
	}


	for (int i = 0; i < vec.get_size(); ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			arr[vec[i].first][j] = 0;
		}
	}
}

void delete_matrix(int** arr, const int& m, const int& n)
{
	for (int i = 0; i < m; ++i)
	{
		delete[] arr[i];
	}
	delete[] arr;
}

//int main(int argc, const char* argv[])
//{
//	/*if (argc != 3)
//	{
//		std::cerr << "Count of arguments incorrect. Your second and third arguments should be numbers\n";
//		return -1;
//	}*/
//
//	const int m = std::atoi(argv[1]);
//	const int n = std::atoi(argv[2]);
//
//	auto arr = allocate_matrix(m, n);
//	set_matrix(arr, m, n);
//	print(arr, m, n);
//	reset(arr, m, n);
//	print(arr, m, n);
//	delete_matrix(arr, m, n);
//
//	return 0;
//}
