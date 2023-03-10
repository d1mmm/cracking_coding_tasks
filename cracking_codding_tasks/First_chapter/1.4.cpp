#include <iostream>
#include <string>

std::pair<bool, std::string>palindrom(const std::string& str)
{
	

	return std::make_pair(true, "");
}


//int main(int argc, const char* argv[])
//{
//	/*if (argc != 2)
//	{
//		std::cerr << "Count of arguments incorrect. Your second argument should be some text in \"\"\n";
//		return -1;
//	}*/
//
//	argv[1] = "Tact Coa";
//	const std::string str = argv[1];
//	auto res = palindrom(str);
//	
//	if (!res.first)
//	{
//		std::cout << "Base string -> " << str << " are not palindrom";
//	}
//	else
//	{
//		std::cout << "Base string -> " << str << " are palindrom -> " << res.second;
//	}
//	
//
//	return 0;
//}