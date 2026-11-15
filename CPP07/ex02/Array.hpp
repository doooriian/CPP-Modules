#pragma once
#include <iostream>

template<typename T>
class	Array
{
	public:

		Array(void);
		Array(unsigned int size);
		Array(const Array<T> &other);
		Array<T>	&operator=(const Array<T> &other);
		~Array(void);

		unsigned int	size(void) const;
		T				&operator[](unsigned int index);
		const T			&operator[](unsigned int index) const;

	private:

	T				*_array;
	unsigned int	_size;
};

template<typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array);

#include "Array.tpp"
