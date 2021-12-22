#pragma once

template<typename T>
class ElementCount
{
public:
	T element;
	int count;
};

template<typename T>
class Array
{
private:
	int size;
	T* array;

	void addElementCount(ElementCount<T>*& array, int& size, T element);

public:
	Array();

	Array(int size);

	Array(const T* array);

	void add(const T& element);

	void insert(const T& element, int index);

	ElementCount<T>* count();

	void show() const;

	int find(const T& element) const;

	void sort();

	bool save(const std::string& path) const;

	bool load(const std::string& path);
};

template<typename T>
inline void Array<T>::addElementCount(ElementCount<T>*& array, int& size, T element)
{
	ElementCount<T>* tmp = new ElementCount<T>[size + 1];
	for (int i = 0; i < size; i++)
	{
		tmp[i] = array[i];
	}
	tmp[size].element = element;
	tmp[size].count = 1;
	size++;

	if (array)
	{
		delete[] array;
	}

	array = tmp;
}

template<typename T>
inline Array<T>::Array()
{
	this->size = 0;
	this->array = new T[this->size];
}

template<typename T>
inline Array<T>::Array(int size)
{
	this->size = size;
	this->array = new T[this->size];
}

template<typename T>
inline Array<T>::Array(const T* array)
{
	if (array != nullptr)
	{
		this->size = _msize((void*)array)/ sizeof(T);
		this->array = new T[this->size];

		for (int i = 0; i < this->size; i++)
		{
			this->array[i] = array[i];
		}
	}
}

template<typename T>
inline void Array<T>::add(const T& element)
{
	T* tmp = new T[this->size + 1];
	for (int i = 0; i < this->size; i++)
	{
		tmp[i] = this->array[i];
	}
	tmp[this->size] = element;
	this->size++;
	if (this->array)
	{
		delete[] this->array;
	}

	this->array = tmp;
}

template<typename T>
inline void Array<T>::insert(const T& element, int index)
{
	if (index<0 || index>this->size)
		return;

	T* tmp = new T[this->size + 1];
	for (int i = 0; i < index; i++)
	{
		tmp[i] = this->array[i];
	}
	
	for (int i = index; i < this->size; i++)
	{
		tmp[i + 1] = this->array[i];
	}

	tmp[index] = element;

	if (this->array)
	{
		delete[] this->array;
	}

	this->size++;

	this->array = tmp;
	
}

template<typename T>
inline ElementCount<T>* Array<T>::count()
{
	int size = 0;
	ElementCount<T>* res = new ElementCount<T>[size];
	for (int i = 0; i < this->size; i++)
	{
		int f = 0;
		for (int j = 0; j < size; j++)
		{
			if (res[j].element == this->array[i])
			{
				f = 1;
				res[j].count++;
				break;
			}
		}
		if (f == 0)
		{
			addElementCount(res, size, this->array[i]);
		}
	}
	return res;
}



template<typename T>
inline void Array<T>::show() const
{
	for (int i = 0; i < this->size; i++)
	{
		std::cout << this->array[i] << "\t";
	}
	std::cout << "\n";
}

template<typename T>
inline int Array<T>::find(const T& element) const
{
	for (int i = 0; i < this->size; i++)
	{
		if (this->array[i] == element)
		{
			return i;
		}
	}
	return -1;
}

template<typename T>
inline void Array<T>::sort()
{
	for (int i = 0; i < this->size; i++)
	{
		for (int j = 0; j < this->size - 1; j++)
		{
			if (this->array[j + 1] < this->array[j])
			{
				T tmp = this->array[j + 1];
				this->array[j + 1] = this->array[j];
				this->array[j] = tmp;
			}
		}
	}
}

template<typename T>
inline bool Array<T>::save(const std::string& path) const
{
	FILE* pf;
	fopen_s(&pf, path.c_str(), "wb");
	if (pf)
	{
		fwrite(&this->size, sizeof(int), 1, pf);
		fwrite(this->array, sizeof(T), this->size, pf);
		fclose(pf);
		return true;
	}
	return false;
}

template<typename T>
inline bool Array<T>::load(const std::string& path)
{
	FILE* pf;
	fopen_s(&pf, path.c_str(), "rb");
	if (pf)
	{
		fread_s(&this->size, sizeof(int), sizeof(int), 1, pf);
		fread_s(this->array, sizeof(T) * this->size, sizeof(T), this->size, pf);
		fclose(pf);
		return true;
	}
	return false;
}
