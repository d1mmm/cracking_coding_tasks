/*
* Допустим, что существует метод isSubstring, проверяющий, является ли
одно слово подстрокой другого. Для двух строк s1 и s2 напишите код, который проверяет, получена ли строка s2 циклическим сдвигом s1, используя
только один вызов метода isSubstring (пример: слово waterbottle получено
циклическим сдвигом erbottlewat).
*/

#include<iostream>
#include <string>
#include <vector>

bool isSubstring(const std::string& str, const std::string& str2)
{
	if (str.length() != str2.length())
	{
		return false;
	}
	
	int j = 0;

	/*for (int i = 0; i < str2.length(); ++i)
	{
		if (str[j] == str2[i])
		{
			++j;
		}
		
		if (i == str.length() - 1)
		{
			i = -1;
		}
	}*/

	return true;
}

//int main(int argc, const char* argv[])
//{
//	/*if (argc != 3)
//	{
//		std::cerr << "Count of arguments incorrect. Your second and third arguments should be string\n";
//		return -1;
//	}*/
//
//	argv[1] = "waterbottle";
//	argv[2] = "erbottlewat";
//
//	const std::string str = argv[1];
//	const std::string str2 = argv[2];
//
//	if (!isSubstring(str, str2))
//	{
//		std::cerr << str << " is not substring with cyclic shift " << str2 << std::endl;
//	}
//	else
//	{
//		std::cout << str << " is substring with cyclic shift " << str2 << std::endl;
//	}
//
//	return 0;
//}