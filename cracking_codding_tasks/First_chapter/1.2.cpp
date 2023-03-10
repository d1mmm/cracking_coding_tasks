/*
* Для двух строк напишите метод, определяющий, явля�тся ли одна строка
перестановкой другой.
*/

#include <iostream>
#include <string>

bool the_same_str(const std::string& str, const std::string& str2)
{
	char letters1[256] = { 0 };
	char letters2[256] = { 0 };

	if (str.length() != str2.length())
	{
		return false;
	}

	for (auto i = 0; i < str.length(); ++i)
	{
		letters1[str[i]]++;
		letters2[str2[i]]++;
	}

	for (auto i = 0; i < 256; ++i)
	{
		if (letters1[i] != letters2[i])
		{
			return false;
		}
	}

	return true;
}

//int main(int argc, const char* argv[])
//{
//	if (argc != 3)
//	{
//		std::cerr << "Count of arguments are incorrect. Your should input two arguments\n";
//		return -1;
//	}
//
//	const std::string str = argv[1];
//	const std::string str2 = argv[2];
//
//	if (!(the_same_str(str, str2)))
//	{
//		std::cout << str << " and " << str2 << " are not the same\n";
//	}
//	else
//	{
//		std::cout << str << " and " << str2 << " are the same\n";
//	}
//
//	return 0;
//}