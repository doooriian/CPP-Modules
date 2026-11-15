#include <exception>

#define RESET	"\033[0m"
#define RED		"\033[31m"

template<typename T>
Array<T>::Array()
: _array(NULL), _size(0)
{
	std::cout << "Array default constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(unsigned int size)
: _size(size)
{
	if (size == 0)
		_array = NULL;
	else
		_array = new T[size]();
	std::cout << "Array constructor called" << std::endl;
}

template<typename T>
Array<T>::Array(const Array<T> &other)
: _size(other._size)
{
	if (_size == 0)
		_array = NULL;
	else
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	std::cout << "Array copy constructor called" << std::endl;
}

template<typename T>
Array<T>	&Array<T>::operator=(const Array<T> &other)
{
	std::cout << "Array assignment operator called" << std::endl;
	if (this == &other)
		return (*this);
	delete[] _array;
	_size = other._size;
	if (_size == 0)
		_array = NULL;
	else
	{
		_array = new T[_size];
		for (unsigned int i = 0; i < _size; i++)
			_array[i] = other._array[i];
	}
	return (*this);
}

template<typename T>
Array<T>::~Array()
{
	delete[] _array;
	std::cout << RED << "Default destructor called" << RESET << std::endl;
}

template<typename T>
unsigned int	Array<T>::size() const
{
	return (_size);
}

template<typename T>
T	&Array<T>::operator[](unsigned int index)
{
	if (index >= _size)
		throw (std::out_of_range("Index is out of bounds"));
	return (_array[index]);
}

template<typename T>
const T	&Array<T>::operator[](unsigned int index) const
{
	if (index >= _size)
		throw (std::out_of_range("Index is out of bounds"));
	return (_array[index]);
}

template<typename T>
std::ostream	&operator<<(std::ostream &os, const Array<T> &array)
{
	for (unsigned int i = 0; i < array.size(); i++)
		os << array[i];
	return (os);
}
