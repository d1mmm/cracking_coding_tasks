/*
* Реализуйте алгоритм, определяющий, все ли символы в строке встречаются
только один раз. А если при этом запрещено использование дополнительных
структур данных?
*/

#include <iostream>
#include <string>

bool unique_str(const std::string& str)
{
	char letters[256] = { 0 };
	for (auto i = 0; i < str.length(); ++i)
	{
		letters[str[i]]++;
		if (letters[str[i]] > 1)
		{
			return false;
		}
	}
	return true;
}

//int main(int argc, char* argv[])
//{
//	if (argc != 2)
//	{
//		std::cerr << "Count of arguments incorrect\n";
//		return -1;
//	}
// 
//	const std::string str = argv[1];
//
//	if (!unique_str(str))
//	{
//		std::cout << "symbols " << str << " are not unique\n";
//	}
//	else
//	{
//		std::cout << "symbols " << str << " are unique\n";
//	}
//
//	return 0;
//}