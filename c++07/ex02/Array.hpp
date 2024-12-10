#pragma once

#include <iostream>
#include <stdexcept>

template <typename T>
class Array
{
	public:

	Array()
	{
		_array = new T[0];
		_size = 0;
	}

	~Array() {delete[] _array;}

	Array(uint32_t n)
	{
		_array = new T[n]();
		_size = n;
	}

	Array(const Array& original)
	{
		if (this != &original)
			*this = original;
	}

	Array&	operator=(const Array& original)
	{
		if (this == &original)
			return (*this);
		this->_array = new T[original.size()];
		for (uint32_t i = 0; i < original.size(); i++)
		{
			this->_array[i] = original._array[i];
		}
		return (*this);
	}

	const T&	operator[](uint32_t index) const
	{
		if (index >= this->size())
			throw std::out_of_range("Index out of bounds");
		return(_array[index]);
	}

	T&	operator[](uint32_t index)
	{
		if (index >= this->size())
			throw std::out_of_range("Index out of bounds");
		return(_array[index]);
	}

	uint32_t	size()	const {return (_size);}

	private:
	
	T*			_array;
	uint32_t	_size;
};

template <typename T>
std::ostream&	operator<<(std::ostream& out, const Array<T>& array)
{
	for (uint32_t i = 0; i < array.size(); i++)
		out << array[i];
	return (out);
}
