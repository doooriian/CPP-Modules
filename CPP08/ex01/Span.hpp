#pragma once
#include <vector>
#include <stdexcept>

class	Span
{
	public:

		Span(unsigned int N);
		Span(const Span &other);
		Span &operator=(const Span &other);
		~Span(void);

		void			addNumber(int nb);
		template<typename It>
		void			addRange(It begin, It end);
		unsigned int	shortestSpan(void) const;
		unsigned int	longestSpan(void) const;

	private:

		Span(void);
		unsigned int		_maxSize;
		std::vector<int>	_vector;
};

template<typename It>
void	Span::addRange(It begin, It end)
{
	int	rangeSize = std::distance(begin, end);

	if (rangeSize < 0)
		throw std::invalid_argument("Invalid range: end iterator precedes begin iterator");
	if ((_vector.size() + static_cast<unsigned int>(rangeSize)) > _maxSize)
		throw std::out_of_range("Range too large: it would exceed the maximum size of the Span");
	_vector.insert(_vector.end(), begin, end);
}
