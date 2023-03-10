/*
* Допустим, что существует метод isSubstring, проверяющий, является ли
одно слово подстрокой другого. Для двух строк sl и s2 напишите код, который проверяет, получена ли строка s2 циклическим сдвигом s1, используя
только один вызов метода isSubstring (пример: слово waterbottle получено
циклическим сдвигом erbottlewat).
*/

#include<iostream>
#include <string>

bool isSubstring(const std::string& str, const std::string& str2)
{
	if (str.length() != str2.length())
	{
		return false;
	}

	int count = 1;
	char letter = str2[0];
	
	// Count where is shift
	for (int i = 0; i < str.length(); ++i)
	{
		if (str[i] == letter)
		{
			count += i;
			break;
		}
	}
	
	int j = str2.length() - count;
	for (int i = 0; i < str.length(); ++i)
	{
		++j;
		if (str2[j] == '\0')
		{
			j = 0;
		}
		if (str[i] != str2[j])
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
//		std::cerr << "Count of arguments incorrect. Your second and third arguments should be string\n";
//		return -1;
//	}
//
//	const std::string str = argv[1];
//	const std::string str2 = argv[2];
//
//	if (!isSubstring(str, str2))
//	{
//		std::cerr << str << " is not substring with cyclic shift to the left" << str2 << std::endl;
//	}
//	else
//	{
//		std::cout << str << " is substring with cyclic shift to the left" << str2 << std::endl;
//	}
//
//	return 0;
//}