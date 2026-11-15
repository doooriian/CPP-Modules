#include "../includes/Brain.hpp"
#include <iostream>

Brain::Brain()
{
	std::cout << "Brain default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	for (size_t i = 0; i < 100; ++i)
		this->_ideas[i] = other.getIdea(i);
	std::cout << "Brain copy constructor called" << std::endl;
}

Brain	&Brain::operator=(const Brain &other)
{
	if (this != &other)
	{
		for (size_t i = 0; i < 100; ++i)
			this->_ideas[i] = other.getIdea(i);
	}
	std::cout << "Brain copy assignment operator called" << std::endl;
	return (*this);
}

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}

const std::string	Brain::getIdea(size_t index) const
{
	if (index < 100)
		return (this->_ideas[index]);
	std::cout << index << ": Not a valid index" << std::endl;
	return (std::string());
}

void	Brain::setIdea(size_t index, const std::string &idea)
{
	if (index < 100)
		this->_ideas[index] = idea;
	else
		std::cout << index << ": Not a valid index" << std::endl;
}
