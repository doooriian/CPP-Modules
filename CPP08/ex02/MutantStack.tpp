#include <iostream>

// Orthodox canonical form
template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(void)
: std::stack<T, Container>()
{
	std::cout << "MutantStack default constructor called" << std::endl;
}

template<typename T, typename Container>
MutantStack<T, Container>::MutantStack(const MutantStack<T, Container> &other)
: std::stack<T, Container>(other)
{
	std::cout << "Mutantstack copy constructor called" << std::endl;
}

template<typename T, typename Container>
MutantStack<T, Container>	&MutantStack<T, Container>::operator=(const MutantStack<T, Container> &other)
{
	std::cout << "MutantStack copy assignement operator called" << std::endl;
	if (this != &other)
		std::stack<T, Container>::operator=(other);
	return (*this);
}

template<typename T, typename Container>
MutantStack<T, Container>::~MutantStack(void)
{
	std::cout << "MutantStack default destructor called" << std::endl;
}

// Iterator related functions

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::begin()
{
	return (this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::iterator	MutantStack<T, Container>::end()
{
	return (this->c.end());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::begin() const
{
	return (this->c.begin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_iterator	MutantStack<T, Container>::end() const
{
	return (this->c.end());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rbegin()
{
	return (this->c.rbegin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::reverse_iterator	MutantStack<T, Container>::rend()
{
	return (this->c.rend());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rbegin() const
{
	return (this->c.rbegin());
}

template<typename T, typename Container>
typename MutantStack<T, Container>::const_reverse_iterator	MutantStack<T, Container>::rend() const
{
	return (this->c.rend());
}
