#pragma once


/*
* Тут нужно немного изменить стуркутуру вектор, а именно алоцировать память по другому. Тобишь в оригинальном векторе
  алоцируется память (capacity * 2). Ну то есть если у нас вектор на 10 элементов, то надо алоцировать (10*2) это даст
  нам быстродействие, что не нужно постоянно переалоцировать память.
*/

template <typename T>
class vector
{
public:
	vector() = default;
	void push_back(const T& param);
	T& operator[](const int& el);
	int get_size();
private:
	T* data;
	size_t size{};
};

template<typename T>
inline void vector<T>::push_back(const T& param)
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

template<typename T>
inline T& vector<T>::operator[](const int& el)
{
	return data[el];
}

template<typename T>
inline int vector<T>::get_size()
{
	return size;
}
