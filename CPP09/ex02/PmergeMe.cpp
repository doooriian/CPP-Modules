#include "PmergeMe.hpp"
#include <ctime>
#include <cctype>
#include <cerrno>
#include <climits>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Orthodox Canonical Form

PmergeMe::PmergeMe()
{
}

PmergeMe::PmergeMe(const PmergeMe &other)
: _deq(other._deq), _vec(other._vec)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
	if (this != &other)
	{
		this->_deq = other._deq;
		this->_vec = other._vec;
	}
	return (*this);
}

PmergeMe::~PmergeMe()
{
}

// Parsing functions

static bool	parseToken(const std::string &token, int &value)
{
	long	v;
	char	*end = 0;

	if (token.empty())
		return (false);
	for (size_t i = 0; i < token.size(); ++i)
	{
		if (!std::isdigit(static_cast<unsigned char>(token[i])))
			return (false);
	}
	errno = 0;
	v = strtol(token.c_str(), &end, 10);
	if (errno == ERANGE || end == token.c_str() || *end != '\0')
		return (false);
	if (v < 1 || v > INT_MAX)
		return (false);
	value = static_cast<int>(v);
	return (true);
}

void	PmergeMe::parse(int ac, char **av)
{
	std::string			token;

	this->_deq.clear();
	this->_vec.clear();
	for (int i = 1; i < ac; ++i)
	{
		std::istringstream	ss(av[i]);
		while (ss >> token)
		{
			int	value;
			if (!parseToken(token, value))
				throw std::runtime_error("Error: unrecognized token.");
			this->_deq.push_back(value);
			this->_vec.push_back(value);
		}
	}
	if (this->_vec.empty() || this->_deq.empty())
		throw std::runtime_error("Error: empty containers.");
}

// Print function
template<typename T>
void	PmergeMe::printContainer(const std::string &prefix, const T &container) const
{
	std::cout << prefix;
	for (size_t i = 0; i < container.size(); ++i)
	{
		std::cout << container[i];
		if (i != container.size() - 1)
		std::cout << " ";
	}
	std::cout << std::endl;
}

// Algo functions

static std::vector<int>	getJacobsthalOrderVec(int nbPendings)
{
	int	j0 = 0;
	int	j1 = 1;
	int	j2;
	int	bound = 0;
	std::vector<int>	order;

	while (order.size() < static_cast<size_t>(nbPendings))
	{
		j2 = j1 + 2 * j0;
		if (j2 > nbPendings)
			j2 = nbPendings;
		order.push_back(j2);
		j0 = j1;
		j1 = j2;
		while (j2 > bound + 1)
			order.push_back(--j2);
		bound = j1;
	}
	return (order);
}

void	PmergeMe::fordJohnsonVector(std::vector<int> &vec)
{
	if (vec.size() <= 1)
		return;
	int		straggler = -1;
	bool	straggler_flag = false;
	std::vector<int>					order;
	std::vector<int>					mains;
	std::vector< std::pair<int, int> >	pairs;

	for (size_t	i = 0; i + 1 < vec.size(); i += 2)
	{
		if (vec[i] > vec[i + 1])
			pairs.push_back(std::make_pair(vec[i], vec[i + 1]));
		else
			pairs.push_back(std::make_pair(vec[i + 1], vec[i]));
	}
	if (vec.size() % 2 != 0)
	{
		straggler = vec.back();
		straggler_flag = true;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
		mains.push_back(pairs[i].first);
	fordJohnsonVector(mains);
	vec = mains;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first == mains[0])
		{
			vec.insert(vec.begin(), pairs[i].second);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}
	order = getJacobsthalOrderVec(mains.size());
	for (size_t i = 1; i < order.size(); ++i)
	{
		size_t index = static_cast<size_t>(order[i]);
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == mains[index - 1])
			{
				std::vector<int>::iterator	bound = std::find(vec.begin(), vec.end(), pairs[j].first);
				std::vector<int>::iterator	pos = std::lower_bound(vec.begin(), bound, pairs[j].second);
				vec.insert(pos, pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	if (straggler_flag == true)
	{
		std::vector<int>::iterator	pos = std::lower_bound(vec.begin(), vec.end(), straggler);
		vec.insert(pos, straggler);
	}
}

static std::deque<int>	getJacobsthalOrderDeq(int nbPendings)
{
	int	j0 = 0;
	int	j1 = 1;
	int	j2;
	int	bound = 0;
	std::deque<int>	order;

	while (order.size() < static_cast<size_t>(nbPendings))
	{
		j2 = j1 + 2 * j0;
		if (j2 > nbPendings)
			j2 = nbPendings;
		order.push_back(j2);
		j0 = j1;
		j1 = j2;
		while (j2 > bound + 1)
			order.push_back(--j2);
		bound = j1;
	}
	return (order);
}

void	PmergeMe::fordJohnsonDeque(std::deque<int> &deq)
{
	if (deq.size() <= 1)
		return;
	int		straggler = -1;
	bool	straggler_flag = false;
	std::deque<int>						order;
	std::deque<int>						mains;
	std::deque< std::pair<int, int> >	pairs;

	for (size_t	i = 0; i + 1 < deq.size(); i += 2)
	{
		if (deq[i] > deq[i + 1])
			pairs.push_back(std::make_pair(deq[i], deq[i + 1]));
		else
			pairs.push_back(std::make_pair(deq[i + 1], deq[i]));
	}
	if (deq.size() % 2 != 0)
	{
		straggler = deq.back();
		straggler_flag = true;
	}
	for (size_t i = 0; i < pairs.size(); ++i)
		mains.push_back(pairs[i].first);
	fordJohnsonDeque(mains);
	deq = mains;
	for (size_t i = 0; i < pairs.size(); ++i)
	{
		if (pairs[i].first == mains[0])
		{
			deq.insert(deq.begin(), pairs[i].second);
			pairs.erase(pairs.begin() + i);
			break;
		}
	}
	order = getJacobsthalOrderDeq(mains.size());
	for (size_t i = 1; i < order.size(); ++i)
	{
		size_t index = static_cast<size_t>(order[i]);
		for (size_t j = 0; j < pairs.size(); ++j)
		{
			if (pairs[j].first == mains[index - 1])
			{
				std::deque<int>::iterator	bound = std::find(deq.begin(), deq.end(), pairs[j].first);
				std::deque<int>::iterator	pos = std::lower_bound(deq.begin(), bound, pairs[j].second);
				deq.insert(pos, pairs[j].second);
				pairs.erase(pairs.begin() + j);
				break;
			}
		}
	}
	if (straggler_flag == true)
	{
		std::deque<int>::iterator	pos = std::lower_bound(deq.begin(), deq.end(), straggler);
		deq.insert(pos, straggler);
	}
}

// Main process

void	PmergeMe::run()
{
	clock_t				start;
	clock_t				end;
	std::vector<int>	vec_copy = this->_vec;
	std::deque<int>		deq_copy = this->_deq;

	printContainer("Before: ", this->_vec);
	start = clock();
	fordJohnsonVector(vec_copy);
	end = clock();
	this->_timeVec = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	start= clock();
	fordJohnsonDeque(deq_copy);
	end = clock();
	this->_timeDeq = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
	printContainer("After: ", vec_copy);
	std::cout << "Time to process a range of " << vec_copy.size() << " elements with std::vector : " << this->_timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << deq_copy.size() << " elements with std::deque  : " << this->_timeDeq << " us" << std::endl;

}
