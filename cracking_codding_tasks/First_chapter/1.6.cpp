/*
* Реализуйте метод для выполнения простейшего сжатия строк с использованием счетчика повторяющихся символов. 
Например, строка ааЬсссссааа превращается в а2Ыс5а3. Если •сжатая� строка не становится короче исходной,
* то метод возвращает исходную строку. Предполагается, что строка состоит
только из букв верхнего и нижнего регистра (a-z). 
*/

#include <iostream>
#include <string>

std::string letters_to_digits(const std::string& str)
{
	std::string res = "";
	int count = 1;
	char letter = str[0];
	for (int i = 1; i < str.length(); ++i)
	{
		if (letter == str[i])
		{
			++count;
		}
		else
		{
			res += letter + std::to_string(count);
			letter = str[i];
			count = 1;
		}
		
	}
	res += letter + std::to_string(count);

	if (res.length() == str.length())
	{
		return str;
	}

	return res;
}

//int main(int argc, const char* argv[])
//{
//	/*if (argc != 2)
//	{
//		std::cerr << "Count of arguments incorrect. Your second argument should be some text in \"\"\n";
//		return -1;
//	}*/
//	argv[1] = "aabcccaa";
//
//	const std::string str = argv[1];
//	const auto res = letters_to_digits(str);
//	
//	std::cout << "String after changing -> " << res;
//
//	return 0;
//}