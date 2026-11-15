#pragma once
#include <deque>
#include <vector>
#include <string>

class	PmergeMe
{
	public:

		PmergeMe(void);
		PmergeMe(const PmergeMe &other);
		PmergeMe &operator=(const PmergeMe &other);
		~PmergeMe(void);

		void	parse(int ac, char **av);
		void	run(void);



	private:

		std::deque<int>		_deq;
		std::vector<int>	_vec;
		double				_timeVec;
		double				_timeDeq;


		template<typename T>
		void	printContainer(const std::string &prefix, const T &container) const;
		void	fordJohnsonVector(std::vector<int> &vec);
		void	fordJohnsonDeque(std::deque<int> &deq);
};
