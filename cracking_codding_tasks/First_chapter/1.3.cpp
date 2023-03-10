#include <iostream>
#include <string>

template <typename T>
class vector
{
public:
	vector() = default;
	void push_back(const T& param)
	{
		if (data == nullptr)
		{
			data = new T[1];
			*data = param;
			++size;
		}
		else
		{
			T* new_data = new T[++size];
			for (auto i = 0; i < size - 1; ++i)
			{
				new_data[i] = data[i];
			}
			new_data[size - 1] = param;

			delete[] data;
			data = new T[size];
			for (auto i = 0; i < size; ++i)
			{
				data[i] = new_data[i];
			}
			delete[] new_data;
		}
	}
	T& operator[](const int& el)
	{
		return data[el];
	}

	int get_size()
	{
		return size;
	}
private:
	T* data;
	size_t size{};
};

std::string replace(const std::string& str)
{
	std::string res = "", temp = "";
	const std::string c_str = str + '\0';
	vector<std::string> vec;
	
	for (auto i = 0; i < c_str.length(); ++i)
	{
		if (c_str[i] == ' ' || c_str[i] == '\0')
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
			temp += c_str[i];
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

