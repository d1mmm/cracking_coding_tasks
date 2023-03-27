/*
* Напишите метод, заменяющий все пробелы в строке символами '%20'. Можете
считать, что длина строки позволяет сохранить дополнительные символы,
а фактическая длина строки известна заранее. (Примечание: при реализации
метода наj ava для выполнения операции •на месте• используйте символьный
массив.) 
*/

#include <iostream>
#include <string>
#include "../my_vector.h"

std::string replace(const std::string& str)
{
	std::string res = "", temp = "";
	const std::string c_string = str + '\0';
	vector<std::string> vec;
	
	for (auto i = 0; i < c_string.length(); ++i)
	{
		if (c_string[i] == ' ' || c_string[i] == '\0')
		{
			if (temp == "")
			{
				continue;
			}
			vec.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c_string[i];
		}
	}

	for (auto i = 0; i < vec.get_size(); ++i)
	{
		if (i == vec.get_size() - 1)
		{
			res += vec[i];
		}
		else
		{
			res += vec[i] + "%20";
		}
	}

	return res;
}

//int main(int argc, const char* argv[])
//{
//	if (argc != 2)
//	{
//		std::cerr << "Count of arguments incorrect. Your second argument should be some text in \"\"\n";
//		return -1;
//	}
//
//	const std::string str = argv[1];
//	auto res = replace(str);
//
//	std::cout << "Base string -> " << str << " after replacing white space on %20 -> " << res << std::endl;
//	
//	return 0;
//}

