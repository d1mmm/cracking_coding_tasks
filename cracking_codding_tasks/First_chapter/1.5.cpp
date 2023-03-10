/*
* Существуют три вида модифицирующих операций со строками: вставка
символа, удаление символа и замена символа. Напишите функцию, которая
проверяет, находятся ли две строки на расстоянии одной модификации (или
нуля модификаций).
Пример:
pale, ple -> true
pales, pale -> true
pale, bale -> true
pale, bake -> false 
*/

#include <string>
#include <iostream>

bool check(const std::string& str, const std::string& str2)
{
	char letters[256] = { 0 };
	int count = 0;

	for (auto i = 0; i < str.length(); ++i)
	{
		letters[str[i]]++;
	}

	for (auto i = 0; i < str2.length(); ++i)
	{
		letters[str2[i]]++;
	}
	
	for (int i = 0; i < 256; ++i)
	{
		if (letters[i] == 1)
		{
			++count;
		}
	}

	if (count > 1)
	{
		return false;
	}

	return true;
}

//int main(int argc, const char* argv[])
//{
//	if (argc != 3)
//	{
//		std::cerr << "Count of arguments incorrect. Your second argument should be some text in \"\"\n";
//		return -1;
//	}
//
//	const std::string str = argv[1];
//	const std::string str2 = argv[2];
//	
//	if (!check(str, str2))
//	{
//		std::cout << str << " Couldn`t modification into -> " << str2 << std::endl;
//	}
//	else
//	{
//		std::cout << str << " Could modification into -> " << str2 << std::endl;
//	}
//	
//
//	return 0;
//}