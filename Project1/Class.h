#pragma once

template <typename T, typename U>
class Numbers
{
private:
	T value_1;
	U value_2;

public:
	Numbers()
	{
		this->value_1 = NULL;
		this->value_2 = NULL;
	}

	Numbers(T value_1, T value_2)
	{
		this->value_1 = value_1;
		this->value_2 = value_2;
	}

	//gets
	T getValue_1() const;
	T getValue_2() const;

	//sets
	void setValue_1(T value);
	void setValue_2(U value);

	T add();
	T subtract();

	bool save(const std::string& path) const;
	bool load(const std::string& path);
};

template<typename T, typename U>
inline void Numbers<T, U>::setValue_1(T value)
{
	this->value_1 = value;
}

template<typename T, typename U>
inline void Numbers<T, U>::setValue_2(U value)
{
	this->value_2 = value;
}

template<typename T, typename U>
inline T Numbers<T, U>::add()
{
	return this->value_1 + this->value_2;
}

template<typename T, typename U>
inline T Numbers<T, U>::subtract()
{
	return this->value_1 - this->value_2;
}

template<typename T, typename U>
inline bool Numbers<T, U>::save(const std::string& path) const
{
	FILE* pf;
	fopen_s(&pf, path.c_str(), "wb");
	if (pf)
	{
		fwrite(&this->value_1, sizeof(T), 1, pf);
		fwrite(&this->value_2, sizeof(U), 1, pf);
		fclose(pf);
		return true;
	}
	return false;
}

template<typename T, typename U>
inline bool Numbers<T, U>::load(const std::string& path)
{
	FILE* pf;
	fopen_s(&pf, path.c_str(), "rb");
	if (pf)
	{
		fread_s(&this->value_1, sizeof(T), sizeof(T), 1, pf);
		fread_s(&this->value_2, sizeof(U), sizeof(U), 1, pf);
		fclose(pf);
		return true;
	}
	return false;
}

template<typename T, typename U>
inline T Numbers<T, U>::getValue_1() const
{
	return this->value_1;
}

template<typename T, typename U>
inline T Numbers<T, U>::getValue_2() const
{
	return this->value_2;
}
