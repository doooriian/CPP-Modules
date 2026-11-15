#include "MutantStack.hpp"
#include <iostream>
#include <iomanip>
#include <list>

#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define BOLD    "\033[1m"

void	printSectionHeader(const std::string& title)
{
	std::cout << std::endl << BOLD << BLUE << "╔═══════════════════════════════════════════════════════════╗" << RESET << std::endl;
	std::cout << BOLD << BLUE << "║ " << std::setw(53) << std::left << title << "     ║" << RESET << std::endl;
	std::cout << BOLD << BLUE << "╚═══════════════════════════════════════════════════════════╝" << RESET << std::endl;
}

int	main()
{
	printSectionHeader("BASIC STACK FEATURES");
	std::cout << YELLOW;
	MutantStack<int>	ms;
	std::cout << "Size at start : " << ms.size() << std::endl;
	ms.push(5);
	ms.push(17);
	std::cout << "Top after pushing 5 and 17 : " << ms.top() << std::endl;
	std::cout << "Size : " << ms.size() << std::endl;
	ms.pop();
	std::cout << "Top after pop : " << ms.top() << std::endl;
	std::cout << "Size : " << ms.size() << std::endl;
	ms.push(3);
	ms.push(7);
	ms.push(737);
	ms.push(0);
	std::cout << "Top after pushing 3, 7, 737 and 0 : " << ms.top() << std::endl;
	std::cout << "Size : " << ms.size() << std::endl;

	printSectionHeader("ITERATION");
	std::cout << GREEN;
	MutantStack<int>::iterator	it = ms.begin();
	MutantStack<int>::iterator	ite = ms.end();
	++it;
	--it;
	for ( ; it != ite; ++it)
		std::cout << *it << std::endl;

	printSectionHeader("CONST ITERATION");
	std::cout << CYAN;
	const MutantStack<int>	cms(ms);
	MutantStack<int>::const_iterator	cit = cms.begin();
	MutantStack<int>::const_iterator	cite = cms.end();
	++cit;
	--cit;
	// *cit = 42; should not compile because of const
	for ( ; cit != cite; ++cit)
		std::cout << *cit << std::endl;

	printSectionHeader("REVERSE ITERATION");
	std::cout << YELLOW;
	MutantStack<int>::reverse_iterator	rit = ms.rbegin();
	MutantStack<int>::reverse_iterator	rite = ms.rend();
	++rit;
	--rit;
	for ( ; rit != rite; ++rit)
		std::cout << *rit << std::endl;

	printSectionHeader("COMPATIBILITY WITH STD::STACK");
	std::cout << GREEN;
	std::stack<int>	s(ms);
	std::cout << "top: " << s.top() << std::endl << "size: " << s.size() << std::endl;

	printSectionHeader("COMPATIBILITY WITH ANOTHER CONTAINER");
	std::cout << CYAN;
	MutantStack< int, std::list<int> >	ms_list;
	ms_list.push(5);
	ms_list.push(17);
	ms_list.pop();
	ms_list.push(3);
	ms_list.push(7);
	ms_list.push(737);
	ms_list.push(0);
	MutantStack< int, std::list<int> >::iterator	it_lst = ms_list.begin();
	MutantStack< int, std::list<int> >::iterator	ite_lst = ms_list.end();
	for ( ; it_lst != ite_lst; ++it_lst)
		std::cout << *it_lst << std::endl;

	printSectionHeader("DESTRUCTORS");
	return(0);
}


// int main()
// {
// 	MutantStack<int>	mstack;

// 	mstack.push(5);
// 	mstack.push(17);

// 	std::cout << mstack.top() << std::endl;

// 	mstack.pop();

// 	std::cout << mstack.size() << std::endl;

// 	mstack.push(3);
// 	mstack.push(5);
// 	mstack.push(737);
// 	//[...]
// 	mstack.push(0);

// 	MutantStack<int>::iterator it = mstack.begin();
// 	MutantStack<int>::iterator ite = mstack.end();

// 	++it;
// 	--it;
// 	while (it != ite)
// 	{
// 		std::cout << *it << std::endl;
// 		++it;
// 	}
// 	std::stack<int> s(mstack);
// 	return (0);
// }
