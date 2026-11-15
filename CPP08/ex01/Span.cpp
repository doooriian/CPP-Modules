#include "Span.hpp"
#include <iostream>
#include <algorithm>

Span::Span(unsigned int N)
: _maxSize(N)
{
}

Span::Span(const Span &other)
: _maxSize(other._maxSize), _vector(other._vector)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		_maxSize = other._maxSize;
		_vector = other._vector;
	}
	return (*this);
}

Span::~Span()
{
}

void	Span::addNumber(int nb)
{
	if (_vector.size() >= _maxSize)
		throw std::out_of_range("Span is full");
	_vector.push_back(nb);
}

unsigned int	Span::shortestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers in the span");

	std::vector<int>	tmp = _vector;
	std::sort(tmp.begin(), tmp.end());

	unsigned int	shortest = tmp[1] - tmp[0];

	for (std::vector<int>::const_iterator it = tmp.begin(); (it + 1) != tmp.end(); it++)
	{
		unsigned int diff = *(it + 1) - *it;
		if (diff < shortest)
			shortest = diff;
	}
	return (shortest);
}

unsigned int	Span::longestSpan() const
{
	if (_vector.size() < 2)
		throw std::logic_error("Not enough numbers in the span");
	std::vector<int>::const_iterator	lowest = std::min_element(_vector.begin(), _vector.end());
	std::vector<int>::const_iterator	highest = std::max_element(_vector.begin(), _vector.end());
	int									diff = *highest - *lowest;

	return (static_cast<unsigned int>(diff));
}
