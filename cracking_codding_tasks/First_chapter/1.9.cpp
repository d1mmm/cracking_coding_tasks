/*
* Допустим, что существует метод isSubstring, проверяющий, является ли
одно слово подстрокой другого. Для двух строк s1 и s2 напишите код, который проверяет, получена ли строка s2 циклическим сдвигом s1, используя
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
	
	std::string res;

	for (int i = 0; i < str.length(); ++i)
	{
		for (int j = 0; j < str2.length(); ++j)
		{
			if (str[i] == str2[j])
			{
				res += str2[j];
				break;
			}
		}
	}
	
	if (str != res)
	{
		return false;
	}

	return true;
}

int main(int argc, const char* argv[])
{
	/*if (argc != 3)
	{
		std::cerr << "Count of arguments incorrect. Your second and third arguments should be string\n";
		return -1;
	}*/

	const std::string str = argv[1];
	const std::string str2 = argv[2];

	if (!isSubstring(str, str2))
	{
		std::cerr << str << " is not substring with cyclic shift " << str2 << std::endl;
	}
	else
	{
		std::cout << str << " is substring with cyclic shift " << str2 << std::endl;
	}

	return 0;
}